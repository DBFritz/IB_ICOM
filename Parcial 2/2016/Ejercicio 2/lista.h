#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED
#include <stdlib.h>

typedef struct Node {
    int cont;
    struct Node * pNext;
} *List_t;

#define LIST_EMPTY NULL
#define LIST_CONT(lst) ((lst)->cont)
#define LIST_TAIL(lst) ((lst)->pNext)

int ListNumNodes(List_t lst);
List_t ListNodeCreate(int e, List_t tail);
void ListPrint(List_t lst);
void ListDestroy(List_t lst);
#endif // LISTA_H_INCLUDED
