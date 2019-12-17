#include <stdio.h>
/* Realizar un programa que recorra todos los números naturales desde 1 hasta 1000 y calcule e
imprima la suma de todos los múltiplos de 2, 3, 4, y 5 en distintos acumuladores. (Acum2 acumula
la suma de todos los múltiplos de 2, Acum3 acumula la suma de todos los múltiplos de 3, etc.).
*/

int main() {
    int i,j,sum[6];
    for (j=2;j<6;j++)
    {
        for (sum[j]=0, i=1; i<=1000 ;i++)
        {
            if (i%j ==0)
            {
                sum[j]+=i;
            }
        }
    }
    for(j=2; j<6;j++)
    {
        printf("La suma de los numeros hasta 1000 multiplos de %d es: %d\n",j, sum[j]);
    }

}
