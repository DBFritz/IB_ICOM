#include <stdio.h>
#include <stdlib.h>
#include "regresion_lineal.h"
#define TAM 257

int leeDatos(char filename[], double x[], double y[])
{
    int i=0;
    FILE * archivo;
    archivo = fopen(filename, "r");
    if (archivo == NULL)
    {
        fprintf(stderr, "Error al abrir el archivo %s", filename);
        exit(-1);
    }

    while(!feof(archivo))
    {
        fscanf(archivo,"%lf",&y[i]);
        x[i]=i;
        i++;
    }
    fclose(archivo);
    return --i;
}
double estimaQuiebre(double * x, double * y, int length)
{
    int i;
    double chi2Min, chi2, xmin= -1;
    FitParams recta[2];
    recta[0] = fitLineal(length, x, y);
    chi2Min=recta[0].chi2;
    // printf("%lf\n",chi2Min);
    for(i=1;i<length;i++)
    {
        recta[0] = fitLineal(i,x,y);
        recta[1] = fitLineal(length-i,x+i,y+i);
        chi2 = recta[0].chi2 + recta[1].chi2;
        // printf("%lf\t%lf\n",x[i], chi2);
        if (chi2 < chi2Min)
        {
            xmin=x[i];
            chi2Min= chi2;
        }
    }
    return xmin;
}

int main()
{
    int n,i;
    double x[TAM], y[TAM];
    char filename[20] = "dataX.txt";
    for(i=1;i<=5;i++)
    {
        filename[4] = '0'+i;
        n=leeDatos(filename, x, y);
        printf("En los datos %d, se estima un quiebre para x=%lf\n", i , estimaQuiebre(x,y,n));
    }
    return 0;
}
