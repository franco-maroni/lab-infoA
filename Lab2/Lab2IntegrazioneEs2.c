//
//  main.c
//  Es2
//
//  Created by Paolo Perego on 06/11/16.
//  Copyright © 2016 Paolo Perego. All rights reserved.
//

#include <stdio.h>

typedef struct voto {
    int voto;
    int credito;
} voto;

int main(int argc, char *argv[]) {
    
    int numero_corsi,i;
    voto voti[10];
    float num,den,media;
    
    // acquisisce il numero di voti
    printf("\n Digita il numero di corsi : ");
    scanf("%d",&numero_corsi);
    
    // acquisisce numero di crediti e voto per ogni singolo corso
    for(i = 0;i < numero_corsi;i++){
        
        printf("\n CORSO %d ",i);
        
        //  chiede il numero di crediti del corso
        printf("\n   Inserisci il n∞ crediti :");
        scanf("%d",&voti[i].credito);
        
        //  chiede il voto in 30imi
        printf("\n   Inserisci il voto       :");
        scanf("%d",&voti[i].voto);
    }
    
    // calcola la media pesata
    num = 0;
    den = 0;
    for(i = 0;i < numero_corsi;i++){
        num += voti[i].voto * voti[i].credito;
        den += voti[i].credito;
    }
    media = num / den;
    
    //  stampa il risultato 	
    printf("\n  Media Pesata  %.2f ", media);
    
    return 0;
}
