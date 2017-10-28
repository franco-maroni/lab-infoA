//
//  main.c
//  Es3
//
//  Created by Paolo Perego on 06/11/16.
//  Copyright © 2016 Paolo Perego. All rights reserved.
//

#include <stdio.h>

int main(int argc, char *argv[]) {
    int i;
    int seqA[5],seqB[5];
    // acquisisce seqA
    for(i = 0;i < 5;i++){
        printf("\n Inserisci il val%d della sequenza A  ",i);
        scanf("%d",&seqA[i]);
    }
    
    // acquisisce seqB
    for(i = 0;i < 5;i++){
        printf("\n Inserisci il val%d della sequenza B  ",i);
        scanf("%d",&seqB[i]);
    }
    
    //  Print delle sequenze inserite
    printf("\nSeqA : [ ");
    for(i = 0;i < 5;i++){
        printf("%d",seqA[i]);
        if(i != 4)
            printf(",");
    }
    printf(" ]");
    
    printf("\nSeqB : [ ");
    for(i = 0;i < 5;i++){
        printf("%d",seqB[i]);
        if(i != 4)
            printf(",");
    }
    printf(" ]");
    
    // stampa a video la sequenza ìinterlacciataî tra A e l'inversa di B:
    // il primo elemento di A, l'ultimo elemento di B, il secondo
    
    printf("\nSeq Interlacciata : [ ");
    for(i = 0;i < 5;i++){
        printf("%d,%d",seqA[i],seqB[4 - i]);
        if(i != 4)
            printf(",");	
    }
    printf(" ]");
    
    
    
    return 0;
}