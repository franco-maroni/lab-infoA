/*
 Scrivere un programma che richieda all'utente di riempire una matrice 3 x 3 di interi
 -	la stampi
 -	sostituisca nella matrice ogni numero dispari con il suo cubo
 -	stampi la matrice così modificata
 -	infine, calcoli e stampi la media di tutti gli elementi.
 */

#include <stdio.h>
#define N 3

void stampa_matrice_quadrata(int m[][N]);
void modifica_matrice(int m[][N]);
float media_matrice(int m[][N]);

int main (void) {
    int mat[N][N], i, j;
    float avg = 0; // NB è float
    
    // acquisizione
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            printf("Elemento in posizione (%d, %d): ", i, j);
            scanf("%d%*c", &mat[i][j]);
        }
    }
    
    // prima stampata
    printf("Matrice inserita:\n");
    stampa_matrice_quadrata(mat);

    modifica_matrice(mat);
    
    // seconda stampata
    printf("Matrice modificata:\n");
    stampa_matrice_quadrata(mat);

    avg = media_matrice(mat);
    
    // stampata della media
    printf("La media degli elementi è %f\n", avg);
    
    return 0;
}

void stampa_matrice_quadrata(int m[N][N]){
    int i, j;
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            printf("\t%d", m[i][j]);
        }
        printf("\n");
    }
}
    
    void modifica_matrice(int m[][N]){
        int i,j;
        for (i = 0; i < N; i++) {
            for (j = 0; j < N; j++) {
                if (m[i][j] % 2 != 0) {
                    // numero dispari
                    m[i][j] *= m[i][j] * m[i][j]; // calcolo il cubo
                }
            }
        }
}

float media_matrice(int m[][N]){
    int i, j, media;
    media = 0;
        for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            media += m[i][j];
        }
    }
    media /= (N * N);
    return media;

}

