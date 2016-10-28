/*
 ESERCIZIO 3 - Numeri Primi
 Si scriva un programma in grado di decidere se un numero dato dall’utente è primo. Si ricorda che un numero è primo se non è divisibile per nessuno dei valori compresi tra il numero stesso e 1.

 */

#include <stdio.h>

int main(void) {
    int n, i;
    int primo; // flag che utilizzo per determinare se numero è primo
    
    do {
        printf("Inserire un valore intero positivo:\n");
        scanf("%d", &n);
    } while (n < 1);
    
    i = 2; // il primo confronto
    primo = 1; // se alla fine dell'iterazione primo avrà ancora valore 1, allora il numero è primo
    
    while (primo && i <= n / 2) { // mi basta arrivare fino a n/2
        primo = n % i; // se la divisione intera non dà resto -> primo = 0 -> esco dal ciclo e concludo che il numero non è primo
    }
    
    /*
     VERSIONE COMPATTA EQUIVALENTE
    for(i = 2, primo = 1; primo && i <= n / 2; i++) {
        primo = n % i;
    }
    */
    
    if(!primo) {
        printf("Il numero NON è primo\n");
    } else {
        printf("Il numero è primo\n");
    }
    
    return 0;
}
