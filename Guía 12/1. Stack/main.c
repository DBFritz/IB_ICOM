#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int main()
{
    int letra,i;
    Stack_t * stack = StackCreate(16);
    StackPush(stack, 'a');
    StackPush(stack, 'b');
    StackPush(stack, 'a');
    StackPush(stack, 'c');
    StackFilter(stack, 'a');
    while (!StackIsEmpty(stack))
    {
        StackPop(stack, &letra);
        putchar(letra);
    }
    return 0;
}
