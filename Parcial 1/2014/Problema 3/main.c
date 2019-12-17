#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float pochhammer(float a,int k)
{
    if (k==0) return 1;
    return (a+k-1)*pochhammer(a,k-1);
}

unsigned long int factorial(int n)
{
    return ((n==0)?1:n*factorial(n-1));
}

float hyper(float a, float c, float z,int n)
{
    int i;
    float sum=0;
    for(i=0;i<n;i++)
        sum+=pochhammer(a,i)/pochhammer(c,i)*pow(z,i)/factorial(i);
    return sum;
}

int main()
{
    float z;
    do {
        printf("Ingrese un valor de z (0 para salir): ");
        scanf("%f",&z);
        printf("%f\tvs\t%f\n", hyper(1,2,2*z,10),exp(z)*sinh(z)/z);
        getchar();
    }while(z!=0);
}
