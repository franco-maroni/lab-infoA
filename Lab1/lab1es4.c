//
//  lab1es4.c
//  lab-infoA
//
//  Created by Francesco Marconi on 10/28/17.
//  Copyright © 2017 Francesco Marconi. All rights reserved.
//
//  Scrivere un programma che, dato in ingresso un numero intero di massimo 4 cifre, restituisca i valori divise per migliaia, centinaia, decine ed unità (come un abaco).
//


#include <stdio.h>

int main(void) {
    int n; // numero intero richiesto in ingresso
    int dec; // potenza del 10 da utilizzare per la scomposizione
    int val; // coefficiente da utilizzare per la stampa
    
    do {
        printf("Inserire un valore intero positivo di massimo 4 cifre:\n");
        scanf("%d", &n);
    } while (n < 1 || n>9999); // verifico che la cifra
    
    // versione partendo da cifra più significativa (migliaia)
    dec = 1000;
    printf("Scomposizione partendo da cifra piu` significativa:\n");
    while (dec >= 1) {
        val = n%(dec*10)/dec; // isolo la cifra sfruttando modulo e divisione intera
        printf("%d * %d\n", val, dec);
        dec /= 10;
    }
    
    // versione equivalente partendo dalle unità (utile per la versione bonus)
    dec = 1;
    printf("Scomposizione partendo da unita`:\n");
    while (dec <= 1000) {
        val = n/dec % 10; // isolo la cifra sfruttando modulo e divisione intera
        printf("%d * %d\n", val, dec);
        dec *= 10;
    }
}



