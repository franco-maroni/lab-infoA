//
//  lab2es2.c
//  lab-infoA
//
//  Created by Francesco Marconi on 10/28/17.
//  Copyright © 2017 Francesco Marconi. All rights reserved.
//
/*
 Nelle gare di tuffi a 5 giudici, il punteggio finale è il doppio della somma dei voti ottenuta eliminando il voto più alto ed il più basso. Il programma deve leggere in input 5 valori e calcolare in uscita il voto finale.
 Es. 2.1 Scrivere il programma senza l’utilizzo degli array;
 */


#include <stdio.h>

#define NUM_GIUDICI 5

int main(){
    
    int i;
    float max = 0, min = 0, cur, totale = 0;
    
    for(i = 0; i < NUM_GIUDICI; i++) { // ripeto NUM_GIUDICI volte
        printf("Inserire valore numero %d:\n", i + 1);
        scanf("%f", &cur);
        if (i == 0) { //alla prima iterazione, assegno lo stesso valore a max e min
            min = cur;
            max = cur;
        } else{
            if (cur < min) {
                min = cur;
            }
            if (cur > max) {
                max = cur;
            }
        }
        totale += cur;
    }
    printf("Il massimo è %f\n", max);
    printf("Il minimo è %f\n", min);
    printf("Il voto finale è %f\n", (totale - min - max) * 2);
    
}
