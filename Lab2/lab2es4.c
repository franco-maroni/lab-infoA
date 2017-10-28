//
//  lab2es4.c
//  lab-infoA
//
//  Created by Francesco Marconi on 10/28/17.
//  Copyright © 2017 Francesco Marconi. All rights reserved.
//
/*
 Scrivere un programma che legge da stdin una sequenza (di lunghezza arbitraria) di numeri interi positivi, 
 terminata da 0, e indica, alla fine della sequenza, qual è la lunghezza della massima sotto-sequenza di 
 numeri consecutivi in ordine crescente.
 */

#include <stdio.h>
#define DIM_SEQUENZA 100

int main(){
    int cur, i, sequenza[DIM_SEQUENZA], valori_inseriti;
    int lung_sseq_corr = 0; // lunghezza della sotto-sequenza crescente corrente
    int lung_sseq_max = 0; // lunghezza della sotto-sequenza crescente massima
    int reset = 1; // flag che indica se è necessario  resettare l_sseq_corr
    // acquisizione valori
    do {
        printf("Inserire valore numero %d (0 termina l'inserimento)\n", i);
        scanf("%d", &cur);
        if (cur > 0) {
            sequenza[i] = cur;
        }
        i++;
    } while (cur != 0 && i < DIM_SEQUENZA);
    valori_inseriti = i; // salvo numero di valori inseriti
    
    for (i = 0; i < valori_inseriti - 1; i++) {
        if(reset)
            lung_sseq_corr = 0;
        if (sequenza[i] < sequenza[i+1]) { // il prossimo valore è maggiore del valore corrente
            lung_sseq_corr++;
            reset = 0;
            if (lung_sseq_corr > lung_sseq_max) {
                lung_sseq_max = lung_sseq_corr;
            }
        }else{ // il prossimo valore non è maggiore del valore corrente
            reset = 1; // alla prossima iterazione lung_sseq_corr sarà azzerato
        }
    }
    printf("\nLa lunghezza della massima sottosequenza crescente è: %d\n", lung_sseq_max);
}
