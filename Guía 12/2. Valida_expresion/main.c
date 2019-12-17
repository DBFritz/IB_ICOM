#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include <string.h>

int CheckExpresion(const char *expr)
{
    int i = -1, j, lectura;
    char open[] = "([{";
    char close[] = ")]}";
    Stack_t * stack = StackCreate(strlen(expr));
    while (expr[++i])
    {
        for (j=0;j<strlen(open);j++)
        {
            if (expr[i]==open[j])
            {
                StackPush(stack, expr[i]);
                break;
            }
            else if (expr[i]==close[j])
            {
                if (StackIsEmpty(stack))
                {
                    StackDestroy(stack);
                    return 0;
                }
                StackPop(stack, &lectura);
                if (lectura != open[j])
                {
                    StackDestroy(stack);
                    return 0;
                }
                break;
            }
        }
    }
    if (StackIsEmpty(stack))
    {
                    StackDestroy(stack);
                    return 1;
    }
    StackDestroy(stack);
    return 0;;
}

int main()
{
    char sentencia[] = "A+Y*{12+z*[sin(34+PI*(2+Y)) + 3] + Q} + (4*Y)";
    printf("La sentencia %s es %s",sentencia, (CheckExpresion(sentencia))?"VALIDA":"INVALIDA");
    return 0;
}
