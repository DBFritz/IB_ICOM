#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct Node {
    int cont;
    struct Node *pNext;
} *Stack_t;


/** Crea una pila vacía y retorna un puntero a dicha pila ¿HACE FALTA?*/
Stack_t* StackCreate(void)
{
    Stack_t *ps=(Stack_t*)malloc(sizeof(Stack_t));
    assert(ps);
    *ps=NULL;
    return ps;
}

/**Destruye un Stack y a su puntero */
void _destroy(Stack_t pNodo)
{
    if (pNodo==NULL)
        return;
    _destroy(pNodo->pNext);
    free(pNodo);
    return;
}

void StackDestroy(Stack_t* ps)
{
    _destroy(*ps);
    free(ps);
    return;
}

/** Agrega el elemento "e" al Stack */
void StackPush (Stack_t *ps, int e)
{
    Stack_t pNewNode=(struct Node*)malloc(sizeof(struct Node));
    pNewNode->pNext=*ps;
    pNewNode->cont=e;
    *ps=pNewNode;
}

/** Quita el elemento de la punta del Stack, y apunta el puntero pe a él,
devuelve 0 si el stack estaba vacío, y 1 si funcionó */
int StackPop(Stack_t *ps, int *pe)
{
    if (*ps==NULL)
        return 0;
    Stack_t pTemp=*ps;
    *pe=(*ps)->cont;
    *ps=pTemp->pNext;
    free(pTemp);
    return 1;
}

/** Devuelve 1 si está vacío, 0 si no*/
int StackIsEmpty(Stack_t pNode)
{
    return(!pNode);
}

/** Esto sí hay que ponerle el formato TIPO_T bien a printf*/
void StackPrint (Stack_t pNode)
{
    if (pNode==NULL)
        return;
    printf("%d ",(pNode->cont));
    StackPrint(pNode->pNext);
    return;
}
