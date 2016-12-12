//
//  main.c
//  lab4es3
//
//  Created by Francesco Marconi on 12/11/16.
//  Copyright © 2016 Francesco Marconi. All rights reserved.
//

#include <stdio.h>
#include <math.h>

int pow_rec(int base, int esponente);
int fact_rec(int n);
float mac_laurin_rec(float x, int n);
float mac_laurin_iter(float x, int n);

int main(int argc, const char * argv[]) {
    float x;
    int n;
    printf("Inserire il valore dell'argomento x di cui si vuole calcolare il coseno\n");
    scanf("%f", &x);
    printf("Inserire l'ordine fino a cui si vuole calcolare lo sviluppo\n");
    scanf("%d", &n);
    printf("cos(%f): %f\n mac_laurin_rec(%f) - ordine %d: %f\n", x, cosf(x), x, n, mac_laurin_rec(x, n));
    printf("cos(%f): %f\n mac_laurin_iter(%f) - ordine %d: %f\n", x, cosf(x), x, n, mac_laurin_iter(x, n));
    return 0;
}

float mac_laurin_rec(float x, int n){
    float res;
    if (n==0)
        return 1;
    else {
        res = (float)pow_rec(x, 2*n) * (float)pow_rec(-1, n) / (float)fact_rec(2*n) + (float)mac_laurin_rec(x, n-1);
        // res = powf(x, 2*n) * powf(-1, n)/ (float)fact_rec(2*n) + (float)mac_laurin_rec(x, n-1);
        printf("rec: %f\n", res);
        return res;
    }
}

float mac_laurin_iter(float x, int n){
    float res = 0.0;
    for (int i = 0; i<=n; i++) {
        res += powf(x, 2*i) * powf(-1, i) / (float) fact_rec(2*i);
        printf("iter: %f\n", res);
    }
    return res;
}



int pow_rec(int base, int esponente){
    if (esponente == 0)
        return 1;
    else return base * pow_rec(base, esponente - 1);
    
}

int fact_rec(int n){
    // caso base
    if (n==0) {
        return 1;
    }else if (n >0){ // passo generico
        return n * fact_rec(n - 1);
    }else{ // sono ammessi solo valori interi positivi
        printf("Not a Number!\n");
        return -1; // valore di errore
    }
    
}
