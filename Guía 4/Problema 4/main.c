#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/*Pi. Utilizando la siguiente serie numérica propuesta por Leibniz */
int main()
{
    int n,i;
    double pi = 0;
    scanf("%d", &n);
    for(i=0;i<n;i++)
    {
        pi += 1.0/((4*i+1)*(4*i+3));
    }
    pi *= 8;
    printf("El valor de pi es %1.20f", pi);
    return 0;
}
