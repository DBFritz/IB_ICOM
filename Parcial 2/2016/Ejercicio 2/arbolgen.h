#ifndef ARBOLGEN_H_INCLUDED
#define ARBOLGEN_H_INCLUDED

#include "lista.h"

#define MAX_PARENTESCO 10
#define MAX_NOMBRE 20

// Estructura para almacenar los datos de una persona
typedef struct {
	int dni;
	char nombre[32];
} Persona_t;

typedef struct ArbolGen_s {
	Persona_t * pers; // datos de la persona
	struct ArbolGen_s * padre; // arbol paterno
	struct ArbolGen_s * madre; // arbol materno
} * ArbolGen_t;

// Extrae los datos de una persona del
// string line y los usa para crear una Persona_t
Persona_t * CreaPersona(char * line, char * parentesco);

// Crea el arbol genealogico completo de una persona
// a partir de los datos contenidos en el archivo
// una persona por linea, con el formato siguiente
// Ejemplo: E.P.P.M.P 8701739 Ireneo
ArbolGen_t CreaArbolGen(char * filename);

void ImprimeArbol(ArbolGen_t ar);

// Alloca un struct ArbolGen_s
ArbolGen_t CreaNodoArbolGen();

// Pone los datos de la persona en el nodo apuntado por ar
void setDatosPersona(ArbolGen_t ar, int dni, char * nombre);

// Destruye un arbol genealogico
void DestruyeArbolGen(ArbolGen_t a);

// Busca una persona en el arbol por dni.
// Si la encuentra, retorna verdadero y pone en *gen
// la profundidad  (generacion) en que se encuentra con respecto
// a la raiz del arbol.
int BuscaNivelPersona(ArbolGen_t a, int dni, int * gen);

/***************************************************************
 Estas funciones son las que tendrían que hacer...
****************************************************************/



#endif // ARBOLGEN_H_INCLUDED



