#include <stdio.h>
#include <stdlib.h>

void Replace(char s[],const char nuevo,const char viejo)
{
    // Voy a aumentar el índice antes de evaluarlo
    int i=-1;
    while(s[++i]!=0)
    {
        if (s[i]==viejo)
        {
            s[i]=nuevo;
        }
    }
}

int StrLen(const char string[])
{
    int i=-1;
    // Barro hasta que me encuentre el final del string (\0)
    while (string[++i]!=0);
    return i;
}

int StrCmp(const char str1[],const char str2[])
{
    int i = 0;
    //Voy a comparar char por char hasta que: sean distintos, o uno de los strings haya terminado.
    while ((str1[i]!=str2[i])&&(str1[i]!=0||str2[i]!=0));
    return (int)(str1[i]-str2[i]);
}

void StrCat(char destino[], const char concatenar[])
{
    int i=-1, length = StrLen(destino);
    while (concatenar[++i]!=0)
    {
        destino[i + length] = concatenar[i];
    }
    destino[i+length] = 0;
}

int StrStr(const char buscando[],const char busqueda[])
{
    int i = -1,j, lenBusqueda, coincide = 0, ubicacion = -1;
    lenBusqueda = StrLen(busqueda);
    while (buscando[++i]!=0 && !coincide)
    {
        if (buscando[i]==busqueda[0])
        {
            coincide = 1;
            ubicacion = i;
            j=0;
            while (busqueda[++j]!=0 && coincide)
            {
                if (buscando[i+j]!=busqueda[j])
                {
                    coincide = 0;
                    ubicacion = -1;
                }
            }
        }

    }
    return ubicacion;
}


int EsPalindromo(char string[])
{
    int i,j, largo = StrLen(string), medioLargo = largo /2;
    for (i=0,j=largo;i<medioLargo;i++,j--)
    {
        //No quiero comparar espacios ni caracteres raros, entonce si me lo encuentro, me los salteo.
        while (!(('a'<=string[i] && string[i]<'z')||
               ('A'<=string[i] && string[i]<'Z')||
               ('0'<=string[i] && string[i]<'9'))) i++;
        while (!(('a'<=string[j] && string[j]<'z')||
               ('A'<=string[j] && string[j]<'Z')||
               ('0'<=string[j] && string[j]<'9'))) j--;

        //Si encuentro que los caracteres no son iguales, entonces ya no es palindromo
        if ((string[i]!=string[j]) && ((string[i]-'A'+'a')!=string[j]) && ((string[i]+'A'-'a')!=string[j]))
        {
            return 0;
        }
    }
    return 1;
}

void LeftTrim(char phrase[])
{
    int espacios=0, i=-1, len=StrLen(phrase);
    while (phrase[++i]==' ') espacios++;
    for(;i<=len;i++)
    {
        phrase[i-espacios]=phrase[i];
    }
}

int main()
{
    char stringRandom[128] = "Me pegue alta fiesta";
    printf("Si cambio 'f' por 's' en la frase \"%s\" queda:\n\t ",stringRandom);
    Replace(stringRandom, 's', 'f');
    puts(stringRandom);
    printf("\nEl string de recien tiene %d caracteres\n\n",StrLen(stringRandom));
    StrCat(stringRandom, " jojo");
    puts(stringRandom);
    printf("\n\nSi busco en la frase \"Tu mama es mi novia\", la frase \"mama\" empieza en la letra %d",
           StrStr("Tu mama es mi novia", "mama"));
    puts("\n\nDecime una frase: ");
    gets(stringRandom);
    printf("La frase %s %s es un palindromo\n\n", stringRandom, (EsPalindromo(stringRandom))?"SI":"NO");
    printf("Sacale los espacios a esta frase:\n");
    gets(stringRandom);
    LeftTrim(stringRandom);
    puts(stringRandom);
    return 0;
}
