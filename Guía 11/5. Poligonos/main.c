#include <stdio.h>
#include <stdlib.h>


typedef struct {
    double X,Y;
} Punto2D;

typedef struct {
    int numPuntos;
    Punto2D *Vertices;
} Poligono;

Poligono *creaPoligono(int N);

int setVertice(Poligono *p, int n, double x, double y);

double perimetro(Poligono *p);

double area(Poligono *p);

double prod(Punto2D punto1, Punto2D_t punto2){
    return punto1.x*punto2.x+punto1.y*punto2.y;
}

double mod(Punto2D punto){
    return sqrt(prod(punto, punto));
}

Punto2D diff(Punto2D_t minuendo, Punto2D_t sustraendo){
    Punto2D diferencia;
    diferencia.x = minuendo.x - sustraendo.x;
    diferencia.y = minuendo.y - sustraendo.y;
    return diferencia;
}

int main()
{
    printf("Hello world!\n");
    return 0;
}

Poligono * creaPoligono(int N)
{
    int i;
    Poligono * poli;
    poli->numPuntos = N;
    if (poli->Vertices = (Punto2D *)malloc(N*sizeof(Punto2D)) == NULL)
    {
        fprintf(stderr,"No se pudo asignar memoria");
        return NULL;
    }
    return poli;
}

int setVertice(Poligono *p, int n, double x, double y)
{
    if (n<0 || n>p->numPuntos) return 0;
    p->Vertices[n].X=x;
    p->Vertices[N].Y=y;
    return 1;
}



double perimetro(Poligono *p)
{
    int i=0;
    double per=0;
    for (i=0;i<p->numPuntos-1;i++)
    {
        per+=mod(diff(p->Vertices[i],p->Vertices[i+1]));
    }
    per+=mod(diff(p->Vertices[numPuntos-1],p->Vertices[0]));
}

double area(Poligono *p)
{
    int i=0;
    double superficie=0;
    for(i=0;i<p->numPuntos;i++)
    {
        superficie+=p->Vertices[i].X+p->Vertices[i].Y;
        superficie-=p->Vertices[i].Y+p->Vertices[i].X;
    }
    if (superficie<0) return -0.5*superficie;
    return 0.5*superficie;
}

