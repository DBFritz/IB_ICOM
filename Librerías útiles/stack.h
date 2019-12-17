#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct Node {
    int cont;
    struct Node *pNext;
} *Stack_t;

/** Crea una pila vacía y retorna un puntero a dicha pila ¿HACE FALTA?*/
Stack_t* StackCreate(void);

/**Destruye un Stack y a su puntero */
void _destroy(Stack_t pNodo);

void StackDestroy(Stack_t* ps);

/** Agrega el elemento "e" al Stack */
void StackPush (Stack_t *ps, int e);

/** Quita el elemento de la punta del Stack, y apunta el puntero pe a él,
devuelve 0 si el stack estaba vacío, y 1 si funcionó */
int StackPop(Stack_t *ps, int *pe);

/** Devuelve 1 si está vacío, 0 si no*/
int StackIsEmpty(Stack_t pNode);

/** Esto sí hay que ponerle el formato TIPO_T bien a printf*/
void StackPrint (Stack_t pNode);