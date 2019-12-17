#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "arbolgen.h"
#include "lista.h"

int BuscaPersona(ArbolGen_t a, int dni);
int BuscaNivelPersona(ArbolGen_t a, int dni, int * gen);
int NivelPersona(ArbolGen_t a, int dni, int * nivel);
List_t ListaAncestrosComunes(ArbolGen_t a, ArbolGen_t b, List_t lac);
// double CoefRelacionOrigen(ArbolGen_t a, int dni);
double CoefRelacion(ArbolGen_t a, ArbolGen_t b);


int main()
{
    ArbolGen_t coco;
    ArbolGen_t pepe;

    coco = CreaArbolGen("coco.txt");
    pepe = CreaArbolGen("pepe.txt");

    printf("El coeficiente de Relacion entre coco y pepe es: %lf\n",CoefRelacion(coco,pepe));

    puts("Los ancestros comunes tienen los siguientes DNI:");
    List_t ancestrosComunes = NULL;
    ancestrosComunes = ListaAncestrosComunes(coco, pepe, ancestrosComunes);
    ListPrint(ancestrosComunes);
    ListDestroy(ancestrosComunes);

    DestruyeArbolGen(coco);
    DestruyeArbolGen(pepe);
    return 0;
}

int BuscaPersona(ArbolGen_t a, int dni) {
    if (a == NULL) return 0;
    else if (a->pers->dni == dni) return 1;
    return (BuscaPersona(a->madre, dni) || BuscaPersona(a->padre, dni));
}

/*  El contenido de nivel debe ser un cero.    */
int NivelPersona(ArbolGen_t a, int dni, int * nivel) {
	if (!BuscaPersona(a, dni))
    {
        *nivel = 0;
        return 0;
    }
	else if(a->pers->dni == dni)
		return 1;
	else if(BuscaPersona(a->madre,dni))
    {
           *nivel = 1 + *nivel;
           return (NivelPersona(a->madre, dni, nivel));
    }
    *nivel = 1 + *nivel;
    return (NivelPersona(a->padre, dni, nivel));
}

List_t ListaAncestrosComunes(ArbolGen_t a, ArbolGen_t b, List_t lac) {
    if (a == NULL) return lac;
    if (BuscaPersona(b,a->pers->dni))
        lac = ListNodeCreate(a->pers->dni, lac);
    lac = ListaAncestrosComunes(a->madre,b,lac);
    lac = ListaAncestrosComunes(a->padre,b,lac);
    return lac;
}

/* EN VEZ DE USARSE POW EN CoefRelacion PODRÍA USARSE ESTA FUNCIÓN
double CoefRelacionOrigen(ArbolGen_t a, int dni)
{
    int i, nivel = 0;
    if (!(NivelPersona(a, dni, &nivel))) return 0;
    double relacion = 1;
    for(i=0;i<nivel;i++)
        relacion*=0.5;
    return relacion;
}
*/

double CoefRelacion(ArbolGen_t a, ArbolGen_t b){
    double relacion = 0;
    int nivel[2];
    List_t viejosComunes = NULL;
    viejosComunes = ListaAncestrosComunes(a,b,viejosComunes);
    while (viejosComunes != NULL)
    {
        //relacion+= CoefRelacionOrigen(a, viejosComunes->cont)
        //            *CoefRelacionOrigen(b, viejosComunes->cont);
        nivel[0] = 0;
        nivel[1] = 0;
        NivelPersona(a, viejosComunes->cont, nivel);
        NivelPersona(b, viejosComunes->cont, nivel+1);
        relacion += pow(0.5,nivel[0])*pow(0.5,nivel[1]);
        viejosComunes = viejosComunes->pNext;
    }
    return relacion;
}
