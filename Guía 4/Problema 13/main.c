#include <stdio.h>
#include <stdlib.h>

typedef struct {
 unsigned char red;
 unsigned char green;
 unsigned char blue;
} RGB;

int compositeColor(RGB color)
{
    int codLed = 0;
    codLed = (color.red) | (color.green << 8) | (color.blue << 16) ;
    return codLed;
}

RGB decompositeColor(int codLed)
{
    RGB led;
    led.blue = (codLed >> 16);
    led.green = (codLed >> 8) % 256;
    led.red = codLed % 256;
    return led;
}

int main()
{
    RGB led;
    int codLed,i;
    char ch;
    do {
        printf("Ingrese la opcion:\n1)Descomponer LED.\n2)Componer LED\ns) Salir\n\t> ");
        fflush(stdin);
        ch = getchar();
        switch (ch) {
            case '1':
                printf("Ingrese el valor del color rojo: ");
                scanf("%d",&led.red);
                printf("Ingrese el valor del color verde: ");
                scanf("%d",&led.green);
                printf("Ingrese el valor del color azul: ");
                scanf("%d",&led.blue);
                printf("\nEl codigo del led es: %d", compositeColor(led));
                break;
            case '2':
                printf("Ingrese el valor del codigo del led");
                scanf("%d",&codLed);
                led=decompositeColor(codLed);
                printf("El valor del color rojo: %d", led.red);
                printf("El valor del color verde: %d", led.green);
                printf("El valor del color azul: %d", led.blue);
                break;
            case 's': printf("Saliendo del programa..."); break;
            default: printf("Tecla equivocada");
        }
        for(i=0;i<20;printf("\n"),i++);
    } while (ch!='s');
    return 0;
}
