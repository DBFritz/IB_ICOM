#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void deleteChar(char * frase, int position)
{
    int i = position;
    while (frase[i+1]!=0){
        frase[i]=frase[i+1];
        i++;
    }
    frase[i]=0;
}

void cutStrings(char * frase, char start, char end)
{
    int i;
    for(i=0;i<strlen(frase);i++)
    {
        if (frase[i]==start)
        {
            while(frase[i]!=end)
            {
                deleteChar(frase, i);
            }
            deleteChar(frase, i);
        }
    }
}

int main()
{
    char frase[1024];
    printf("Ingrese lo que usted desea cortar:\n\t> ");
    gets(frase);
    cutStrings(frase, '(', ')');
    printf("Su frase recortada es:\n");
    puts(frase);

    return 0;
}
