#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define N 100000

typedef double(*fun_ptr_type)(double);

double integra(double a, double b, fun_ptr_type fun)
{
    double sum, i, h = (b-a) / N;
    sum = (*fun)(a);
    for (i = 1; i < N ; i++)
    {
        sum += 2* (*fun)(a+i*h);
    }
    sum+=(*fun)(b);
    return h*sum/2;
}

double identity(double t)
{
    return t;
}

double quad(double t)
{
    return t*t;
}

int main()
{
    printf("%lf", integra(0,M_PI,sin));
    return 0;
}
