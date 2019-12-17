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
    return queue;
}

void QueueDestroy(Queue_t * pQueue)
{
    free(pQueue->pElements);
    free(pQueue);
}

int QueuePut(Queue_t * pQueue, int element)
{
    if (QueueLen(pQueue) >= pQueue->qSize) return 0;
    pQueue->pElements[pQueue->tail++ %pQueue->qSize] = element;
    return 1;
}

int QueueGet(Queue_t * pQueue, int *element)
{
    if (QueueLen(pQueue) == 0) return 0;
    *element = pQueue->pElements[pQueue->head++%pQueue->qSize];
    return 1;
}

int QueueLen(Queue_t * pQueue)
{
    return (pQueue->tail - pQueue->head);
}

int QueueIsEmpty(Queue_t * pQueue)
{
    return (pQueue->head == pQueue->tail);
}

