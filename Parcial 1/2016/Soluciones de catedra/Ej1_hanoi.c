#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char pop(char torre[]);
void push(char torre[],char disco);
void print_hanoi(char A[], char B[], char C[]);

void hanoi(int n, char from[], char aux[], char to[]) {
    static int nmvs=0;
    static int nextprint = 2;
    if( n == 1 ) {
        nmvs++;
        
        // Esto pone en el tope de la torre to 
        // el disco que remueve del tope de la torre from
        push(to,pop(from)); 
        
        if (nmvs == nextprint-1)
        {
            printf("\n\nNumero de Movimientos = %d\n",nmvs);
            print_hanoi(from,aux,to);
            nextprint <<= 1;
        }
        return;
    }

    hanoi(n-1, from, to, aux);
    hanoi(1, from, aux, to);
    hanoi(n-1, aux, from, to);
}

int main() {
    char A[13]="A:9876543210";
    char B[13]="B:";
    char C[13]="C:";

	puts("Asi comienzan las torres");
    print_hanoi(A,B,C);
    hanoi(10, A, B, C);
    return 0;
}

char pop(char torre[])
{
    char disco = torre[strlen(torre)-1];
    torre[strlen(torre)-1]=0;
    return disco;
}

void push(char torre[],char disco)
{
    torre[strlen(torre)] = disco;
}


void print_hanoi(char A[], char B[], char C[])
{
    puts(A);
    puts(B);
    puts(C);
    return;
}
