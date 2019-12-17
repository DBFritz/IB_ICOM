
#define LIST_EMPTY     NULL
#define LIST_CONT(lst) ((lst)->cont)
#define LIST_TAIL(lst) ((lst)->pNext)

typedef struct Node {
    int cont;
    struct Node *pNext;
} *List_t; //  List_t es sinomimo de puntero a struct Node

/** RETORNA LA CANTIDAD DE NODOS*/
int ListNumNodes(List_t lst);

/**RETORNA 1 SI e ES MIEMRO Y 0 SI NO*/
int ListIsMember(int e, List_t lst);

/**LAS LISTAS EST�N EN ORDEN DECRECIENTE, VAN DE M�S CHICO A M�S GRANDE,
AGREGA e EN LA POSICI�N CORRECTA*/
List_t ListInsert(List_t lst, int e);

/**IMPRIME LA LISTA EN PANTALLA*/
void ListPrint(List_t lst);

/** CUIDADO!! SI LA LISTA EST� VAC�A EXPLOTA TODO!!!! ELIMINA EL PRIMER ELEMENTO DE LA LISTA
 Y RETORNA SU CONTENIDO*/
int ListGetNode(List_t lst);

/**ELIMINA EL PRIMER ELEMENTO DE LA LISTA SI NO EST� VAC�A,
RETORNA 0 SI EST� VAC�A Y 1 SI NO EST� VAC�A*/
int ListDeleteNode (List_t lst);

/**DESTRUYE LA LISTA*/
void ListDestroy (List_t lst);


