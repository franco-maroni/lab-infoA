//
//  liste_iterative.h
//  InfoA-16-17
//
//  Created by Francesco Marconi on 12/22/16.
//  Copyright © 2016 Francesco Marconi. All rights reserved.
//

#ifndef liste_iterative_h
#define liste_iterative_h

typedef struct list_node {
    int content;
    struct list_node *next;
} node;

typedef node * list;

// Inserisce l'elemento alla fine (coda) della lista e ritorna la "nuova" lista
list tailInsert(list l, int content);

// Inserisce l'elemento all'inizio (testa) della lista e ritorna la nuova lista
list headInsert(list l, int content);

// Inserisce l'elemento nella lista in ordine e ritorna la "nuova" lista
list sortInsert(list l, int content);

// Rimuove il primo elemento della lista che contiene l'elemento passato come parametro
list removeFirst(list l, int content);

// Rimuove tutti gli elementi della lista che contengono l'elemento passato come parametro
list removeAll(list l, int content);

// Ritorna 1 se content e' presente nella lista, 0 altrimenti
int find(list l, int content);

// Ritorna il numero di elementi nella lista
int size(list l);

// Rimuove tutti gli elementi dalla lista
void clearList(list l);

// Stampa la lista
void printList(list l);


#endif /* liste_iterative_h */
