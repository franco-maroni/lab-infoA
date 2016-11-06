//
//  main.c
//  Es1
//
//  Created by Paolo Perego on 06/11/16.
//  Copyright © 2016 Paolo Perego. All rights reserved.
//

#include <stdio.h>

int main(int argc, char *argv[]) {
    int i,num,X;
    int array[10];
    int somma,prodotto;
    
    // acquisisce una sequenza di 10 numeri	interi
    for(i =0;i<10;i++){
        printf("\n Inserisci il numero %d : ", i );
        scanf("%d",&num);
        array[i] = num;
    }
    
    // acquisisce l'indice X
    printf("\n Inserisci l'indice X : ");
    scanf("%d",&X);
    
    // calcola la somma dei numeri in posizioni minori di X  e il prodotto dei numeri in posizione maggiore di X
    somma = 0;
    prodotto = 1;
    for(i = 0; i< 10; i++){
        if(i < X){
            somma += array[i];
        }else{
            prodotto *= array[i];
        }
    }
    
    //stampa il risultato :
    
    printf("\nSomma    = %d",somma) ;
    printf("\nProdotto = %d",prodotto) ;
    
    
    return 0;
}
