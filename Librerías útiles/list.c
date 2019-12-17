#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "FUNCIONES_LISTAS.h"

int ListNumNodes(List_t lst)
{
    if(lst == LIST_EMPTY)
        return 0;
    return 1 + ListNumNodes(LIST_TAIL(lst));
}


int ListIsMember(int e, List_t lst)
{
    if(lst == LIST_EMPTY)
        return 0;
    if(LIST_CONT(lst) == e)
        return 1;
    return ListIsMember(e, LIST_TAIL(lst));
}

static List_t ListNodeCreate(int e, List_t tail)
{
    List_t newL = (List_t ) malloc(sizeof(struct Node));
    assert(newL);
    LIST_CONT(newL) = e;
    LIST_TAIL(newL) = tail;
    return newL;
}


List_t ListInsert(List_t lst, int e)
{
    if(lst == LIST_EMPTY || e <= LIST_CONT(lst) )
        return ListNodeCreate(e, lst);
    LIST_TAIL(lst) = ListInsert(LIST_TAIL(lst), e);
    return lst;
}

void ListPrint(List_t lst)
{
    while(lst) {
        printf("%d ", LIST_CONT(lst));
        lst = LIST_TAIL(lst); //lst = lst->pNext
    }
    puts("");
}

/** CUIDADO!!! SI ESTÁ VACÍA EXPLOTA TODO*/
int ListGetNode(List_t lst)
{
    int c;
    if (lst==LIST_EMPTY)
        printf("Se intentó sacar un elemento de una lista vacía, el programa explota");
    List_t lstaux=lst;
    c=LIST_CONT(lstaux);
    lst=LIST_TAIL(lst);
    free(LIST_TAIL(lstaux));
    free(lstaux);
    return c;
}


int ListDeleteNode (List_t lst)
{
    if (lst==LIST_EMPTY)
        return 0;
    List_t lstaux=lst;
    lst=LIST_TAIL(lst);
    free(LIST_TAIL(lstaux));
    free(lstaux);
    return 1;
}


void ListDestroy (List_t lst)
{
    if (lst==LIST_EMPTY);
    free(lst);
    ListDeleteNode(lst);
    ListDestroy(lst);
}
