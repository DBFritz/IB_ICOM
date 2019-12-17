int ListNumNodes(List_t list)
{
	int nn = 0;
	while( lst != LIST_EMPTY ) {
	++nn;
	lst = LIST_TAIL(lst);
	}
	return nn;
}

int ListIsMember(int e, List_t lst)
{
	while( lst != LIST_EMPTY ) {
		if(LIST_CONT(lst) == e)
		return 1;
		lst = LIST_TAIL(lst);
	}
	return 0;
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

void ListPrint(List_t lst)
{
while(lst) {
printf("%d ", LIST_CONT(lst));
lst = LIST_TAIL(lst); // lst = lst->pNext
}
puts("");
}