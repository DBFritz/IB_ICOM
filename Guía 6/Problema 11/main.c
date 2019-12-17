#include <stdio.h>
#include <stdlib.h>

typedef struct {
    double x;
    double y;
} Punto2D_t;

Punto2D_t leePunto(void)
{
    Punto2D_t punto;
    printf("Ingrese la coordenada x: ");
    scanf("%lf", &punto.x);
    printf("Ingrese la coordenada y: ");
    scanf("%lf", &punto.y);
    return punto;
}

double prod(Punto2D_t punto1, Punto2D_t punto2)
{
    return punto1.x*punto2.x+punto1.y*punto2.y;
}

double mod(Punto2D_t punto)
{
    return sqrt(prod(punto, punto));
}

Punto2D_t diff(Punto2D_t minuendo, Punto2D_t sustraendo)
{
    Punto2D_t diferencia;
    diferencia.x = minuendo.x - sustraendo.x;
    diferencia.y = minuendo.y - sustraendo.y;
    return diferencia;
}

int analizaLados(Punto2D_t * vert)
{
    if (mod(diff(vert[0],vert[1]))==mod(diff(vert[1],vert[2])))
    {
        if (mod(diff(vert[0],vert[1]))==mod(diff(vert[0],vert[2])))
        {
            return 0;
        }else {
            return 1;
        }
    } else if (mod(diff(vert[0],vert[1]))==mod(diff(vert[0],vert[2])))
        return 1;
    else
        return 2;

    return -1;
}


int analizaAngulos(Punto2D_t * vert)
{
    int i;
    float cosAng;
    for(i=0;i<3;i++)
    {
        cosAng = prod(diff(vert[i],vert[(i+1)%3]),diff(vert[i],vert[(i+2)%3]));
        if (cosAng==0)
            return 1;
        else if (cosAng<0)
            return 2;
    }
    return 0;
}

int main()
{
    int i;
    Punto2D_t triangulo[3];
    for (i=0;i<3;i++)
    {
        triangulo[i] = leePunto();
    }
    for(i=0;i<3;i++)
    {
        printf("%f\t%f\n", mod(diff(triangulo[i], triangulo[(i+1)%3])),
               prod(diff(triangulo[i],triangulo[(i+1)%3]),diff(triangulo[i],triangulo[(i+2)%3])));

    }
    switch (analizaLados(triangulo))
    {
        case 0: printf("\nEl triangulo es equilatero\n"); break;
        case 1: printf("\nEl triangulo es isoceles\n"); break;
        case 2: printf("\nEl triangulo es escaleno\n"); break;
        default: printf("Error, no se que paso\n");
    }
    switch (analizaAngulos(triangulo))
    {
        case 0: printf("\nEl triangulo es acutangulo\n"); break;
        case 1: printf("\nEl triangulo es rectangulo\n"); break;
        case 2: printf("\nEl triangulo es obtusangulo\n"); break;

    }
    return 0;
}
