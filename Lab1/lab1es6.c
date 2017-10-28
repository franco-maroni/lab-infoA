//
//  lab1es6.c
//  lab-infoA
//
//  Created by Francesco Marconi on 10/28/17.
//  Copyright © 2017 Francesco Marconi. All rights reserved.
/*
    ESERCIZIO 6 – Potenza
    Scrivere un programma che presi in ingresso la base e l’esponente, calcoli per mezzo di un ciclo il risultato dell’elevamento a potenza.
 
 */

#include <stdio.h>

int main(){
    
    int base, esponente;
    float risultato;
    
    printf("Inserire base:\n");
    scanf("%d", &base);
    
    printf("Inserire esponente:\n");
    scanf("%d", &esponente);
    
    risultato = 1;
    if (esponente >= 0) {
        for (int i = 1; i <= esponente; i++) {
            risultato *= base;
        }
    }else{
        for (int i = -1; i >= esponente; i--) {
            risultato /= base;
        }
        
    }
    printf("%d^%d = %f\n", base, esponente, risultato);
}


