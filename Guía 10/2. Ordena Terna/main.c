#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int i;
    int j;
    int value;
} Terna;

static int cmpTerna(const void * pr1, const void * pr2)
{
    return ((Terna *)pr1)->value - ((Terna *)pr2)->value;
}


void ordenaTerna(Terna * terna, int cantidad)
{
    qsort(terna, cantidad, sizeof(Terna), cmpTerna);
}

int main()
{
    printf("Hello world!\n");
    return 0;
}
