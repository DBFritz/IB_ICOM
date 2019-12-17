#include <stdio.h>
#include <math.h>

double promedio(double * datos, int muestras)
{
    int i;
    double sum = 0;
    for(i=0;i<muestras;i++)
    {
        sum+=datos[i];
    }
    return sum/muestras;
}

double dstandard(double * datos, int muestras)
{
    int i;
    double sumSq = 0, prom = promedio(datos, muestras);
    for(i=0;i<muestras;i++)
    {
        sumSq += (datos[i]-prom)*(datos[i]-prom);
    }
    return sqrt(sumSq/(muestras-1));
}
