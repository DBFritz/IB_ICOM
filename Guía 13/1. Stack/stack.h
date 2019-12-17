#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

typedef struct SNode{
    int value;
    struct SNode *next;
} *Stack_t;

int StackPush(Stack_t *ps, int e);

int StackPop(Stack_t *ps, int *pe);

int StackIsEmpty(Stack_t *ps);

int StackFilter(Stack_t *pStk, int e);

int StackFilter_nonRecursive(Stack_t *pStk, int e);
#endif
