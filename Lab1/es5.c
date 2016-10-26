/*
 ESERCIZIO 5 - Calcolo del fattoriale
 Scrivere un programma che, fornito in input un intero, ne restituisca in output il fattoriale n!.
 */

#include <stdio.h>

int main(void) {

    int n, i, fact;
    do {
        printf("Inserire un valore intero positivo:\n");
        scanf("%d%*c", &n);
    } while (n < 1);

    
    for(i = 0, fact = 1; i < n - 1; i++) {
        fact *= n - i;
    }

    printf("Il fattoriale di %d è %d\n", n, fact);
    return 0;
}
