/* El problema del cumplea�os est� relacionado con cu�l es la probabilidad de que en un
grupo de personas haya al menos dos que cumplan a�os el mismo d�a. Se sabe que si
en una misma sala si hay 23 personas reunidas, la probabilidad es del 50,7%. Para 57
o m�s personas la probabilidad es mayor del 99%. Si bien esto se puede deducir de
manera anal�tica, es posible hacer una comprobaci�n emp�rica. Para eso, considere
1000 grupos de un tama�o fijo de personas, tomando sus fechas de nacimiento al azar
y analice en cu�ntos casos al menos dos personas cumplen el mismo d�a. Los tama�os
de los grupos deben tomarse entre 10 y 60, aumentando de a 10. Hacer una tabla que
indique la probabilidad en funci�n del tama�o de grupo. V�lgase de funciones para
descomponer el problema en sub-problemas.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void creaCumples(int * cumple, int cantidad)
{
    int i;
    for (i=0;i<cantidad;i++)
    {
        cumple[i] = rand()%365;
    }
}

int esPosta(int * cumple, int cantidad)
{
    int i,j;
    for(i=0;i<cantidad-1;i++)
    {
        for(j=i+1;j<cantidad;j++)
        {
            if (cumple[i]==cumple[j])
                return 1;
        }
    }
    return 0;
}

int main()
{
    srand(time(NULL));
    int i, grupos, cantidad, aciertos;
    int * cumple;
    printf("Ingrese la cantidad de grupos que desea analizar: ");
    scanf("%d",&grupos);
    do {
        printf("Ingrese la cantidad de personas a tomar (0 para salir): ");
        scanf("%d",&cantidad);
        if (cantidad<=0) continue;
        aciertos=0;
        for(i=0;i<grupos;i++)
        {
            cumple = (int *)malloc(cantidad*sizeof(int));
            creaCumples(cumple,cantidad);
            aciertos += esPosta(cumple, cantidad);
            free(cumple);
        }
        printf("\nLa probabilidad de que entre %d personas randoms,\ndos cumplan el mismo dia es de %f",
               cantidad, 100.0*aciertos/grupos);
        printf("\n\nPresione una tecla para continuar...");
        getch();
        system("cls");
    }while(cantidad>0);

    return 0;
}
