//
//  main.c
//  lab2es8
//
//  Created by Francesco Marconi on 10/29/17.
//  Copyright © 2017 Francesco Marconi. All rights reserved.
//
/*
 Scrivere un programma che prese in ingresso due parole della medesima lunghezza (la lunghezza
 massima della parola è 15), verifichi se le due parole sono una l’anagramma dell’altra.
 */

/*
 Possibile soluzione:
 si utilizzeranno 3 array: due per contenere le due parole  (parola1 e parola2) e un terzo (indici_trovati) per salvare gli indici di parola2 nei quali sono memorizzate le lettere corrispondenti a quelle di parola1. 
 un aspetto di cui tenere conto nella risoluzione di questo problema è il fatto che, se parola2 è anagramma di parola1, il numero di occorrenze di ogni lettera in parola1 dev'essere uguale al numero di lettere in parola2.
 Pwer questo, ogni volta che verrà trovata in parola2 una lettera esistente in parola1, si dovrà controllare in indici_trovati che l'indice corrispondente a quella parola non sia già presente (e quindi che la lettera non sia già stata "conteggiata").
 
0 - salvare le due parole in due array (parola1 e parola2)
1 - Se le due parole hanno dimensioni uguali:
2   - inizializzare un terzo array indici_trovati con un valore di default, superiore al range di possibili indici (>=LUNGHEZZA_MAX_PAROLA)
3   - per ogni lettera x in parola1:
4       - scorrere le lettere di parola2:
5           - se si trova x all'indice k di parola2:
6               - scorrere l'array indici_trovati per verificare se k è già presente:
7                   - se già presente, continuare con l'iterazione successiva del ciclo 4
8                   - se non è già presente, salvare l'indice k nella prima cella disponibile in indici_trovati e proseguire con il ciclo 3
9            - se non si trova x:
10                - parola2 non è anagramma di parola1
11 - se le due parole hanno dimensioni diverse:
12   - parola2 non è anagramma di parola1
13 - se il numero di indici salvati in indici_trovati è uguale alla dimensione di parola1 (e di parola2):
14    - parola1 è anagramma di parola2

 */


#include <stdio.h>
#define LUNGHEZZA_MAX_PAROLA 10
#define TRUE 1
#define FALSE 0

int main(int argc, const char * argv[]) {
    
    char parola1[LUNGHEZZA_MAX_PAROLA], parola2[LUNGHEZZA_MAX_PAROLA]; // i due array che conterranno le due parole
    int indici_trovati[LUNGHEZZA_MAX_PAROLA];  // array in cui verranno salvati gli indici delle lettere corrispondenti
    int dimensione1 = 0, dimensione2 = 0;
    int i, j, k = 0;
    int anagramma = FALSE;
    int trovata_lettera = TRUE;
    printf("\nInserire unla prima parola (lunghezza massima %d):\n", LUNGHEZZA_MAX_PAROLA);
    scanf("%s", parola1);
    i = 0;
    while(i<LUNGHEZZA_MAX_PAROLA && parola1[i]!='\0'){
        i++;
    }
    dimensione1 = i;
    printf("\nInserire unla seconda parola (lunghezza massima %d):\n", LUNGHEZZA_MAX_PAROLA);
    scanf("%s", parola2);
    i = 0;
    while(i<LUNGHEZZA_MAX_PAROLA && parola2[i]!='\0'){
        i++;
    }
    dimensione2 = i;
    
    //inizializza array indici_trovati
    for (i = 0; i<LUNGHEZZA_MAX_PAROLA; i++) {
        indici_trovati[i] = LUNGHEZZA_MAX_PAROLA; // indice "invalido" che indica che la cella dell'array non è ancora stata utilizzata
    }
    
    if(dimensione1 == dimensione2){
        for (i = 0; i < dimensione1 && trovata_lettera; i++) {
            trovata_lettera = FALSE;
            for (j = 0; j < dimensione1 && !trovata_lettera; j++) {
                if (parola1[i] == parola2[j]) {
                    for (k = 0; k < dimensione1 && !trovata_lettera; k++) {
                        if (indici_trovati[k] == j) {
                            break;
                        }else if (indici_trovati[k] == LUNGHEZZA_MAX_PAROLA){
                            indici_trovati[k] = j;
                            trovata_lettera = TRUE;
                            // se il numero di indici salvati in indici_trovati è uguale alla dimensione di parola1 (e di parola2), allora parola1 è anagramma di parola2
                            if (k == dimensione1 - 1) {
                                anagramma = TRUE;
                            }
                        }
                    }
                }
            }
        }
    }
    
    if (anagramma) {
        printf("\n %s è anagramma di %s\n", parola1, parola2);
    }
    else
        printf("\n %s NON è anagramma di %s\n", parola1, parola2);
    
}
