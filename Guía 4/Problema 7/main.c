#include <stdio.h>
#include <stdlib.h>

double calculaE()
{
    int i;
    double nroe=1.0;
    long int fac=1;
    /*
    for(i=0; i<0; i++)
    {
        fac *= i;
        e += 1.0/fac;
    }
    */
    return nroe;
}

int main()
{
    double e;
    e= calculaE();
    printf("El valor de e calculado es %ld", e);
    return 0;
}
