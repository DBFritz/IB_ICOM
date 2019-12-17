#include <stdio.h>
#include <stdlib.h>

float maximiza(float * x, float * y, int len)
{
    int i, imax=0;
    for(i=1;i<len;i++)
    {
        if (y[i]>y[imax])
        {
            imax = i;
        }
    }
    return x[imax];
}

int lines(FILE * archivo)
{
    int cantidad = 1;
    rewind(archivo);
    while (!feof(archivo))
    {
        if (fgetc(archivo)=='\n')
        {
            cantidad++;
        }
    }
    rewind(archivo);
    return cantidad;
}

void extrae(FILE * file, float * x, float * y)
{
    int i =0;
    rewind(file);
    while (!feof(file))
    {
        fscanf(file,"%f\t%f",&x[i],&y[i]);
        i++;
    }
    rewind(file);
}
int main()
{
    int len;
    float * x, * y;
    FILE * file;
    if ((file = fopen("peaks.dat", "rt"))==NULL)
    {
        fprintf(stderr, "Hubo un error al abrir el archivo \"peaks.dat\".");
        return -1;
    }
    len = lines(file);

    if ((x = (float *)malloc(len*sizeof(float)))==NULL)
    {
        fprintf(stderr, "No se pudo almacenar memoria.");
        return -2;
    }

    if ((y = (float *)malloc(len*sizeof(float)))==NULL)
    {
        fprintf(stderr, "No se pudo almacenar memoria.");
        return -2;
    }

    extrae(file, x, y);
    int i;
    printf("hay %d valores leidos\n", len);
    for (i=0;i<10;i++)
    {
        printf("%f\t%f\n",x[i],y[i]);
    }
    printf("El valor maximo de y se encuentra para x=%.3f", maximiza(x,y,len));


    fclose(file);
    free(x);
    free(y);
    return 0;
}
