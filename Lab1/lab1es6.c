/*
 ESERCIZIO 6 - Fibonacci
 Scrivere un programma che chieda un intero positivo n all'utente e in risposta stampi i primi n numeri della serie di Fibonacci.
 La serie di Fibonacci è definita come segue:
 
 F(0) = 1 F(1) = 1
 F(n) = F(n-1) + F(n-2)
 
 Quindi la serie è:
 1 1 2 3 5 8 13
 */


#include <stdio.h>

int main(void) {
    int i, n;
    int f_n, f_n_1, f_n_2; // F(n), F(n-1), F(n-2)
    /* Inizializzazione variabili (caso n = 0) */
    f_n_2 = 0;
    f_n_1 = 0;
    f_n = 1;
    
    do {
        printf("Inserire intero positivo:\n");
        scanf("%d", &n);
    } while (n <= 0);
    
    for(i = 0; i < n; i++) {
        printf("%d ", f_n);
        f_n_2 = f_n_1;
        f_n_1 = f_n;
        /* Calcolo valore prossima iterazione:
         F(n) = F(n-1) + F(n-2) */
        f_n = f_n_1 + f_n_2; // --> assegnazione equivalente: f_n += f_n_2;
    }
    printf("\n");
    
    return 0;
}
