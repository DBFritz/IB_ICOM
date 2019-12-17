#include "Queue.h"
#include <stdlib.h>
#include <stdio.h>

Queue_t * QueueCreate(int size_queue)
{
    Queue_t * queue = (Queue_t *)malloc(sizeof(Queue_t));
    if (queue == NULL)
    {
        return NULL;
    }
    queue->pElements = (int *)malloc(size_queue*sizeof(int));
    if (queue->pElements == NULL)
    {
        free(queue);
        return NULL;
    }
    queue->qSize = size_queue;
    queue->head = 0;
    queue->tail = 0;
}

void QueueDestroy(Queue_t * pQueue)
{
    free(pQueue->pElements);
    free(pQueue);
}

int QueuePut(Queue_t * pQueue, int element)
{
    if (QueueLen(pQueue) >= (pQueue->qSize-1)) return 0;
    pQueue->pElements[pQueue->tail++]=element;
    pQueue->tail%=pQueue->qSize;
    return 1;
}

int QueueGet(Queue_t * pQueue, int *element)
{
    if (QueueIsEmpty(pQueue)) return 0;
    *element = pQueue->pElements[pQueue->head++];
    pQueue->head%=pQueue->qSize;
    return 1;
}

int QueueLen(Queue_t * pQueue)
{
    if (pQueue->head <= pQueue->tail)
        return (pQueue->head - pQueue->tail);
    return (pQueue->qSize - pQueue->head + pQueue->tail);
}

int QueueIsEmpty(Queue_t * pQueue)
{
    return (pQueue->head == pQueue->tail);
}

