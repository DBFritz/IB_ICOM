#include <stdio.h>
#include <stdlib.h>

void muestraBase(int nro, int base)
{
    if (nro==0) return;
    muestraBase(nro/base, base);
    printf("%x", nro%base);
}

int main()
{
    int nro, base;
    do {
        printf("Escriba el numero para cambiar base:\t");
        scanf("%d", &nro);
        printf("Escriba la nueva base:\t");
        scanf("%d", &base);
        printf("El numero en la nueva base sera:\t");
        muestraBase(nro,base);
        printf("\n\n");
    } while(nro==0);
    return 0;
}
