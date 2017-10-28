//
//  lab2es5.c
//  lab-infoA
//
//  Created by Francesco Marconi on 10/28/17.
//  Copyright © 2017 Francesco Marconi. All rights reserved.
//
/*
 Il Crivello di Eratostene è una tecnica per calcolare i numeri primi.
 1. Si disegna una tabella 10x10 con i numeri da 1 a 100 ordinati. I numeri possono essere
 liberi o cancellati.
 2. Inizialmente tutti i numeri sono liberi, eccetto l’1 che è cancellato (non essendo numero
 primo, per definizione)
 3. Si sceglie il primo numero libero (il 2, al primo giro) e si cancellano tutti i suoi multipli
 (4,6,8,...)
 4. Si sceglie il successivo numero libero (questa volta il 3) e si cancellano tutti i suoi multipli
 che non siano già stati cancellati (9,15,21,...)
 5. Si procede in questo modo fino alla fine della tabella +
 6. Alla fine i numeri non cancellati saranno tutti e soli i numeri primi tra 0 e 100
 Implementare il Crivello di Eratostene usando una matrice 10x10 e stampare la matrice risultante al termine dell’esecuzione in forma tabellare
 */


#include <stdio.h>

int main(){
    
    int crivello[10][10];
    int i, j, multiplo_i;
    //inizializza crivello
    for (i = 0; i<10; i++) {
        for (j = 0; j<10; j++) {
            crivello[i][j] = 10 * i + j + 1;
        }
    }
    // cancella (setta a 0) 1, numero non primo per definizione
    crivello[0][0] = 0;
    
    // a partire da 2
    for (i = 2; i < 100; i++) {
        // per ogni numero primo (!= 0)
        if(i != 0){
            // cancella tutti i suoi multipli
            for (multiplo_i = i*2; multiplo_i <= 100; multiplo_i += i) {
                crivello[multiplo_i/10][multiplo_i%10 - 1] = 0;
            }
        }
    }
    
    
    // stampa crivello
    for (int i = 0; i<10; i++) {
        for (int j = 0; j<10; j++) {
            printf("%d\t", crivello[i][j]);
        }
        printf("\n");
    }
}
