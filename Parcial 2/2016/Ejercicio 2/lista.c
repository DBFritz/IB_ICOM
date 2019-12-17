#include <assert.h>
#include <stdio.h>
#include "lista.h"

int ListNumNodes(List_t lst)
{
    if(lst == LIST_EMPTY)
        return 0;
    return 1 + ListNumNodes(LIST_TAIL(lst));
}

List_t ListNodeCreate(int e, List_t tail)
{
    List_t newL = (List_t ) malloc(sizeof(struct Node));
    assert(newL);
    LIST_CONT(newL) = e;
    LIST_TAIL(newL) = tail;
    return newL;
}

void ListPrint(List_t lst)
{
    while(lst) {
        printf("%d ",LIST_CONT(lst));
        lst = LIST_TAIL(lst); // lst = lst->pNext
    }
    puts("");
}

void ListDestroy(List_t lst)
{
    if(lst==LIST_EMPTY)
        return;
    ListDestroy(LIST_TAIL(lst));
    free(lst);
}
