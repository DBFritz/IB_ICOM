#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int ListNumNodes(List_t list)
{
	int nn = 0;
	while( list != LIST_EMPTY ) {
	++nn;
	list = LIST_TAIL(list);
	}
	return nn;
}

int ListIsMember(int elemento, List_t list)
{
	while( list != LIST_EMPTY ) {
		if(LIST_CONT(list) == elemento)
		return 1;
		list = LIST_TAIL(list);
	}
	return 0;
}

static List_t __ListNodeCreate(int e, List_t tail)
{
    List_t newL = (List_t ) malloc(sizeof(struct LNode));
    if (newL == NULL) return NULL;
    LIST_CONT(newL) = e;
    LIST_TAIL(newL) = tail;
    return newL;
}

List_t ListInsert(List_t lst, int e)
{
    if(lst == LIST_EMPTY|| e <= LIST_CONT(lst) )
    return __ListNodeCreate(e, lst);
    LIST_TAIL(lst) = ListInsert(LIST_TAIL(lst), e);
    return lst;
}

void ListPrint(List_t lst)
{
    while(lst) {
        printf("%d ", LIST_CONT(lst));
        lst = LIST_TAIL(lst); // lst = lst->pNext
    }
    puts("");
}

List_t FilterList( List_t lst, FilterFun filtro, void
*params)
{
    List_t newList = LIST_EMPTY;

    while (lst)
    {
        if (filtro(LIST_CONT(lst),params))
        {
            newList = ListInsert(newList, LIST_CONT(lst));
        }
        lst = LIST_TAIL(lst);
    }

    return newList;
}
