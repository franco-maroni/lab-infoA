/*
 
 ESERCIZIO 4
 Scrivere una funzione ricorsiva (in C) che, avendo in input un array di 5 interi positivi, dia in output 1 se tutti gli elementi sono maggiori di m, 0 altrimenti.
 */
#include <stdio.h>

#define ARR_SIZE 5
#define TRUE 1
#define FALSE 0

int tuttiMaggiori(int a[], int n, int m);
void print_array(int a[], int size);

int main(int argc, const char * argv[]) {
    printf("TUTTI MAGGIORI DI M\n");
    int m;
    int risultato;
    int arr[ARR_SIZE];
    int numeri_inseriti = 0;
    do {
        printf("Inserire valore numero %d\n", numeri_inseriti + 1);
        scanf("%d", arr + numeri_inseriti);
        numeri_inseriti++;
    } while (numeri_inseriti < ARR_SIZE);
    
    printf("Array inserito:\n");
    print_array(arr, ARR_SIZE);
    
    printf("Inserire il valore di m:\n");
    scanf("%d", &m);
    risultato = tuttiMaggiori(arr, ARR_SIZE, m);
    risultato == TRUE ? printf("Tutti i valori sono >%d\n", m) : printf("Alcuni valori sono <=%d\n", m);
}


int tuttiMaggiori(int A[], int n, int m){
    printf("n:%d, a[%d]:%d\n", n, n - 1, m);
    if (n < 1) // caso base: array vuoto
        return TRUE;
    else if (A[n-1] <= m )
        return FALSE;
    else
        return tuttiMaggiori(A, n-1, m);
    
}


void print_array(int a[], int size){
    int j;
    printf("\n[ ");
    for (j=0; j<size; j++)
        printf("%d ", a[j]);
    printf("]\n");
}
