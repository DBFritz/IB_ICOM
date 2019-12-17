#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void hanoi(int n, int from, int to, int aux)
{
    if (n==1)
    {
        printf("de %d a %d\n", from, to);
        return;
    }
    hanoi(n-1, from, aux, to);
    hanoi(1, from, to, aux);
    hanoi(n-1, aux, to, from);
}

int main()
{
    int n;
    printf("Ingrese la cantidad de pilas que tiene la torre:\t");
    scanf("%d",&n);
    hanoi(n,1,3,2);
    return 0;
}
