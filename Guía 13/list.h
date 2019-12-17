#ifndef LIST_H
#define LIST_H
#define LIST_EMPTY	NULL
#define LIST_CONT(list)	((list)->contenido)
#define LIST_TAIL(list)	((list)->nextNode)

typedef struct Node {
	int contenido;
	struct Node * nextNode;
} * List_t;

int ListNumNodes(List_t list);

int ListIsMember(List_t lista, int elemento);

static List_t __ListNodeCreate(int e, List_t tail);

List_t ListInsert(List_t lst, int e);

void ListPrint(List_t lst);

#endif