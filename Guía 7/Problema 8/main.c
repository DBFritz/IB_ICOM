#include <stdio.h>
#include <stdlib.h>

int main()
{
    int tabs = 0;
    char lectura;
    FILE * datos;
    if ((datos = fopen("mapa.dat", "rt")) == NULL)
    {
        fprintf(stderr,"Error, no se pudo abrir el archivo.\n");
        printf("Error al abrir archivo.\n");
        return -1;
    }
    while (!feof(datos))
    {
        lectura = fgetc(datos);
        if (lectura=='\n')
        {
            tabs=0;
            putchar('\n');
        }

        if (2<=tabs && tabs<=3)
        {
            putchar(lectura);
        }

        if (lectura=='\t')
        {
            tabs++;
        }
    }

    fclose(datos);
    getchar();
    return 0;
}
