/*
 ESERCIZIO 2
 2A) Scrivere una funzione ricorsiva in C (e un main che la esegua) che permetta di calcolare il fattoriale di un numero intero.
 2B) scrivere una funzione che, dato in input un array di interi positivi, lo modifichi sostituendo al valore di ogni elemento il proprio fattoriale. Si utilizzi la funzione precedentemente definita (“fattoriale”) per calcolare il fattoriale di ogni elemento.
 */

#include <stdio.h>
#define ARR_SIZE 5

int fact_rec(int n);
void apply_fact_array_iter(int a[], int n);
void apply_fact_array_rec(int a[], int n);
void print_array(int a[], int size);


int main(int argc, const char * argv[]) {
    /* Parte 2A */
    printf("### Parte 2A ###\n");
    int n;
    printf("Inserire il numero\n");
    scanf("%d", &n);
    int fact = fact_rec(n);
    printf("\nIl fattoriale di %d è %d!\n", n, fact);
    
    /* Parte 2B */
    printf("### Parte 2B ###\n");
    int arr[ARR_SIZE];
    int numeri_inseriti = 0;
    do {
        printf("Inserire valore numero %d\n", numeri_inseriti + 1);
        scanf("%d", arr + numeri_inseriti);
        numeri_inseriti++;
    } while (numeri_inseriti < ARR_SIZE);
    
    printf("Array inserito:\n");
    print_array(arr, ARR_SIZE);
    // fattoriale_array_iter(arr, ARR_SIZE);
    apply_fact_array_rec(arr, ARR_SIZE);
    printf("Array fattoriale:\n");
    print_array(arr, ARR_SIZE);
    
    return 0;
}

/* funzione fattoriale ricorsiva */
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

/*
 funzione che sostituisce ad ogni intero presente nell'array il proprio fattoriale
 versione ITERATIVA
 */
void apply_fact_array_iter(int a[], int n){
    int i;
    for (i=0 ; i < n; i++) {
        //        res[i] = fattoriale(a[i]);
        a[i] = fact_rec(a[i]);
    }
    return;
}

/*
 funzione che sostituisce ad ogni intero presente nell'array il proprio fattoriale
 versione RICORSIVA
 */
void apply_fact_array_rec(int a[], int n){
    if(n==0) // caso base: l'array passato ha dimensione 0 -> ritorno senza applicare modifiche
        return;
    /*
     passo induttivo: dato l'array di "dimensione" n:
     - modifico ultimo elemento (posizione n-1)
     - applico lo stesso procedimeno al sottoarray di "dimensione" n-1
     */
    else
        {
            a[n-1] = fact_rec(a[n-1]);
            return apply_fact_array_rec(a, n-1);
        }
}


void print_array(int a[], int size){
    int j;
    printf("\n[ ");
    for (j=0; j<size; j++) {
        printf("%d ", a[j]);
    }
    printf("]\n");
}




