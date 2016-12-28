/*
    Partendo dal file liste_iterative.c o liste_ricorsive.c si scriva una funzione che ricevute due liste di interi (senza ripetizioni) restituisce una lista contenente tutti e soli gli elementi divisibili per 3 delle due liste (senza ripetizioni).

 --> In questo caso si utilizza liste_iterative.c
 */

#include <stdio.h>
#include <stdlib.h>

#include "liste_ricorsive.h"

list popola_lista(list l);
list inserisciDivisibiliPerN(list l, list listaDivisibili, int n);

int main(void) {
    
    list l1 = NULL, l2 = NULL;
    
    printf("LISTA 1:\n");
    l1 = popola_lista(l1);
    
    printf("\nLISTA 2:\n");
    l2 = popola_lista(l2);
    
    printf("LISTA 1:\n");
    printList(l1);
    printf("LISTA 2:\n");
    printList(l2);
    
    list l3 = NULL;
    
    l3 = inserisciDivisibiliPerN(l1, l3, 3);
    l3 = inserisciDivisibiliPerN(l2, l3, 3);
    
    printf("Lista degli elementi divisibili per 3:\n");
    printList(l3);
    
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

list inserisciDivisibiliPerN(list l, list listaDivisibili, int n){
    while (l != NULL) {
        if(!(l->content % n) && !find(listaDivisibili, l->content))
            listaDivisibili = tailInsert(listaDivisibili, l->content);
        l = l->next;
    }
    return listaDivisibili;
}

