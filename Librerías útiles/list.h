
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

/**LAS LISTAS ESTÁN EN ORDEN DECRECIENTE, VAN DE MÁS CHICO A MÁS GRANDE,
AGREGA e EN LA POSICIÓN CORRECTA*/
List_t ListInsert(List_t lst, int e);

/**IMPRIME LA LISTA EN PANTALLA*/
void ListPrint(List_t lst);

/** CUIDADO!! SI LA LISTA ESTÁ VACÍA EXPLOTA TODO!!!! ELIMINA EL PRIMER ELEMENTO DE LA LISTA
 Y RETORNA SU CONTENIDO*/
int ListGetNode(List_t lst);

/**ELIMINA EL PRIMER ELEMENTO DE LA LISTA SI NO ESTÁ VACÍA,
RETORNA 0 SI ESTÁ VACÍA Y 1 SI NO ESTÁ VACÍA*/
int ListDeleteNode (List_t lst);

/**DESTRUYE LA LISTA*/
void ListDestroy (List_t lst);


