#include <stdio.h>
#include <stdlib.h>

struct Persona {
 char nombre[64];
 char apellido[64];
 int dni;
};

void CargaPersona(struct Persona *pper)
{
    puts("Ingrese el nombre de la persona:\t");
    gets(pper->nombre);
    printf("Ingrese el apellido de %s:\t", pper->nombre);
    gets(pper->apellido);
    puts("Ingrese el dni de $s:\t", pper->nombre);
    fflush(stdin);

}


int main()
{
    printf("Hello world!\n");
    return 0;
}
