#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "myFunc.h"

#define N 100000000

int main()
{
	int cantidad;
	double * Vector;
	printf("Ingrese la cantidad de vectores a leer: ");
	scanf("%d", &cantidad);
	Vector = malloc(cantidad* sizeof(double));
	LeeVector(Vector, cantidad);
	OrdenaVectores(Vector, cantidad);
	printf("\n\nEl vector ordenado es:\n");
	ImprimeVector(Vector, cantidad);
	free(malloc);
	return 0;
}
