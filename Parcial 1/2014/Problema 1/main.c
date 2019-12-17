#include <stdio.h>
#include <stdlib.h>

int leeDatos(char filename[], float prob[])
{
    int indice;
    float probabilidad;
    char linea[32];
    FILE * archivo = fopen(filename, "rt");
    if (archivo == NULL)
    {
        fprintf(stderr, "Error al abrir el archivo %s", filename);
        return -1;
    }
    while (!feof(archivo))
    {
        fgets(linea, 32, archivo);
        sscanf(linea,"%d\t%f",&indice, &probabilidad);
        prob[indice] = probabilidad;
    }
    fclose(archivo);
    return 0;
}

int main()
{
    int tA, tB, tC, i, j;
    float probA[4], probB[4], probC[4], probMin=1;
    leeDatos("A.txt", probA);
    leeDatos("B.txt", probB);
    leeDatos("C.txt", probC);

    for(i=0;i<=4;i++)
    {
        for (j=0;j<=4;j++)
        {
            if ( i+j<=4 && probA[i]*probB[j]*probC[4-i-j] < probMin)
            {
                tA = i;
                tB = j;
                tC = 4-tA-tB;
                probMin = probA[tA]*probB[tB]*probC[tC];
            }
        }
    }

    printf("Para que sea más posible que no repruebe las tres materias deberá estudiar\n");
    printf("* %d dias la materia A\n* %d dias la materia B\n* %d dias la materia C", tA, tB, tC);
    return 0;
}
