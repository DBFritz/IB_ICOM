#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double miSqrt(double a)
{
    int i=0;
    double x=1, x_anterior=0;
    while (sqrt(pow(x-x_anterior,2))>=0.00001)
    {
        x_anterior=x;
        x= (x_anterior+a/x_anterior)/2;
        i++;
    }
    printf("\nConvergio en %d iteraciones\n",i);
    return x;
}

int main()
{
    float a,x=1;
    printf("Ingrese el valor de a: ");
    scanf("%f", &a);
    printf("La raiz calculada de %f fue: %lf\nEl verdadero valor es %lf", a, miSqrt(a), sqrt(a));
    return 0;
}
