#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int grado;
    double *coefs;
} Polinomio_t;

Polinomio_t *PolAlloc( int grado );

void PolFree(Polinomio_t *pPol);

int PolSetCoef(Polinomio_t *pPol, int cIdx, double v);

double PolEval(Polinomio_t *pPol, double x);

Polinomio_t *PolDeriv(Polinomio_t *pPol);

Polinomio_t *PolInteg(Polinomio_t *pPol);

int main()
{
    printf("Hello world!\n");
    return 0;
}

Polinomio_t *PolAlloc( int grado )
{
    int i;
    Polinomio_t *pPol = (Polinomio_t *)
    malloc(sizeof(Polinomio_t));
    if (pPol==NULL)
    {
        fprintf(stderr,"Error al asignar memoria");
        return NULL;
    }
    // inicializacion de miembros
    pPol->grado = grado;
    pPol->coefs = (double *)
    malloc((grado+1) * sizeof(double));
    if (pPol->coefs==NULL)
    {
        fprintf(stderr,"Error al asignar memoria");
        return NULL;
    }
    for( i = 0; i <= grado; i++ )
        pPol->coefs[i] = 0;
    return pPol;
}

void PolFree(Polinomio_t *pPol)
{
    free(pPol->coefs);
    free(pPol);
}

int PolSetCoef(Polinomio_t *pPol, int cIdx, double v)
{
    if(cIdx >= 0 && cIdx <= pPol->grado) {
        pPol->coefs[cIdx] = v;
        return 1;
    }
    return 0;
}

double PolEval(Polinomio_t *pPol, double x)
{
    double y=0,xi=1;
    int i;
    for (i=0;i<pPol->grado;i++)
    {
        y+= pPol->coefs[i] *xi;
        xi*=x;
    }
    return y;
}

Polinomio_t * PolDeriv(Polinomio_t *pPol)
{
    int i;
    Polinomio_t * dpol = PolAlloc( pPol->grado -1);
    for(i=0; i <= dpol->grado;i++)
    {
        dpol->coefs[i] = pPol->coefs[i+1]*(i+1);
    }
    return dpol;
}

Polinomio_t *PolInteg(Polinomio_t * pPol){
    int i;
    Polinomio_t * ipol = PolAlloc( pPol->grado +1);
    ipol->coefs[0]=0;
    for(i=1; i <= ipol-> grado; i++)
    {
        ipol->coefs[i] = pPol->coefs[i+1]/(i+1);
    }
    return ipol;
}
