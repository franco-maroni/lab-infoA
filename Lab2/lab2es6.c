//
//  lab2es6.c
//  lab-infoA
//
//  Created by Francesco Marconi on 10/28/17.
//  Copyright © 2017 Francesco Marconi. All rights reserved.
//
/*
 Scrivere un programma che riceve in ingresso due vettori di interi, ciascuno di 10 elementi. Supponendo che i due vettori siano inseriti già ordinati in modo crescente, il programma deve creare e stampare un terzo vettore che rappresenti la “fusione” dei due vettori acquisiti, ovvero che contenga tutti i 20 elementi ordinati tra loro in modo crescente.
 Esempio:
 se il primo vettore contiene gli elementi
 1 3 9 18 19 23 25 29 33 37
 e il secondo vettore contiene gli elementi
 3 5 11 13 17 22 23 24 31 35
 Il programma crea e stampa un vettore contenente i seguenti elementi: 1 3 3 5 9 11 13 17 18 19 22 23 23 24 25 29 31 33 35 37
 */
#include <stdio.h>
#define DIM_VETTORE 5

int main(){
    
    int v1[DIM_VETTORE], v2[DIM_VETTORE], v_fusione[DIM_VETTORE*2];
    int i,j,k;
    printf("\nVettore 1 (i valori devono essere ordinati):\n");
    i = 0;
    while (i < DIM_VETTORE){
        printf("Inserisci valore numero %d\n", i+1);
        scanf("%d", &v1[i]);
        // proseguo solo se il valore è superiore a quello precedente
        if (i == 0 || (i > 0 && v1[i] > v1[i-1])) {
            i++;
        }
    }
    for (i = 0; i < DIM_VETTORE; i++) {
        printf("%d\t", v1[i]);
    }

    printf("\nVettore 2 (i valori devono essere ordinati):\n");
    i = 0;
    while (i < DIM_VETTORE){
        printf("Inserisci valore numero %d\n", i+1);
        scanf("%d", &v2[i]);
        // proseguo solo se il valore è superiore a quello precedente
        if (i == 0 || (i > 0 && v1[i] > v1[i-1])) {
            i++;
        }
    }
    
    for (i = 0; i < DIM_VETTORE; i++) {
        printf("%d\t", v2[i]);
    }
    
    i = 0;
    j = 0;
    k = 0;
    while (i < DIM_VETTORE || j < DIM_VETTORE) {
        if (v1[i] < v2[j]) {
            v_fusione[k] = v1[i];
            i++;
        }else{
            v_fusione[k] = v2[j];
            j++;
        }
        k++;
    }
    printf("\nVettore Fusione:\n");
    for (i = 0; i < DIM_VETTORE*2; i++) {
        printf("%d\t", v_fusione[i]);
    }
}
