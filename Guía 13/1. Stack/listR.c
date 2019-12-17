
int ListNumNodes(List_t list)
{
	if (list == LIST_EMPTY) return 0;
	return (1+ListNumNodes(list);
}

int ListIsMember(List_t lista, int elemento)
{
	if (lista == LIST_EMPTY) return 0;
	if (LIST_CONT(lista) == elemento) return 1;
	return (ListIsMember(LIST_TAIL(lista, int elemento)));
}

static List_t __ListNodeCreate(int e, List_t tail)
{
	List_t newL = (List_t ) malloc(sizeof(struct Node));
	assert(newL);
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
