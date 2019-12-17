#include <stdio.h>
#include <stdlib.h>

double **AllocaMatSimetrica(int n);
void LiberaMatSimetrica(double **pMat, int n);
double GetElement(double **pMat, int n, int i, int j);
void SetElement(double **pMat, int n, int i, int j, double X);

double **AllocaMatSimetrica(int n)
{
    int i;
    double **laMatrix = (double **)malloc(n*sizeof(double *));
    if (laMatrix == NULL)
    {
        fprintf(stderr, "No se pudo asignar la Matrix. Houston, tenemos un problema.\n");
        return NULL;
    }
    for (i=0;i<n;i++)
    {
        laMatrix[i] = (double *)malloc((i+1)*sizeof(double));
        if (laMatrix[i]==NULL)
        {
            fprintf(stderr,"Me quede corto de memoria.\n");
            LiberaMatSimetrica(laMatrix,i);
            return NULL;
        }
    }
    return laMatrix;
}

void LiberaMatSimetrica(double **pMat, int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        free(pMat[i]);
    }
    free(pMat);
}

double GetElement(double **pMat, int n, int i, int j)
{
    if (i>=n || j>=n)
    {
        fprintf(stderr,"No se pudo encontrar el elemento %d,%d.\n",i,j);
        return 0;
    }
    int aux;
    if (i<j)
    {
        aux=j;
        j=i;
        i=aux;
    }
    return pMat[i][j];
}

void SetElement(double **pMat, int n, int i, int j, double X)
{
    if (i>=n || j>=n)
    {
        fprintf(stderr,"No se pudo encontrar el elemento %d,%d.\n",i,j);
        return;
    }
    int aux;
    if (i<j)
    {
        aux=j;
        j=i;
        i=aux;
    }
    pMat[i][j]=X;
}

double ** sumaSimetricas(double ** matriz1, double ** matriz2, int n)
{
    return NULL;
}

double ** multiplicaMatriz(double ** matriz1, double ** matriz2, int n)
{
    return NULL;
}

int main()
{
    printf("Hello world!\n");
    return 0;
}
