/*
 ESERCIZIO 7 - Conversione binario - decimale
 Scrivere un programma che converta un numero binario in un numero decimale.
 Il numero binario è rappresentato su N bit, e il valore di N è inserito da tastiera.
 L’utente inserisce le cifre del numero binario un bit alla volta, partendo dal bit meno significativo (ossia dal bit di peso 2 0 ).
 Il programma visualizzerà il numero decimale corrispondente. Suggerimento.
 Per calcolare le potenze di 2 utilizzare la funzione pow, includendo la libreria math.h. Ad esempio per calcolare 2 5 , si scriverà pow(2,5).
 In generale, data una base a, per calcolare y = a b , si scrive y = pow(a,b) includendo la libreria math.h.
 */
#include <stdio.h>
#include <math.h>
#define BASE 2
int main(void)
{
    int n ; // numero di cifre binarie
    int bit ; // cifra binaria
    int peso ; // peso della cifra binaria
    int numero ; // valore decimale del numero binario
    /* Inizializzazione variabili*/
    peso = 0 ; // prima cifra binaria avrà valore 0
    numero = 0 ; // valore decimale inizializzato a 0
    
    do {
        printf("Immetti il numero di bit del numero binario (>0): ") ;
        scanf("%d", &n) ;
    } while (n <= 0);
    
    
    printf("\nImmetti il numero binario partendo dal bit meno significativo \n") ;
    
    while ( peso < n )
    {
        do {
            printf("Immetti la cifra binaria 2^%d:", peso) ;
            scanf("%d", &bit) ;
        } while (bit != 0 && bit != 1);
        /* Calcolo valore decimale corrispondente alla cifra binaria inserita e sommo al numero*/
        numero = numero + bit * pow(BASE, peso) ;
        peso = peso + 1 ; // aggiorna peso per iterazione successiva
    }
    
    printf("\nLa cifra decimale calcolata e’: %d\n", numero) ;
    return 0;
}
