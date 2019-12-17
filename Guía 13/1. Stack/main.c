#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int main()
{
    int letra,i;
    Stack_t * stack = NULL;
    printf("%d", StackIsEmpty(stack));
    StackPush(stack, 'a');
    printf("%d", StackIsEmpty(stack));
    StackPush(stack, 'b');
    StackPush(stack, 'a');
    StackPush(stack, 'c');
//    StackFilter(stack, 'a');
    while (!StackIsEmpty(stack))
    {
        StackPop(stack, &letra);
        putchar(letra);
    }
    return 0;

    return 0;
}
