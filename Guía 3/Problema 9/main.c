#include <stdio.h>
#include <stdlib.h>

typedef struct {
    float re;
    float im;
} COMPLEX;

COMPLEX sumaComplejos(COMPLEX z1, COMPLEX z2){
    COMPLEX suma;
    suma.re = z1.re + z2.re;
    suma.im = z1.im + z2.im;
    return suma;
}

COMPLEX multiplicaComplejos(COMPLEX z1, COMPLEX z2){
    COMPLEX prod;
    prod.re = z1.re * z2.re - z1.im * z2.im;
    prod.im = z1.re * z2.im + z1.im * z2.re;
    return prod;
}

int main()
{
    COMPLEX z1, z2, suma, prod;
    printf("Escriba la parte real de z1: ");
    scanf("%f", &z1.re);
    printf("Escriba la parte imaginaria de z1: ");
    scanf("%f", &z1.im);
    printf("Escriba la parte real de z1: ");
    scanf("%f", &z2.re);
    printf("Escriba la parte imaginaria de z1: ");
    scanf("%f", &z2.im);
    suma = sumaComplejos(z1,z2);
    prod = multiplicaComplejos(z1,z2);
    printf("\nLa suma de ambos numeros es: (%.3f)+(%.3f)i", suma.re, suma.im);
    printf("\nLa suma de ambos numeros es: (%.3f)+(%.3f)i", prod.re, prod.im);
}
