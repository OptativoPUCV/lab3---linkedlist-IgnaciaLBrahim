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
  if (list->head == NULL)
  {
    return NULL;
  }
    list->current = list->head;
    void * temp = list->head->data;
    return temp;
}

void * nextList(List * list) {
  if (list->current == NULL || list->current->next == NULL)
  {
    return NULL;
  }
  list->current = list->current->next;
  void * temp = list->current->data;
  return temp;
}

void * lastList(List * list) {
  if (list->tail == NULL)
  {
    return NULL;
  }
  list->current = list->tail;
  void * temp = list->current->data;
    return temp;
}

void * prevList(List * list) {
  if (list->current == NULL || list->current == list->head)
  {
    return NULL;
  }
  list->current = list->current->prev;
  void * temp = list->current->data;
  return temp;
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
    list->head->prev = nuevo_nodo;
    nuevo_nodo->next = list->head;
    list->head = nuevo_nodo;
    list->current = list->head;
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
  else if (list->current == list->tail)
  {
    list->tail->next = nuevo_nodo;
    nuevo_nodo->prev = list->tail;
    list->tail = nuevo_nodo;
    list->current = nuevo_nodo;
  }
  else
  {
    list->current->next = nuevo_nodo;
    nuevo_nodo->prev = list->current;
    list->current = nuevo_nodo;
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
      if (list->current == list->tail)
      {
        void * temp = list->tail->data;
        list->tail = list->tail->prev;
        list->tail->next = NULL;
        return temp;
      }
      else if (list->current == list->head)
      {
        void * temp = list->head->data;
        list->head = list->head->next;
        list->head->prev = NULL;
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