//
//  lab2es1.c
//  lab-infoA
//
//  Created by Francesco Marconi on 10/28/17.
//  Copyright © 2017 Francesco Marconi. All rights reserved.
//
/*
 Es. 1
 Scrivere un programma che, dato un anno inserito dall’utente come numero intero, dica se è bisestile o meno.
 Esempio:
	Inserisci anno: 1777
	L’anno 1777 non e` bisestile!
 
 Si ricorda che, secondo il calendario gregoriano, sono bisestili:
 •	Gli anni non secolari il cui numero è divisibile per 4 (792, 1996, 2012)
 •	Gli anni secolari il cui numero è divisibile per 400 (es 1200, 1600, 2000)
 Questo significa gli anni secolari il cui numero non è divisibile per 400 (es 1900) non sono bisestili.
 */

#include <stdio.h>


int main(){
    int anno;
    printf("inserire anno:\n");
    scanf("%d", & anno);
    // (se l'anno è divisibile per 400) OR ((è divisibile per 4) AND (non è divisibile per 100))
    if(!(anno%400) || (!(anno%4) && anno%100)){
        printf("L'anno è bisestile\n");
    }else
        printf("L'anno non è bisestile\n");
}
