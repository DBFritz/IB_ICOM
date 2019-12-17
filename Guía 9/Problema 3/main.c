#include <stdio.h>
#include <stdlib.h>

int CompareStrings(const char *str1, const char *str2)
{
    int i = 0;
    while(str1[i]==str2[i] && str1[i] && str2[i])
    i++;
    return (str1[i]-str2[i]);
}

int main()
{
    printf("Hello world!\n");
    return 0;
}
