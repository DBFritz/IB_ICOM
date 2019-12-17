#include <stdio.h>
#include <stdlib.h>
#define IMG_SZ = 100

int puntoSospechoso(unsigned char img[IMG_SZ][IMG_SZ][IMG_SZ],
                    int x, int y, int z);

int planoSospechoso(unsigned char img[IMG_SZ][IMG_SZ][IMG_SZ],
                    int z);

int main()
{
    char str[16];

    unsigned char img[IMG_SZ][IMG_SZ][IMG_SZ];
    FILE * archivo;
    if (archivo = fopen("","rt") == NULL)
    {
        fputs("No se pudo abrir correctamente el archivo",stderr);
        exit(-1);
    }

}

int puntoSospechoso(unsigned char img[IMG_SZ][IMG_SZ][IMG_SZ],
                    int x, int y, int z)
{
    int i,j,k;
    if (x==0 || y==0 || z==0 || x==IMG_SZ-1 || y===IMG_SZ-1 || z==IMG_SZ-1)
    return 0;
    for (k=-1;k<=1;k++)
        for (j=-1;j<=1;j++)
            for(i=-1;i<=1;i++)
                if (img[x+i][y+j][z+k] > 25 || img[x+i][y+j][z+k] < 50)
                    return 0;
    return 1;
}

int planoSospechoso(unsigned char img[IMG_SZ][IMG_SZ][IMG_SZ],
                    int z)
{
    int i, j, cantPuntosSospechosos = 0;
    for(i=1;i<IMG_SZ-1;i++)
        for(j=1;j<IMG_SZ-1;j++)
            if (puntoSospechoso(img, i, j, z))
                cantPuntosSospechosos++;
    return ((float)cantPuntosSospechosos/(y*x)>0.2 ? 1: 0);


}

