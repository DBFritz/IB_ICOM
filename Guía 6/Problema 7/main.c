#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "myFunc.h"

int main()
{
	int i;

	int cantidad;
	double vector[RAND_MAX];
    srand(time(NULL));
    /*
	double * vector;
	int cantidad = rand();
	if (vector = malloc(cantidad*sizeof(double))==NULL)
	{
	    printf("Algo extraño paso, un embole.");
	    getchar();
	    exit(1);
	}
    */
    cantidad = rand();
    printf("Se ordenaran %d elementos, esto va a llevar un tiempo... anda preparate un tesito.", cantidad);
    for(i=0;i<cantidad;i++)
    {
        vector[i] = rand();
    }

	clock_t begin = clock();
    OrdenaVectores(vector, cantidad);
	clock_t end = clock();

	double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("\n\nEl ordenamiento de %d numeros random duro %lf segundos\n", cantidad, time_spent);

    return 0;
}
