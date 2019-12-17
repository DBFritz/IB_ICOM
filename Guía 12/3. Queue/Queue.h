#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED

typedef struct {
    unsigned int tail;
    unsigned int head;
    int qSize;
    int * pElements;
} Queue_t;

/** \brief Te crea una cola con capacidad para size_queue elementos
 * \param size_queue:   el tama�o m�ximo de la cola
 * \return  la cola constru�da                      */
Queue_t * QueueCreate(int size_queue);

/** \brief Te destruye la cola que quieras.
 * \param pQueue:   a cola a destruir        */
void QueueDestroy(Queue_t * pQueue);

/** \brief Coloca element al final de la cola, siempre y cuando la cola no est� llena
    \param pQueue:      La cola a la cual ponerle el elemento
    \param element:     el elemento al cual asignar el valor de la cola.
    \return el estado de la inserci�n del elemento           */
int QueuePut(Queue_t * pQueue, int element);

/** \brief Saca un elemento de la cola para ponerlo en element,
            siempre y cuando la cola est� no vac�a
    \param pQueue:      La cola del cual extraer el elemento
    \param *element:    el elemento al cual asignar el valor de la cola
    \return el estado de la asignaci�n           */
int QueueGet(Queue_t * pQueue, int *element);

/** \brief Mide el largo de una cola (cantidad de elementos en ella)
    \param pQueue:  La cola a medir el largo
    \return el largo de la cola         */
int QueueLen(Queue_t * pQueue);

/** \brief Determina si la cola est� vac�a
    \param pQueue:  La cola a analizar
    \return 1 si la cola est� vac�a, 0 si no lo est�    */
int QueueIsEmpty(Queue_t * pQueue);

#endif // QUEUE_H_INCLUDED
