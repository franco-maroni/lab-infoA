/*
 ESERCIZIO 1 - Confronto valori
 Scrivere un programma in C che richieda in input due numeri, A e B, e produca in output le seguenti informazioni:
 1.	determini se B è un numero positivo o negativo
 2.	determini se A è un numero pari o dispari
 3.	calcoli il valore di A + B
 4.	determini quale scelta dei segni nell’espressione (±A) + (±B) porta al risultato massimo, e quale è questo valore massimo.
 */

#include <stdio.h>

int main(void){
    int a, b;
    
    printf("Inserire valore di A:\n");
    scanf("%d%*c", &a);
    
    printf("Inserire valore di B:\n");
    scanf("%d%*c", &b);
    
    printf("Valori inseriti \n A: %d , B: %d \n", a,b);

    // B positivo o negativo
    if (b >= 0) {
        printf("1. B è positivo!\n");
    }else {
        printf("1. B è negativo!\n");
    }
    
    // A pari o dispari
    if (a % 2) {
        printf("2. A è dispari\n");
    }else {
        printf("2. A è pari\n");
    }
    
    // A + B
    printf("3. A + B = %d\n", a + b);
    
    // (±A) + (±B)
    printf("4. massimo valore (±A) + (±B):\n");
    if (a >= 0) { // a positivo, controllo b
        if (b >= 0) {
            printf("(+A) + (+B) -> %d\n", a + b);
        }else { // b negativo
            printf("(+A) + (-B) -> %d\n", a - b);
        }
    }else { // a negativo, controllo b
        if (b >= 0) {
            printf("(-A) + (+B) -> %d\n", -a + b);
        }else { // b negativo
            printf("(-A) + (-B) -> %d\n", -a - b);
        }
    }
    
    // ALTERNATIVA, se non interessa sapere QUALE COMBINAZIONE fornisce il maggior risultato
    //trovo valore assoluto e sommo
    if (a < 0) {
        a = -a;
    }
    if (b < 0) {
        b = -b;
    }
    printf("4alt. massimo valore (±A) + (±B): %d\n", a + b);
    
    return 0;
}
