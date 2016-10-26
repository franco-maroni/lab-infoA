/*
 ESERCIZIO 4 - Calcolo del massimo e del minimo
 Scrivere un programma in C che, forniti in input N valori, ne determini il Massimo ed il minimo.
 Il programma deve:
 - chiedere in ingresso un valore intero corrispondente ad N
 - chiedere in ingresso gli N valori (uno alla volta)
 - stampare in output il valore massimo e minimo
 
 */

#include <stdio.h>

int main(void) {
    int n, i, max, min, cur;
    
    do {
        printf("Inserire valore di N:\n");
        scanf("%d%*c", &n);
    } while ( n < 1 );
    
    max = 0;
    min = 0;
    for(i = 0; i < n; i++) { // ripeto n volte
        printf("Inserire valore numero %d:\n", i + 1);
        scanf("%d%*c", &cur); 
        if (i == 0) { //alla prima iterazione, assegno lo stesso valore a max e min
            min = cur;
            max = cur;
        } else{
            if (cur < min) {
                min = cur;
            }
            if (cur > max) {
                max = cur;
            }
        }
    }
    printf("Il MASSIMO è %d\n", max);
    printf("Il MINIMO è %d\n", min);
    
    return 0;
}
