#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define MAX_VALUES 500
#define MAX_TERNAS (MAX_VALUES * (MAX_VALUES + 1) / 2)

typedef struct {
    int i;
    int j;
    int v;
} Terna_t;

// arma vector de ternas {i, j, i^3+j^3}
int armaTernas(Terna_t ters[], int cnt, int maxV)
{
    int i, j, k = 0;
    assert(cnt >= maxV * (maxV+1) / 2);
    for (i = 1; i <= maxV; i++) 
        for (j = 1; j <= i; j++) {
            ters[k].i = i;
            ters[k].j = j;
            ters[k++].v = i * i * i + j * j * j;
        }
    return k;
}

static int cmpTerna(const void *p1, const void *p2)
{
    return ((Terna_t *)p1)->v - ((Terna_t *)p2)->v;
}

// ordena vector de ternas con respecto a v
void ordenaTernas(Terna_t ters[], int cnt)
{
    qsort(ters, cnt, sizeof(Terna_t), cmpTerna);
}

/*
void ordenaTernas(Terna_t ters[], int cnt)
{
    int i, j;
    for(i = 0; i < cnt; i++) {
        for(j = 0; j < cnt - 1 - i; j++) {
            if(ters[j].v > ters[j+1].v) {
                Terna_t aux = ters[j];
                ters[j] = ters[j+1];
                ters[j+1] = aux;
            }
        }
    }
}
*/

// retorna el inicio de la terna que define T(n)
int uberIdx(Terna_t ters[], int cnt, int n)
{
    int i;
    for (i = 0; i < cnt - n; i++) 
        if (ters[i].v == ters[i + n - 1].v)
            return i;
    return -1;
}

Terna_t ternas[MAX_TERNAS];

int main(void)
{
    int t1Idx, t2Idx, t3Idx;
    int cnt = armaTernas(ternas, MAX_TERNAS, MAX_VALUES);
    ordenaTernas(ternas, cnt);
    
    t1Idx = uberIdx(ternas, MAX_TERNAS, 1);
    printf("T(1): %d:\t(%d^3 + %d^3)\n", ternas[t1Idx].v, ternas[t1Idx].i, ternas[t1Idx].j);
    
    t2Idx = uberIdx(ternas, MAX_TERNAS, 2);
    printf("T(2): %d:\t(%d^3 + %d^3)\t(%d^3 + %d^3)\n", ternas[t2Idx].v, 
                                                      ternas[t2Idx].i, ternas[t2Idx].j, 
                                                      ternas[t2Idx+1].i, ternas[t2Idx+1].j);
    t3Idx = uberIdx(ternas, MAX_TERNAS, 3);
    printf("T(3): %d:\t(%d^3 + %d^3)\t(%d^3 + %d^3)\t(%d^3 + %d^3)\n", ternas[t3Idx].v, 
                                                                     ternas[t3Idx].i, ternas[t3Idx].j, 
                                                                     ternas[t3Idx + 1].i, ternas[t3Idx + 1].j, 
                                                                     ternas[t3Idx + 2].i, ternas[t3Idx + 2].j);
    return 0;
}

