#ifndef LIST_H
#define LIST_H
#define LIST_EMPTY	NULL
#define LIST_CONT(list)	((list)->contenido)
#define LIST_TAIL(list)	((list)->nextNode)

typedef struct LNode {
	int contenido;
	struct LNode * nextNode;
} * List_t;

/** \brief Puntero a función que define un criterio de filtrado sobre el contenido
 *      de un nodo, si el ‘valor’ debe estar contenido en la lista filtrada la
 *      función debe retornar 1, sino 0 */
typedef int (*FilterFun) (int valor, void *params);

List_t FilterList( List_t lst, FilterFun filtro, void
*params);

int ListNumNodes(List_t list);

int ListIsMember(int elemento,List_t lista);

List_t ListInsert(List_t lst, int e);

void ListPrint(List_t lst);

#endif
