#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "list.h"

typedef struct Node Node;

struct Node {
    void * data;
    Node * next;
    Node * prev;
};

struct List {
    Node * head;
    Node * tail;
    Node * current;
};

typedef List List;

Node * createNode(void * data) {
    Node * new = (Node *)malloc(sizeof(Node));
    assert(new != NULL);
    new->data = data;
    new->prev = NULL;
    new->next = NULL;
    return new;
}

List * createList() {
  List * lista = (List *) malloc(sizeof(List));
  lista->head = NULL;
  lista->tail = NULL;
  lista->current = NULL;
  return lista;
    
}

void * firstList(List * list) {
    list->current = list->head;
    return list->head;
}

void * nextList(List * list) {
  if (list->current == NULL)
  {
    return NULL;
  }
  list->current = list->current->next;
  return list->current;
}

void * lastList(List * list) {
    return list->tail;
}

void * prevList(List * list) {
  list->current = current->prev;
  return list->current;
}

void pushFront(List * list, void * data) {
  Node * nuevo_nodo = createNode(data);
  if (list->head == NULL)
  {
    list->head = nuevo_nodo;
    list->tail = nuevo_nodo;
    list->current = nuevo_nodo;
  }
  else
  {
    nuevo_nodo->next = list->head;
    list->head->prev = nuevo_nodo;
    nuevo_nodo = list->head;
    list->current = nuevo_nodo;
  }
}

void pushBack(List * list, void * data) {
    list->current = list->tail;
    pushCurrent(list,data);
}

void pushCurrent(List * list, void * data) {
  Node * nuevo_nodo = createNode(data);
  if (list->current == NULL)
  {
    list->head = nuevo_nodo;
    list->current = list->head;
  }
  else
  {
    list->current->next = nuevo_nodo;
    nuevo_nodo->prev = list->current;
  }
}

void * popFront(List * list) {
    list->current = list->head;
    return popCurrent(list);
}

void * popBack(List * list) {
    list->current = list->tail;
    return popCurrent(list);
}

void * popCurrent(List * list) {
  if (list->current == NULL)
  {
    return NULL;
  }
  else
  {
    if (list->current == list->head)
    {
      void * temp = list->head->data;
      list->head = NULL;
      list->tail = NULL;
      list->current = NULL;
      return temp;
    }
    else
    {
      void * temp = list->current->data;
      list->current->prev->next = list->current->next;
      list->current->next->prev = list->current->prev;
      list->current = list->current->next;
      return temp;
    }
  }
}

void cleanList(List * list) {
    while (list->head != NULL) {
        popFront(list);
    }
}