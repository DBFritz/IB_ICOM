#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double *AllocVector(int n);
void FreeVector(double *pVect);
void FillRandVector(double *pVect, int n);
void SortVector(double *pVect, int n);
void PrintVector(double *pVect, int n);

double *AllocVector(int n)
{
    double *vector = (double *)malloc(n*sizeof(double));
    if (vector == NULL)
    {
        fprintf(stderr,"No se pudo guardar la memoria. Que pena.");
        exit(1);
    }
    return vector;
}

void FreeVector(double * pVect)
{
    free(pVect);
}

void FillRandVector(double *pVect, int n)
{
    static int semilla = 0;
    if (!semilla)
    {
        srand(time(NULL));
        semilla=1;
    }
    int i;
    for (i=0;i<n;i++)
    {
        pVect[i] = (double)rand()/RAND_MAX;
    }
}


int comparaVector(const void * v1, const void *v2)
{
    return ((*(double *)v1>=*(double *)v2)?1:-1);
}

void SortVector(double *pVect, int n)
{
    qsort(pVect, n, sizeof(double), comparaVector);
}

void PrintVector(double *pVect, int n)
{
    int i;
    putchar('(');
    for(i=0;i<n-1;i++)
    {
        printf("%lf, ",*(pVect+i));
    }
    printf("%lf)",*(pVect+n-1));
}

int main()
{
    int i;
    double * numeritos;
    clock_t start;
    for(i=1;;i*=2)
    {
        printf("%d Numeros.\t\t", i);
        numeritos = AllocVector(i);
        start = clock();
        FillRandVector(numeritos, i);
        printf("Me tarde %f s\t", ((double)clock()-start)/CLOCKS_PER_SEC);
        start = clock();
        SortVector(numeritos, i);
        printf("Me tarde %f s\n", ((double)clock()-start)/CLOCKS_PER_SEC);
        FreeVector(numeritos);
    }
}
