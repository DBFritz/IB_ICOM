#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define PI 3.14159265358979323846

double randomize(double min, double max)
{
    static int seed = 0;
    double random;
    if (!seed)
    {
        srand((unsigned int)time(NULL));
        seed=1;
    }
    random = (double)rand()/RAND_MAX;
    random *= (max-min);
    random += min;
    return random;
}

int main()
{
    int i, N, A=0;
    float y, theta;
    printf("Ingrese la cantidad de Iteraciones: ");
    scanf("%d",&N);
    for(i=0;i<N;i++)
    {
        y=randomize(0,1);
        theta=randomize(0,2*PI);
        if(y+sin(theta)<0 || y+sin(theta)>1)
        {
            A++;
        }
    }
    printf("El valor de pi, con %d iteraciones es: %f",N,2*(float)N/A);
    return 0;
}
