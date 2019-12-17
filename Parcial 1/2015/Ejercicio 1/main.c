#include <stdio.h>
#include <stdlib.h>

int cbu_check(char cbu[])
{
    int i=0, Bloque1[8], Bloque2[14],sum=0;
    int pesos[] = {7,1,3,9};
     for(i=0;i<8;i++)
    {
        Bloque1[i]= (int)(cbu[i+9] - '0');
    }
    for(i=0;i<14;i++)
    {
        // Identificando Cuenta
        Bloque2[i] = (int)(cbu[i+9] - '0');
    }

    // Validando Primer Bloque
    for(i=0;i<7;i++)
    {
        sum+=Bloque1[i]+pesos[i%4];
    }
    //Si no es válido el bloque1, el cbu no es válido
    if ((10-sum%10)!=Bloque1[8]) return 0;
    sum=0;

    //Valido el otro bloque
    for(i=0;i<14;i++)
    {
        sum+=Bloque2[i]+pesos[(i+2)%4];
    }

    return ((10-sum%10)!=Bloque2[14]);
}

int main()
{
    char cbu[23];
    FILE * file;
    if ((file = fopen("cbu.txt", "rt"))!=NULL)
    {
        fgets(cbu,23,file);
    } else {
        fprintf(stderr,"No se leyo cbu.txt, se leera cbu por teclado: \n\t> ");
        gets(cbu);
    }

    printf("El CBU es %s", (cbu_check(cbu)?"valido":"invalido"));
    getchar();
}
