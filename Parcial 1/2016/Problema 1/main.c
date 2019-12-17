#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void muestraHanoi(char from[], char aux[], char to[])
{
    puts(from);
    puts(aux);
    puts(to);
    putchar('\n');
}
void mueveFicha(char from[], char to[])
{
    int largoFrom = strlen(from);
    int largoTo = strlen(to);
    to[largoTo]=from[largoFrom-1];
    from[largoFrom-1] = 0;
    to[largoTo+1]=0;
}

int esCasiPot2(int n)
{
    int i = 1;
    while(i-1<=n)
    {
        if (n==i-1)
        {
            return 1;
        }
        i*=2;
    }
    return 0;
}

void hanoi(int n, char from[], char to[], char aux[])
{
    static int moves = 0;
    if (n==1)
    {
        moves++;
        mueveFicha(from, to);
        if (esCasiPot2(moves))
        {
            muestraHanoi(from,aux,to);
        }
        return;
    }
    hanoi(n-1, from, aux, to);
    hanoi(1, from, to, aux);
    hanoi(n-1, aux, to, from);
}

int main()
{
    char A[13] = "A:9876543210";
    char B[13] = "B:";
    char C[13] = "C:";
    puts("Torre de Hanoi antes:");
    muestraHanoi(A, B, C);
    puts("Moviendo:");
    hanoi(10, A, C, B);
    puts("Torre de Hanoi al final:");
    muestraHanoi(A, B, C);
    return 0;
}
