#include <stdio.h>
#include <stdlib.h>
#define TAM 500

typedef struct {
int i;
int j;
int v;
} Terna_t;

Terna_t terna[TAM*TAM];

int determinaUber(int n, int cantidad)
{
    int i=0,j,esUber = 0;
    while(!esUber && i<cantidad)
    {
        esUber = 1;
        for(j=1;j<n;j++)
        {
            if (terna[i].v!=terna[i+j].v)
            {
                esUber = 0;
                break;
            }
        }
        i++;
    }
    i--;
    for(j=0;j<n;j++)
    {
        printf(" %d^3+%d^3 =", terna[i+j].i, terna[i+j].j);
    }
    printf(" %d\n",terna[i].v);
    return terna[i].v;
}


int main()
{
    int i,j, cant=0;
    Terna_t aux;

    for(i=1; i<TAM;i++)
    {
        for(j=i; j<TAM; j++)
        {
            terna[cant].i = i;
            terna[cant].j = j;
            terna[cant].v = i*i*i+j*j*j;
            cant++;
        }
    }

    printf("Ordenando...\n");
    for(i=1;i<cant;i++)
    {
        j=i;
        while(j>0 && terna[j-1].v > terna[j].v)
        {
            aux=terna[j];
            terna[j]=terna[j-1];
            terna[j-1]=aux;
            j--;
        }
    }
    printf("Exito!\n");

    for(i=1;i<=3;i++)
    {
        printf("T(%d) =",i);
        determinaUber(i,cant);
    }
    return 0;
}
