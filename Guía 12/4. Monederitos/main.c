#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int valor; // valor de la denominación en centavos
    int cantidad; // cantidad de billetes/moneda necesarios
} Denominacion;

typedef struct {
    int numDenominaciones; // cantidad de denominaciones
    Denominacion *pMonedas; // denominaciones a utilizar
} Monedero;

/** \brief Crea e inicializa un monedero con capacidad para manejar
    numDenom denominaciones                                         */
Monedero *CreaMonedero(int numDenom);

/** Destruye un monedero liberando todos los recursos de memoria    */
void DestruyeMonedero(Monedero *pMonedero);

/** \brief Inicializa la entrada indice del monedero para manejar
    la denominación de valor valor (en centavos). Este servicio
    debe ser llamado con valores crecientes de valor.               */
int SetDenominacion(Monedero *pMonedero, int indice, int valor);

/** \brief Agrega un sueldo a ser distribuido en las distintas
    denominaciones, apuntando a minimizar la cantidad de
    billetes/moneda a entregar                                      */
int AgregaSueldo(Monedero *pMonedero, double montoSueldo);

/** \brief Retorna la cantidad de billetes/monedas necesarios de la
    denominacion de valor valor                                     */
int CantidadValor(Monedero *pMonedero, int valor);

int main()
{
    printf("Hello world!\n");
    return 0;
}

Monedero *CreaMonedero(int numDenom)
{
    int i;
    Monedero * monedero = (Monedero *)malloc(sizeof(Monedero));
    if (monedero==NULL) return NULL;
    monedero->pMonedas = (Denominacion *)malloc(numDenom*sizeof(Denominacion));
    if (monedero->pMonedas == NULL)
    {
        free(monedero);
        return NULL;
    }
    for(i=0;i<numDenom;i++)
    {
        monedero->pMonedas[i].cantidad = 0;
    }
    monedero->numDenominaciones = numDenom;
    return monedero;
}

void DestruyeMonedero(Monedero *pMonedero)
{
    free(pMonedero->pMonedas);
    free(pMonedero);
}

int SetDenominacion(Monedero *pMonedero, int indice, int valor)
{
    if (indice >= pMonedero->numDenominaciones) return 0;
    pMonedero->pMonedas[indice].valor = valor;
    return 1;
}

int AgregaSueldo(Monedero *pMonedero, double montoSueldo)
{
    int i, cantidad = 0, iMax,valorMax = 0;
    while (valorMax)
        valorMax=0;
        for (i=0;i<pMonedero->numDenominaciones;i++)
        {
            if (valorMax < pMonedero->pMonedas[i].valor && pMonedero->pMonedas[i].valor <= montoSueldo)
            {
                valorMax= pMonedero->pMonedas[i].valor;
                iMax = i;
            }
        }
        if (!valorMax)
        {
            pMonedero->pMonedas[iMax].cantidad++;
            montoSueldo -= pMonedero->pMonedas[iMax].valor;
            cantidad++;
        }
    return cantidad;
}

int CantidadValor(Monedero *pMonedero, int valor)
{
    int i;
    for(i=0;i<pMonedero->numDenominaciones;i++)
        if (pMonedero->pMonedas[i].valor == valor)
            return pMonedero->pMonedas[i].cantidad;
    return 0;
}
