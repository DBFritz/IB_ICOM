#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i;
    float x1=1.126, x2=-1.125, x3= -0.001, S=0;
    for(i=0;i<0xFFFFFF; i++)
    {
        S += x1+x2+x3;
    }
    printf("El resultado obtenido es %f", S);
}
