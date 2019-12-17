#include <stdio.h>
#include <stdlib.h>

/// De forma iterativa
int esDivisiblePor7i(int nro)
{
    int cifra;
    while (nro>10)
    {
        cifra = nro%10;
        nro /= 10;
        nro -= 2*cifra;
    }
    return (nro==0 || nro==7 || nro==-7);
}

/// De forma  recursiva
int esDivisiblePor7(int nro)
{
    if (nro/100==0) return (nro==0 || nro==7 || nro==-7);
    return esDivisiblePor7(nro/10-2*(nro%10));
}

int main()
{
    int nro;
    do {
        scanf("%d", &nro);
        printf("El numero %d %s es multiplo de 7\n", nro, (esDivisiblePor7(nro))?"SI":"NO");
    } while (nro!=0);
    return 0;
}
