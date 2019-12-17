#include <stdio.h>
#include <stdlib.h>

int main()
{
    int rojo,verde,azul, led=0;
    printf("Ingrese la componente roja: ");
    scanf("%d",&rojo);
    printf("Ingrese la componente verde: ");
    scanf("%d",&verde);
    printf("Ingrese la componente azul: ");
    scanf("%d",&azul);
    led = (rojo) | (azul << 16) | (verde << 8);
    printf("El codigo del led es %x", led);

    printf("\n\nAhora ingrese un codigo de led: ");
    scanf("%x", &led);
    azul= (led >>16);
    verde = (led >> 8) % 256;
    rojo = led % 256;
    printf("El led tiene %d rojo, %d verde y %d azul", rojo, verde, azul);

    return 0;
}
