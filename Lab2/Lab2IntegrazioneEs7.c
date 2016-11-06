//
//  main.c
//  Es7
//
//  Created by Paolo Perego on 06/11/16.
//  Copyright © 2016 Paolo Perego. All rights reserved.
//

#include <stdio.h>

int main(int argc, char *argv[]) {
    
    int ArrayA[50];
    int ArrayB[5];
    int i,j;
    int flag_check = 0;
    int flag_esiste = 0;
    
    //  inserisco una rampa in  A  da 0 a 50
    for(i = 0;i < 50;i++){
        ArrayA[i]=i;
    }
    
    //chiedo all'utente una rampa
    printf("Inserisci la sequenza da ricercare: \n");
    for(i = 0;i < 5;i++){
        scanf("%i",&ArrayB[i]);
    }
    
    //  ORDINA I DUE ARRAY prima della ricerca
    int k,l,n;
    int temp;
    printf("\n");
    n=49;
    for(l = 0; l<n-1; l++) {
        for(k = 0; k<n-1-l; k++) {
            if(ArrayA[k] > ArrayA[k+1]) {
                temp = ArrayA[k];
                ArrayA[k] = ArrayA[k+1];
                ArrayA[k+1] = temp;
            }
        }
    }
    
    printf("\n");
    n=5;
    for(l = 0; l<n-1; l++) {
        for(k = 0; k<n-1-l; k++) {
            if(ArrayB[k] > ArrayB[k+1]) {
                temp = ArrayB[k];
                ArrayB[k] = ArrayB[k+1];
                ArrayB[k+1] = temp;
            }
        }
    }
    
    
    // scorre l'array di 50 cercando se esiste in A
    // una sequenza di 5 elementi che sono esattamente gli elementi di B nello stesso ordine.
    //  flag_esiste == 1 quando trova la sequenza
    flag_esiste = 0;
    for(i = 0 ; i < 45;i++){
        flag_check = 0;
        for(j = 0 ; j <5; j++){
            if(ArrayA[i + j] != ArrayB[j]){
                flag_check = 1;
            }
        }
        if(flag_check == 0){
            flag_esiste = 1;
        }
    }
    printf("Risposta : %d",flag_esiste);
    return 0;
}


void ordina_array(int v[], int n){
    int i,k;
    int temp;
    printf("\n");
    for(i = 0; i<n-1; i++) {
        for(k = 0; k<n-1-i; k++) {
            if(v[k] > v[k+1]) {
                temp = v[k];
                v[k] = v[k+1];
                v[k+1] = temp;
            }
        }	
    }
}
