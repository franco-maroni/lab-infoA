//
//  main.c
//  lab4es4
//
//  Created by Francesco Marconi on 12/12/16.
//  Copyright © 2016 Francesco Marconi. All rights reserved.
//

#include <stdio.h>
#define ARR_SIZE 4
void somma_array_rec_back(int x[], int y[], int z[], int n);
void somma_array_rec(int x[], int y[], int z[], int i);
void somma_array_iter(int x[], int y[], int z[]);
void riempi_array(int *arr, int size);
void print_array(int a[], int size);
int main(int argc, const char * argv[]) {
    int a[ARR_SIZE]; //= {1, 2, 3, 4};
    int b[ARR_SIZE]; // = {1, 2, 3, 4};
    int c[ARR_SIZE] = {0, 0, 0, 0};
    // inserimento valori
    riempi_array(a, ARR_SIZE);
    riempi_array(b, ARR_SIZE);
    // stampa array
    print_array(a, ARR_SIZE);
    print_array(b, ARR_SIZE);
    somma_array_rec(a, b, c, 0);
//    somma_array_iter(a, b, c);
//    somma_array_rec_back(a, b, c, ARR_SIZE);
    print_array(c, ARR_SIZE);
    
    return 0;
}


void somma_array_iter(int x[], int y[], int z[]){
    for (int i =0; i<ARR_SIZE; i++) {
        z[i] = x[i] + y[ARR_SIZE - i - 1];
    }
}


void somma_array_rec(int *x, int *y, int *z, int i){
    if(i >= ARR_SIZE) return;
    else {
        z[i] = x[i] + y[ARR_SIZE - i - 1];
        return somma_array_rec(x, y, z, i + 1);
    }
}


void somma_array_rec_back(int *x, int *y, int *z, int i){
    if(i < 0) return;
    else {
        z[i - 1] = x[i - 1] + y[ARR_SIZE - i];
        print_array(z, ARR_SIZE);
        return somma_array_rec_back(x, y, z, i - 1);
    }
}

void riempi_array(int *arr, int size){
    int numeri_inseriti = 0;
    do {
        printf("Inserire valore numero %d\n", numeri_inseriti + 1);
        scanf("%d", arr + numeri_inseriti); // in alternativa, potrei scrivere &arr[numeri_inseriti]
        numeri_inseriti++;
    } while (numeri_inseriti < size);
    
}

void print_array(int a[], int size){
    int j;
    printf("\n[ ");
    for (j=0; j<size; j++) {
        printf("%d ", a[j]);
    }
    printf("]\n");
}
