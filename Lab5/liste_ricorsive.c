#include <stdio.h>
#include <stdlib.h>
#include "liste_ricorsive.h"

list tailInsert(list l, int content) {
    node *n;
    if (l == NULL) {
        n = (node *) malloc(sizeof(node));
        n->next = NULL;
        n->content = content;
        return n;
    } else {
        l->next = tailInsert(l->next, content);
        return l;
    }
}

list headInsert(list l, int content) {
    node *n = (node *) malloc(sizeof(node));
    n->next = l;
    n->content = content;
    return n;
}

list sortInsert(list l, int content) {
    node *n;
    if (l != NULL && l->content < content) {
        l->next = sortInsert(l->next, content);
        return l;
    } else {
        n = (node *) malloc(sizeof(node));
        n->content = content;
        if (l != NULL) {
            n->next = l;
        } else {
            n->next = NULL;
        }
        return n;
    }
}

list removeFirst(list l, int content) {
    node *n;
    if (l == NULL) {
        return l;
    } else if (l->content == content) {
        n = l->next;
        free (l);
        return n;
    } else {
        l->next = removeFirst(l->next, content);
        return l;
    }
}

list removeAll(list l, int content) {
    node *n;
    if (l == NULL) {
        return l;
    } else if (l->content == content) {
        n = removeAll(l->next, content);
        free(l);
        return n;
    } else {
        l->next = removeAll(l->next, content);
        return l;
    }
}

int find(list l, int content) {
    if (l == NULL) {
        return 0;
    } else {
        return l->content == content || find(l->next, content);
    }
}

int size(list l) {
    if (l == NULL) {
        return 0;
    } else {
        return 1 + size(l->next);
    }
}

void clearList(list l) {
    node *n;
    if (l != NULL) {
        n = l->next;
        free(l);
        clearList(n);
    }
}

void printList(list l) {
    if (l != NULL) {
        printf("%d", l->content);
        if (l->next != NULL)
            printf(" --> ");
        printList(l->next);
    } else {
        printf(" --|\n");
    }
}
