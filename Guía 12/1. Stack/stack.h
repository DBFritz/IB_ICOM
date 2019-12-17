#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED


typedef struct {
    int top;
    int size;
    int *pElements;
} Stack_t;

/** \brief Crea un Stack
 *
 * \param int size: El tamaño máximo del stack
 * \return El Stack creado, NULL si no se creo
 *
 */
Stack_t *StackCreate(int size);

void StackDestroy(Stack_t *ps);

int StackPush(Stack_t *ps, int e);

int StackPop(Stack_t *ps, int *pe);

int StackIsEmpty(Stack_t *ps);

int StackFilter(Stack_t *pStk, int e);

int StackFilter_nonRecursive(Stack_t *pStk, int e);
#endif
