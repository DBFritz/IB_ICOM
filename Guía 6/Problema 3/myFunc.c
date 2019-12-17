#include <stdio.h>
#include <stdlib.h>
void ImprimeVector(double Vector[], int NumElementos)
{
    int i;
    putchar('(');
    for(i=0;i<NumElementos-1;i++)
    {
        printf("%lf, ",Vector[i]);
    }
    printf("%lf)", Vector[NumElementos-1]);
}

void LeeVector(double Vector[], int NumElementos)
{
    int i;
    for (i=0;i<NumElementos;i++)
    {
        printf("Ingrese la componente %d del vector: ", i+1);
        scanf("%lf",&Vector[i]);
    }
}

void OrdenaVectores(double Vector[], int NumElementos)
{
    int i,j;
    double aux;
    for(i=1;i<NumElementos;i++)
    {
        for(j=0;j<NumElementos-i;j++)
        {
            if (Vector[j]>Vector[j+1])
            {
                aux=Vector[j];
                Vector[j]=Vector[j+1];
                Vector[j+1]=aux;
            }
        }
    }
}
