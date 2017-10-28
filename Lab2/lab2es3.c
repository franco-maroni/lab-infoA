//
//  lab2es3.c
//  lab-infoA
//
//  Created by Francesco Marconi on 10/28/17.
//  Copyright © 2017 Francesco Marconi. All rights reserved.
//
/*
 Scrivere un programma che prenda in ingresso una sequenza di numeri interi positivi. La sequenza ha lunghezza indefinita (massimo 100). L’inserimento della sequenza termina quando viene inserito un numero negativo. Il programma stampi a video la sequenza inserita e la sequenza dei soli numeri pari ordinati in modo crescente.
 */

#include <stdio.h>
#define DIM_SEQUENZA 100

int main(){
    int sequenza[DIM_SEQUENZA];
    int i = 0;
    int valori_inseriti;
    int cur;
    int max = 0;
    int min_cur;
    int min_prec;
    
    // acquisizione valori
    do {
        printf("Inserire valore numero %d (un valore negativo termina l'inserimento)\n", i);
        scanf("%d", &cur);
        if (cur > 0) {
            sequenza[i] = cur;
        }
        i++;
    } while (cur > 0 && i < DIM_SEQUENZA);
    valori_inseriti = i; // salvo numero di valori inseriti
    
    // stampa sequenza acquisita
    printf("\nSequenza inserita:\n");
    for (i = 0; i < valori_inseriti; i++) {
        printf("%d ", sequenza[i]);
    }
    //ricerca del massimo numero pari(servirà successivamente per fermarmi nella stampa dei numeri in ordine crescente)
    for (i = 0; i < valori_inseriti; i++) {
        if (!(sequenza[i]%2) && sequenza[i] > max) {
            max = sequenza[i];
        }
    }
    printf("\nmassimo numero pari: %d", max);
    // stampa valori pari in numero crescente
    /*
     min_prec --> "minimo valore pari precedente"
     min_curr --> "minimo valore pari corrente"
     max --> "massimo valore pari nella sequenza"
     
     - inizializzo min_prec a 0
     - finché non ho stampato max:
        - inizializzo min_curr a max
        - scorro tutta la sequenza cercando il minimo valore pari superiore a min_prec e lo salvo in min_curr
        - stampo min_curr
        - salvo min_curr come min_prec da utilizzare alla prossima iterazione
     */
    
    printf("\nValori pari in ordine crescente:\n");
    min_prec = 0;
    while (min_prec < max) { // itero finchè non ho stampato tutti i numeri pari (raggiungendo il massimo)
        min_cur = max; // inizializzazione minimo corrente
        for (i = 0; i < valori_inseriti; i++) {
            // se l'i-esimo elemento di sequenza è pari, minore del minimo corrente e maggiore del minimo precedente
            if(!(sequenza[i]%2) && sequenza[i] < min_cur && sequenza[i] > min_prec)
                min_cur = sequenza[i];
        }
        // stampo il minimo corrente e lo salvo come minimo precedente per l'iterazione successiva
        printf("%d ", min_cur);
        min_prec = min_cur;
    }

}
