#include <stdio.h>
#include <stdlib.h>

/// MCD de forma recursiva
int MCD(int A, int B)
{
    if (A<B)    // Se ingresaron mal los parámetros
    {
        fprintf(stderr,"ERROR, el primer numero es mayor al segundo");
        return -1;
    }
    return (B!=0)?MCD(B,A%B):A;
}

int MCM(int A, int B)
{
    return (A*B)/MCD(A,B);
}

int main()
{
    int A,B;
    do{
        printf("Ingrese el numero grande:\t");
        scanf("%d",&A);
        printf("Ingrese el numero pequenio:\t") ;
        scanf("%d",&B);
        printf("\nEl MCM entre %d y %d es\t%d\n", A,B,MCM(A,B));
        printf("El MCD entre %d y %d es\t%d", A,B,MCD(A,B));
    } while (A==0 && B==0);
}
