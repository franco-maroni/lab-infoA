//
//  lab1es4.c
//  lab-infoA
//
//  Created by Francesco Marconi on 10/28/17.
//  Copyright © 2017 Francesco Marconi. All rights reserved.
//
//  Scrivere un programma che, dato in ingresso un numero intero arbitrario, restituisca i valori divisi per migliaia, centinaia, decine ed unità (come un abaco).
//

#include <stdio.h>

int main(void) {
    int n; // numero intero richiesto in ingresso
    int dec; // potenza del 10 da utilizzare per la scomposizione
    int val; // coefficiente da utilizzare per la stampa

    
    do {
        printf("Inserire un valore intero positivo:\n");
        scanf("%d", &n);
    } while (n < 1); // verifico che la cifra sia positiva
    
    
    // versione 1 - Scomposizione partendo dalle unità
    dec = 1;
    printf("Scomposizione partendo da unita`:\n");
    while (dec <= n) {
        val = n/dec % 10; // isolo la cifra corrente sfruttando modulo e divisione intera
        printf("%d * %d\n", val, dec);
        dec *= 10;
    }
    
    // versione 2 - Scomposizione partendo dalla cifra più significativa
    // è necessario effettuare una iterazione iniziale per capire il numero di cifre in n
    dec = 1;
    while (dec < n/10) {
        dec *= 10;
    }
    printf("Scomposizione partendo da cifra piu` significativa:\n");
    while (dec >= 1) {
        val = n%(dec*10)/dec; // isolo la cifra corrente sfruttando modulo e divisione intera
        printf("%d * %d\n", val, dec);
        dec /= 10;
    }
    
}
