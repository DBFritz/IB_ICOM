#include <stdio.h>
#include <stdlib.h>
#include "trie.h"

/*
ERORRES CONOCIDOS:
    *   Las contraseñas pueden solaparse.
*/

int main()
{
    char choice;
    char string[1024];
    Trie_t *myTrie = trieCreate();
    puts("Bievenido!");
    puts("Este programa se encarga del manejo de claves");
    do  {
        puts("Por favor, ingrese una de las siguientes opciones.");
        puts(" 1  Ingresar una clave.");
        puts(" 2  Verificar si una clave esta o no.");
        puts(" 3  Chequea que la cantidad de claves ingresadas es correcta.");
        puts(" 4  Determina la cantidad de claves que coinciden con un prefijo.");
        puts(" S  Salir del programa");
        fputs("\t\t>  ",stdout);
        choice = getchar();
        system("cls");
        fflush(stdin);
        switch(choice)
        {
            case '1':
                puts("Ingrese la clave a poner: ");
                fputs("\t\t>  ",stdout);
                gets(string);
                trieInsertKey(myTrie, string);
                break;
            case '2':
                puts("Ingrese la clave a buscar: ");
                fputs("\t\t>  ",stdout);
                gets(string);
                printf("\nLa clave \"%s\" es %s\n", string, (trieExistKey(myTrie, string)?"VALIDA":"INVALIDA"));
                break;
            case '3':
                printf("La cantidad de claves ingresadas y la cantidad de claves del trie %s discrepan\n",
                       (trieCheck(myTrie)?"NO":"SI"));
                break;
            case '4':
                puts("Ingrese el prefijo a buscar ");
                fputs("\t\t>  ",stdout);
                gets(string);
                printf("Existen %d claves con el prefijo \"%s\"\n", trieNumWordsWithPrefix(myTrie, string),string);
                break;
        }
        fflush(stdin);
        puts("\nExito, presione una tecla para continuar");
        getchar();
        system("cls");

    } while(choice!='s' && choice!='S' );
    trieDestroy(myTrie);
}
