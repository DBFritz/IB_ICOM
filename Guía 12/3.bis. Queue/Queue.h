#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED

typedef struct {
    unsigned int tail;
    unsigned int head;
    int qSize;
    int * pElements;
} Queue_t;

Queue_t * QueueCreate(int size_queue);

void QueueDestroy(Queue_t * pQueue);

int QueuePut(Queue_t * pQueue, int element);

int QueueGet(Queue_t * pQueue, int *element);

int QueueLen(Queue_t * pQueue);

int QueueIsEmpty(Queue_t * pQueue);
#endif // QUEUE_H_INCLUDED
