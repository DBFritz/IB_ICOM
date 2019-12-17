#include <stdio.h>
#include <stdlib.h>

double F2C(double fahr)
{
    return 5*(fahr-32)/9;
}

double C2F(double celsius)
{
    return 9*(celsius)/5+32;
}

int main()
{
    char choice;
    double temp;
    do{
        system("cls");
        printf("Ingrese la unidad de la temperatura a cambiar:\n \tc: Celcius\n\tf: Fahrenheit\n\ts: Salir\n\t> ");
        fflush(stdin);
        choice = getchar();
        switch (choice)
        {
            case 'c':
                printf("\nIngrese la temperatura en Celcius: ");
                scanf("%lf",&temp);
                printf("La temperatura en Fahrenheit es: %lf", C2F(temp));
                break;
            case 'f':
                printf("\nIngrese la temperatura en Fahrenheit: ");
                scanf("%lf",&temp);
                printf("La temperatura en Celsius es: %lf", F2C(temp));
                break;
        }
        fflush(stdin);
        printf("Exito, precione una tecla para continuar.\n");
        getch();
    } while(choice != 's');

    return 0;
}
