#include <stdio.h>
#include <stdlib.h>

/**
Los alfiles en el ajedrez se mueven a lo largo de las diagonales y amenazan a aquellas piezas que se encuentran en su
misma diagonal.
a) Escriba un programa que encuentre el número máximo de alfiles que se pueden colocar en las casillas negras del
tablero de ajedrez sin que ninguno de los alfiles colocados se amenacen entre sí.
b) ¿Cuántas soluciones diferentes pueden encontrarse para el número máximo de alfiles colocados en las casillas negras
del tablero?
c) Imprima en pantalla las soluciones encontradas.
*/

typedef struct
{
    int x;
    int y;
} Ficha_t;

typedef struct tablero_struct
{
    int nFichas;
    int ultima;                     /**< La última ficha del tablero puesta */
    Ficha_t * ficha;
} *Tablero_t;

Tablero_t creaTablero(int NroFichitas);
{
    Tablero_t newTablero = (Tablero_t)malloc(sizeof(struct tablero_struct));
    newTablero->ficha = (Ficha_t *)malloc(NroFichitas*sizeof(Ficha_t));
    newTablero->nFichas = NroFichitas;
    newTablero->ultima = 0;
}

void vaciaTablero(Tablero_t tablero)
{
    free(tablero->ficha);
    tablero->nFichas = 0;
    tablero.ultima = 0;
}

int poneFicha(Tablero_t tablero, Ficha_t fichita)
{
    if (tablero->ultima==tablero->nFichas) return 0;
    tablero->ficha[tablero->ultima++] = fichita;
    return 1;
}

Ficha_t sacaFicha(Tablero_t tablero)
{
    if (tablero->ultima)
        return (tablero->ficha[tablero->ultima--]);
    Ficha_t nula;
    nula.x = -1;
    nula.y = -1;
    return nula;
}



int main()
{
    printf("Hello world!\n");
    return 0;
}
