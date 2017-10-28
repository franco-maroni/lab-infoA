//
//  lab2es2.c
//  lab-infoA
//
//  Created by Francesco Marconi on 10/28/17.
//  Copyright © 2017 Francesco Marconi. All rights reserved.
//
/*
 Nelle gare di tuffi a 5 giudici, il punteggio finale è il doppio della somma dei voti ottenuta eliminando il voto più alto ed il più basso. Il programma deve leggere in input 5 valori e calcolare in uscita il voto finale.
 Es. 2.2 Scrivere il programma utilizzando gli array.
 */


#include <stdio.h>
#define NUM_GIUDICI 5

int main(){
    
    int i;
    float max, min, totale;
    float voti[NUM_GIUDICI];
    
    // fase 1: inserimento voti
    for (i = 0; i < NUM_GIUDICI; i++) {
        printf("Inserire valore numero %d:\n", i + 1);
        scanf("%f", &voti[i]);
    }
    
    // fase 2: calcolo voto finale
    //inizializzo massimo, minimo e totale al primo voto inserito
    min = voti[0];
    max = voti[0];
    totale = voti[0];
    for(i = 1; i < NUM_GIUDICI; i++) { // itero sui valori successivi
        if (voti[i] < min) {
            min = voti[i];
        }
        if (voti[i] > max) {
            max = voti[i];
        }
        totale += voti[i];
    }
    
    printf("Il massimo è %f\n", max);
    printf("Il minimo è %f\n", min);
    printf("Il voto finale è %f\n", (totale - min - max) * 2);
    
}
