/*
 ESERCIZIO 1 (somma interi)
 Scrivere una funzione ricorsiva in C (e un main che la esegua) la quale, ricevuto in input un numero naturale n, restituisca la somma dei primi n numeri naturali.
 Suggerimento: pensare sempre al caso base e al passo ricorsivo per ottenere la soluzione.
 */


#include <stdio.h>
int somma(int n);

int main()
{
    int numero, risultato;
    
    do {
        printf("Inserire un intero positivo: \n");
        scanf("%d", &numero);
    } while (numero < 0);
    
    
    risultato = somma(numero);
    
    printf("la somma dei primi %d numeri naturali è: %d\n", numero, risultato);
}

int somma(int num)
{
    // caso base
    if (num == 0)
        return num;
    //passo ricorsivo
    else
        return num + somma(num-1);
}
