#include <stdio.h>
#include <stdlib.h>
#include "list.h"

List_t pasaBajo(List_t lista, int valueMax)
{
    int ___pasaBajo(int valor, void *params){
        return (valor<*((int *)params));
    }
    return FilterList(lista, ___pasaBajo, &valueMax);
}

List_t pasaPares(List_t lista)
{
    int ___pasaPares(int valor, void *params){
        return (!(valor%2));
    }
    return FilterList(lista, ___pasaPares, NULL);
}

List_t pasaRango(int min, int max, List_t lista)
{
    int ___pasaRango(int valor, void *params){
        return (*(int *)params <= valor && valor <= *((int *)params+1));
    }
    int params[] = {min, max};
    return FilterList(lista, ___pasaRango, params);
}

int main()
{
    List_t myNewLista = LIST_EMPTY;
    myNewLista = ListInsert(myNewLista, 6);
    myNewLista = ListInsert(myNewLista, 3);
    myNewLista = ListInsert(myNewLista, 7);
    myNewLista = ListInsert(myNewLista, 5);
    myNewLista = ListInsert(myNewLista, 4);

    puts("Lista:");
    ListPrint(myNewLista);
    putchar('\n');

    puts("Menores a 6:");
    ListPrint(pasaBajo(myNewLista, 6));
    putchar('\n');

    puts("Pares:");
    ListPrint(pasaPares(myNewLista));
    putchar('\n');

    puts("Entre 4 y 6:");
    ListPrint(pasaRango(4, 6, myNewLista));
    putchar('\n');

    return 0;
}
