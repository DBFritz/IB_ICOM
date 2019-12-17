#include <stdio.h>
#include <stdlib.h>

/* La función determina la cantidad de formas de poner
dominos (2x1) en cajitas de 2xN */
int poneDominos(int N)
{
    // casos triviales
    if (N<=2) {
        return N;
    }

    /* Una solución será colocando la primera vertical y las otras como sean
    y la otra colocando las dos primeras horizontales y las otras como sean */
    return poneDominos(N-1)+poneDominos(N-2);
}

int main()
{
    int N;
    printf("Ingrese el ancho de la caja a colocar dominos:\t");
    scanf("%d",&N);
    printf("\nHay %d formas diferentes de colocar %d dominos.\n", poneDominos(N), N);
    return 0;
}
