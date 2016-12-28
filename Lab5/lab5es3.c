/*
 
 ESERCIZIO 3
 Partendo dal file liste_iterative.c o liste_ricorsive.c, scrivere un programma che legga in input una sequenza di n numeri interi e costruisca una lista ordinate in ordine decrescente. 
 Scrivere una funzione ricorsiva che elimini dalla lista tutti gli elementi dispari.
 
 */

#include <stdio.h>
#include <stdlib.h>
#include "liste_iterative.h"

list popola_lista(list l);
list sortInsert_decr(list l, int content);
list removeOdd(list l);

int main(int argc, const char * argv[]) {
    list l = NULL;
    l = popola_lista(l);
    printf("\nLista costruita in ordine decrescente:\n");
    printList(l);
    l = removeOdd(l);
    printf("\nLista senza numeri dispari:\n");
    printList(l);
    return 0;
}

list popola_lista(list l){
    int num;
    do {
        printf("Inserire un intero positivo da aggiungere. -1 per terminare.\n");
        scanf("%d", &num);
        if (num >= 0)
            l = sortInsert_decr(l, num);
    } while (num != -1);
    return l;
}


/* mi basta modificare la funzione definita nelle librerie liste_iterative.c o liste_ricorsive.c */
list sortInsert_decr(list l, int content) {
    list currentNode = l;
    node *n = (node *) malloc(sizeof(node));
    
    // Casi in cui l'elemento deve essere inserito in prima posizione
    if (l == NULL || l->content <= content) {
        return headInsert(l, content);
    }
    
    // Caso in cui l'elemento deve essere inserito in una posizione centrale
    while (currentNode->next != NULL && currentNode->next->content > content) {
        currentNode = currentNode->next;
    }
    n->next = currentNode->next;
    n->content = content;
    currentNode->next = n;
    return l;
}

/* FUnzione ricorsiva che rimuove tutti gli elementi dispari
 OSSERVAZIONE: è molto simile alla funzione removeAll() che potete trovare in liste_ricorsive.c */
list removeOdd(list l) {
    node *n;
    if (l == NULL) {
        return l;
    } else if (l->content % 2) {
        n = removeOdd(l->next);
        free(l);
        return n;
    } else {
        l->next = removeOdd(l->next);
        return l;
    }
}

