#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/*
int main(){
    int i;
    float min= -1, max=1;
    double random;
    for(i=0;i<1000;i++){
        random = (double)rand()/RAND_MAX;
        random *= (max-min);
        random += min;
        printf("%f\n", random);
    }
    return 0;
}
*/
double randomize(double min, double max, int resolution)
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

float mod(float x, float y)
{
    return sqrt(x*x+y*y);
}

int main()
{
    float x,y;
    int N1=0, N, i;
    printf("ingrese la cantidad de Iteraciones que desea realizar: ");
    scanf("%d",&N);
    for(i=0; i<N; i++)
    {
        x=randomize(-1,1,1000);
        y=randomize(-1,1,1000);
        if (mod(x,y)<1)
        {
            N1++;
        }
    }
    printf("El valor de pi calculado fue: %f", 4*(float)N1/N);
}
