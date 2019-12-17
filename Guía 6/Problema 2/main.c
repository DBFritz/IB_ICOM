#include <stdio.h>
#include <stdlib.h>
#define MAX_RAND 32768
#define N 2048
#define lanzadas 32768


int posRandom(int random)
{
    int i;
    for(i=0;i<N;i++)
    {
        if (i*MAX_RAND/N<=random && random<(i+1)*MAX_RAND/N)
        {
            return i;
        }
    }
    return -1;
}

void imprimeResultados(int contador[])
{
    int i;
    FILE * file;
    file = fopen("datos.txt", "wt");
    for(i=0;i<N;i++)
    {
        fprintf(file, "%d\n", contador[i]);
    }
    fclose(file);
}

void muestra(int contador[])
{
    int i;
    for(i=0;i<N;i++)
    {
        printf("%d\n", contador[i]);
    }
}

int main()
{
    srand(time(NULL));
    int contador[N] = {0};
    int random, i;
    for(i=0;i<lanzadas;i++)
    {
        random=rand() % MAX_RAND;
        contador[posRandom(random)]++;
    }

    imprimeResultados(contador);

    muestra(contador);

    return 0;
}
