//
//  main.c
//  lab2es7
//
//  Created by Francesco Marconi on 10/29/17.
//  Copyright © 2017 Francesco Marconi. All rights reserved.
//

#include <stdio.h>
#define LUNGHEZZA_MAX_PAROLA 10
#define TRUE 1
#define FALSE 0

int main(int argc, const char * argv[]) {
    
    char parola[LUNGHEZZA_MAX_PAROLA];
    int dimensione = 0;
    int i, j;
    int palindroma = 1;
    printf("\nInserire una parola (lunghezza massima %d):\n", LUNGHEZZA_MAX_PAROLA);
    scanf("%s", parola);
    
    i = 0;
    while(i<LUNGHEZZA_MAX_PAROLA && parola[i]!='\0'){
        i++;
    }
    dimensione = i; // salva lunghezza parola
    
    for (i=0, j=dimensione - 1 ; i < j && palindroma; i++, j--) {
        if (parola[i] != parola[j]) {
            palindroma = FALSE;
        }
    }
    if (palindroma) {
        printf("\nla parola è palindroma!\n");
    }else
        printf("\nla parola NON è palindroma!\n");
    
    
    return 0;
}
