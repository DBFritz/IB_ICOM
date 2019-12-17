#ifndef LIST_H
#define LIST_H
#define LIST_EMPTY	NULL
#define LIST_CONT(list)	((list)->contenido)
#define LIST_TAIL(list)	((list)->nextNode)

typedef struct LNode {
	int contenido;
	struct LNode * nextNode;
} * List_t;

int ListNumNodes(List_t list);

int ListIsMember(int elemento,List_t lista);

List_t ListInsert(List_t lst, int e);

void ListPrint(List_t lst);

#endif
