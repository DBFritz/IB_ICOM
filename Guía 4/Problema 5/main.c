#include <stdio.h>
#include <stdlib.h>

int main()
{
    unsigned int n,sum,i;
    printf("Ingrese el número hasta el que quiere sumar: ");
    scanf("%d", &n);
    for(sum=0, i=1;i<=n;sum+=i, i++);
    printf("\nLa suma fue %d\n\n",sum);
    return 0;
}
