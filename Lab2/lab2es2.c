
/*
 LAB 2 - 2ES.2
 Scrivere il programma “Gioco dell’impiccato”.
 Richiede al primo utente di inserire una parola lunga 5 lettere e la salvi in un array.
 Richiede al secondo utente l’inserimento una lettera alla volta con lo scopo di indovinare la parola inserita dal primo utente.
  
 Il programma deve contare il numero di errori. E visualizzare le lettere indovinate nella posizione corretta.
  
 Il secondo utente vince se indovina la parola con meno di 5 errori.
  
 Riportare a video HAI VINTO – HAI PERSO ed il numero di errori commesso.

 */

#include <stdio.h>

#define SIZE 5
#define MAX_ERRORI 5

int main(void) {
    
    char parola1[SIZE + 1];
    //inizializzo soluzione utente 2
    char parola2[SIZE + 1] = {'_', '_', '_', '_', '_'};
    char c;
    
    int i, errori, lettere_indovinate = 0;
    int trovato; // variabile sentinella per verificare se il carattere è stato trovato
    
    printf("Utente1, inserisci la parola di %d lettere: ", SIZE);

    scanf("%s%*c", parola1);
    
    printf("La parola da indovinare è: %s \n", parola1);
    
    /* Ciclo finché non supero il numero massimo di errori o non indovino tutte le lettere */
    while ((errori < MAX_ERRORI) && (lettere_indovinate < SIZE))
    {
        /* Stampa stato gioco impiccato */
        switch (errori)
        {
            case 0:
                printf("  +---+  \n  |   |\n      |\n      |\n      |\n      |\n=========\n");
                break;
            case 1:
                printf("  +---+  \n  |   |\n  0   |\n  |   |\n      |\n      |\n=========\n");
                break;
            case 2:
                printf("  +---+  \n  |   |\n  0   |\n /|   |\n      |\n      |\n=========\n");
                break;
            case 3:
                printf("  +---+  \n  |   |\n  0   |\n /|\\  |\n /    |\n      |\n=========\n");
                break;
            case 4:
                printf("  +---+  \n  |   |\n  0   |\n /|\\  |\n / \\  |\n      |\n=========\n");
                break;
        }
  
        printf("Stato soluzione: %s\n", parola2);
        printf("Numero errori: %d\n", errori);
        
        printf("Utente2, inserisci un carattere:\n");
        scanf("%c%*c",&c);
        trovato = 0; //  il carattere non è ancora stato trovato
        for (i=0; i < SIZE; i++) {
            // se c è uguale al carattere corrente di utente1 e non è già stato trovato in precedenzain utente2
            if (c == parola1[i] && c != parola2[i]) {
                printf("Carattere '%c' trovato in posizione %d!\n", c, i);
                parola2[i] = c;
                trovato = 1;
                lettere_indovinate++;
            }
        }
        /* Se alla fine dell'iterazione il carattere non è stato trovato */
        if (!trovato){ // equivalente a trovato == 0
            printf("Errore! Carattere '%c' non tovato o già indovinato\n", c);
            errori++;
        }
    }
    
    printf("La soluzione di Utente2 è: %s\n", parola2);
    if (lettere_indovinate == SIZE)
        printf("HAI VINTO con %d errori\n", errori);
    else
        printf("HAI PERSO\n");
    return 0;
}
