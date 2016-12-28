/*
 
 Partendo dal file liste_terative.c o liste_ricorsive.c si scriva una funzione che ricevute due liste di interi calcola la media degli elementi comuni tra le due liste.
 Si tenga conto di eventuali ripetizioni.
 E.g.   L1: 1 2 3 1 5 3 8
        L2: 9 1 1 1 4 3 7
        ELEMENTI COMUNI: 1 3 1
        MEDIA: 1.66666
 */
#include <stdio.h>
#include <stdlib.h>

#include "liste_ricorsive.h"

list popola_lista(list l);

float mediaListaIter(list l);

float mediaListaRic(list l, int somma_tot, int n);

list copiaLista(list l);

int main(int argc, const char * argv[]) {

    list l1 = NULL, l2 = NULL, l3 = NULL, l2backup = NULL;
  
    
    printf("LISTA 1:\n");
    l1 = popola_lista(l1);
    
    printf("LISTA 2:\n");
    l2 = popola_lista(l2);
    
    printf("LISTA 1:\n");
    printList(l1);
    printf("LISTA 2:\n");
    printList(l2);
    
    list tmp = NULL;
    tmp = l1;
    /* dato che nella costruzione di l3 verranno rimossi mano a mano gli elementi di l1 presenti in l2,
     mi salvo la lista l2 completa nel caso dovessero servirmi tutti gli elementi dopo la costruzione di l3 */
    l2backup = copiaLista(l2);
    
    /* inserisco tutti gli elementi di l1 contenuti in l2, con eventuali ripetizioni */
    while (tmp != NULL) {
        if(find(l2, tmp->content)){
            // se trovo l'elemento, lo rimuovo da l2 così da tener conto delle ripetizioni
            l2 = removeFirst(l2, tmp->content);
            l3 = tailInsert(l3, tmp->content);
        }
        tmp = tmp->next;
    }
    printf("ELEMENTI COMUNI:\n");
    printList(l3);

    printf("MEDIA (ricorsiva): %f\n", mediaListaRic(l3, 0, 0));
    printf("MEDIA (iterativa): %f\n", mediaListaIter(l3));
    
    return 0;
}

list popola_lista(list l){
    int num;
    do {
        printf("Inserire un intero positivo da aggiungere. -1 per terminare.\n");
        scanf("%d", &num);
        if (num >= 0)
            l = tailInsert(l, num);
    } while (num != -1);
    return l;
}


float mediaListaIter(list l){
    float media = 0;
    int num_elems=0, total=0;
    list tmp = l;
    while (tmp != NULL) {
        total += tmp->content;
        num_elems++;
        tmp = tmp->next;
    }
    if (num_elems > 0) {
        media = (float)total/num_elems;
    }
    return media;
}
/* l corrisponde al puntatore all'elemento corrente, mentre n indica il numero di nodi finora "esplorati" */
float mediaListaRic(list l, int somma_tot, int n){
    if (l != NULL) {
        return mediaListaRic(l->next, somma_tot + l->content, ++n);
    }
    if (n > 0) {
        return (float)somma_tot/n;
    }else
        return 0;
}


list copiaLista(list l) {
    node *n;
    if (l == NULL)
        return l;
    else {
        n = (node *) malloc(sizeof(node));
        n->content = l->content;
        n->next = copiaLista(l->next);
        return n;
    }
}
