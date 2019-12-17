#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct{
    double x;
    double y;
    double z;
} P3D_t;

P3D_t CargaP3D()
{
    P3D_t punto;
    printf("Ingrese la coordenada x: ");
    scanf("%lf", &punto.x);
    printf("Ingrese la coordenada y: ");
    scanf("%lf", &punto.y);
    printf("Ingrese la coordenada z: ");
    scanf("%lf", &punto.z);
    return punto;
}

P3D_t RestaP3D(P3D_t v, P3D_t w)
{
    P3D_t resta;
    resta.x = v.x - w.x;
    resta.y = v.y - w.y;
    resta.z = v.z - w.z;
    return resta;
}

P3D_t ProdVectP3D(P3D_t v, P3D_t w)
{
    P3D_t prod;
    prod.x = v.y*w.z-v.z*w.y;
    prod.y = v.z*w.x-v.x*w.z;
    prod.z = v.x*w.y-v.y*w.x;
    return prod;
}

double ModuloP3D(P3D_t v)
{
    return sqrt(v.x*v.x+v.y*v.y+v.z*v.z);
}

int main()
{
    P3D_t A,B,C;
    A=CargaP3D();
    B=CargaP3D();
    C=CargaP3D();

    printf("El area del triangulo formado por los puntos ingresados es: %lf",
           ModuloP3D(ProdVectP3D(RestaP3D(B,A),RestaP3D(C,A)))/2);
}
