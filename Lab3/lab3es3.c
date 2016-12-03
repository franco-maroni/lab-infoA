/*
 ESERCIZIO 3
 Scrivere una funzione ricorsiva (in C) che, avendo in input un array di n interi positivi, dia in output l’elemento minimo della lista.
 */
#define ARR_SIZE 6
#include <stdio.h>

int min(int a[], int n);
void print_array(int a[], int size);

int main(int argc, const char * argv[]) {
    printf("CALCOLO ELEMENTO MINIMO\n");
    int minimo;
    int arr[ARR_SIZE];
    int numeri_inseriti = 0;
    do {
        printf("Inserire valore numero %d\n", numeri_inseriti + 1);
        scanf("%d", arr + numeri_inseriti);
        numeri_inseriti++;
    } while (numeri_inseriti < ARR_SIZE);
    
    printf("Array inserito:\n");
    print_array(arr, ARR_SIZE);
    minimo = min(arr, ARR_SIZE - 1);
    printf("L'elemento minimo dell'array è: %d\n", minimo);
}


int min(int a[], int n){
    int min_rimanente;
    if (n == 0) //caso base: un solo elemento
        return a[n];
    else{ // passo ricorsivo
        min_rimanente = min(a, n-1); 
        if (a[n] < min_rimanente)
            return a[n];
        else
            return min_rimanente;
    }
    
}

                   
void print_array(int a[], int size){
    int j;
    printf("\n[ ");
    for (j=0; j<size; j++)
            printf("%d ", a[j]);
    printf("]\n");
}
