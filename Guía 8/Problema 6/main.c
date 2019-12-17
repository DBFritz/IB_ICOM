#include <stdio.h>
#include <stdlib.h>
#define TAM 100
#define C '#'

void leeTablero(FILE * arch, int ** M, int color)
{
    int x,y;
    rewind(arch);
    while(!feof(arch))
    {
        x=getc(arch);
        getc(arch);
        y=getc(arch);
        getc(arch);
        printf("%d", x-'0');
        M[x-'0'][y-'0']=color;
    }
    rewind(arch);
}

void imprimeTablero(int M[8][8], int n, int m, int color)
{
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            if (M[i][j]==color) {
                putchar('#');
            } else {
                putchar('-');
            }
        }
        putchar('\n');
    }
}

void FloodFill(int M[8][8], int x, int y, int color)
{
    if (M[x][y] == color) return;
    M[x][y] =  color;
    FloodFill(M,x-1,y,color);
    FloodFill(M,x+1,y,color);
    FloodFill(M,x,y+1,color);
    FloodFill(M,x,y-1,color);
}

int main()
{
    int matrix[8][8] = {{0,0,0,0,1,1,1,0},
                        {0,1,1,1,1,0,1,0},
                        {0,1,0,0,0,0,1,0},
                        {0,1,1,0,1,1,1,0},
                        {0,1,0,0,1,0,0,0},
                        {0,1,1,0,1,1,0,0},
                        {0,0,1,0,0,1,0,0},
                        {0,0,1,1,1,1,0,0}};
    imprimeTablero(matrix, 8, 8, 1);
    FloodFill(matrix,2,2,1);
    printf("\n\n");
    imprimeTablero(matrix, 8, 8, 1);
}
/*
int main()
{
    int n, m,x,y, i;
    int matrix[100][100];
    FILE * data;
    if ((data = fopen("datos.txt", "rt")) == NULL)
    {
          fprintf(stderr, "Hubo un error al leer el archivo");
    }
    printf("Ingrese la cantida de filas:\t");
    scanf("%d",&n);

    printf("Ingrese la cantida de filas:\t");
    scanf("%d",&m);

    matrix = (int **)malloc(n*sizeof(int *));
    for(i=0;i<n;i++) matrix[i] = (int *)malloc(m*sizeof(int));

    system("cls");

    x=getc(data);
    printf("%c", x);
    while(!feof(data))
    {
        x=getc(data);
        getc(data);
        y=getc(data);
        getc(data);
        printf("%d", x-'0');
        matrix[x-'0'][y-'0']=C1;
    }
    rewind(data);

    imprimeTablero(matrix, n, m, C1);
    puts("\n\n");
    FloodFill(matrix, n, m,  C1);
    imprimeTablero(matrix, n, m, C1);

    fclose(data);

    return 0;
}

*/
