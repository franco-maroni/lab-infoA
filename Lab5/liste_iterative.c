#include <stdio.h>
#include <stdlib.h>

#include "liste_iterative.h"

list tailInsert(list l, int content) {
  list currentTail = l;
  node *n = (node *) malloc(sizeof(node));
  n->next = NULL;
  n->content = content;
    
  // Caso di lista inizialmente vuota
  if (l == NULL) {
    return n;
  }
    
  // Caso di lista non vuota
  while (currentTail->next != NULL) {
    currentTail = currentTail->next;
  }
    
  currentTail->next = n;
  return l;
}

list headInsert(list l, int content) {
  node *n = (node *) malloc(sizeof(node));
  n->next = l;
  n->content = content;
  return n;
}

list sortInsert(list l, int content) {
  list currentNode = l;
  node *n = (node *) malloc(sizeof(node));
    
  // Casi in cui l'elemento deve essere inserito in prima posizione
  if (l == NULL || l->content >= content) {
    return headInsert(l, content);
  }
    
  // Caso in cui l'elemento deve essere inserito in una posizione centrale
  while (currentNode->next != NULL && currentNode->next->content < content) {
    currentNode = currentNode->next;
  }
  n->next = currentNode->next;
  n->content = content;
  currentNode->next = n;
  return l;
}

list removeFirst(list l, int content) {
  list previousNode = NULL;
  list currentNode = l;
  list head = l;
    
  while (currentNode != NULL && currentNode->content != content) {
    previousNode = currentNode;
    currentNode = currentNode->next;
  }
    
  // Se ho trovato l'elemento ...
  if (currentNode != NULL) {
    // L'elemento era in prima posizione
    if (previousNode == NULL) {
      head = currentNode->next;
    }
    // L'elemento NON era in prima posizione
    else {
      previousNode->next = currentNode->next;
    }
    free(currentNode);
  }
    
  return head;
}

list removeAll(list l, int content) {
  list previousNode = NULL;
  list currentNode = l;
  list head = l;
    
  while (currentNode != NULL) {
    if (currentNode->content == content) {
      // L'elemento era in prima posizione
      if (previousNode == NULL) {
	head = currentNode->next;
      }
      // L'elemento NON era in prima posizione
      else {
	previousNode->next = currentNode->next;
      }
      currentNode = currentNode->next;
    } else {
      previousNode = currentNode;
      currentNode = currentNode->next;
    }
  }
    
  return head;
}

int find(list l, int content) {
  while (l != NULL) {
    if (l->content == content) {
      return 1;
    }
    l = l->next;
  }
  return 0;
}

int size(list l) {
  int count = 0;
  while (l != NULL) {
    count++;
    l = l->next;
  }
  return count;
}

void clearList(list l) {
  list temp;
  while (l != NULL) {
    temp = l;
    l = l->next;
    free(temp);
  }
}

void printList(list l) {
  while (l != NULL) {
    printf("%d", l->content);
    if (l->next != NULL)
        printf(" --> ");
    l = l->next;
  }
  printf(" --|\n");
}
