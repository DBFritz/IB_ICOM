#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "list.h"


int StackPush(Stack_t *ps, int e)
{
    Stack_t newElement = (Stack_t)malloc(sizeof(struct SNode));
    if (newElement == NULL) return 0;
    newElement->value = e;
    if (StackIsEmpty(ps))
        newElement->next = NULL;
    else
        newElement->next = (*ps)->next;
    *ps=newElement;
    return 1;
}

int StackPop(Stack_t *ps, int *pe)
{
    if (StackIsEmpty(ps)) return 0;
    *pe = (*ps)->value;
    Stack_t *aux = &(*ps)->next;
//    free(*ps);
    ps = aux;
    return 1;
}

int StackIsEmpty(Stack_t *ps)
{
    return (ps==NULL);
}


int StackFilter(Stack_t *pStk, int e)
{
    if (StackIsEmpty(pStk)) return 0;
    int lectura;
    StackPop(pStk, &lectura);
    StackFilter(pStk, e);
    if (lectura!=e) StackPush(pStk, lectura);
    return 1;
}

/*
int StackFilter_nonRecursive(Stack_t *pStk, int e)
{
    int lectura;
    Stack_t * aux = StackCreate(pStk->top);
    if (aux == NULL) return 0;
    while (!StackIsEmpty(pStk))
    {
        StackPop(pStk, &lectura);
        if (lectura!=e)
        {
            StackPush(aux,lectura);
        }
    }
    while(!StackIsEmpty(aux))
    {
        StackPop(aux, &lectura);
        StackPush(pStk,lectura);
    }
    StackDestroy(aux);
    return 1;
} */
