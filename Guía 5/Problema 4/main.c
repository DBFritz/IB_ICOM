#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int mintoMAY(char * frase)
{
    int i;
    for (i=0;i<strlen(frase);i++)
    {
        if ('a'<=frase[i] && frase[i]<='z')
        {
            frase[i]-=32;
        }
    }
}

int main()
{
    char frase[1024];
    printf("Ingrese lo que usted quiere gritar:\n\t> ");
    gets(frase);
    mintoMAY(frase);
    printf("Usted quiso decir:\n");
    puts(frase);

    return 0;
}
