#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

Stack_t *StackCreate(int size)
{
    Stack_t *ns = (Stack_t *) malloc(sizeof(Stack_t));
    if(ns == NULL)
    {
        fputs("No se pudo allocar memoria, ouch", stderr);
        return NULL;
    }
    ns->pElements = (int *) malloc(size * sizeof(int));

    if (ns->pElements == NULL)
    {
        fputs("No se pudo allocar memoria", stderr);
        free(ns);
        return NULL;
    }
    ns->size = size;
    ns->top = 0;
    return ns;
}

void StackDestroy(Stack_t *ps)
{
    free(ps->pElements);
    free(ps);
}

int StackPush(Stack_t *ps, int e)
{
    if(ps->top == ps->size)
        return 0;
    ps->pElements[ps->top++] = e;
    return 1;
}

int StackPop(Stack_t *ps, int *pe)
{
    if(ps->top == 0)
        return 0;
    *pe = ps->pElements[--ps->top];
    return 1;
}

int StackIsEmpty(Stack_t *ps)
{
    return ps->top == 0;
}

int StackFilter(Stack_t *pStk, int e)
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
}
