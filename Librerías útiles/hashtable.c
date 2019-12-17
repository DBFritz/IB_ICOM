#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include "hashtable.h"

int HashCode(char *key)
{
    int code=0;
    while(key!='\0')
    {
        // REGLA MATEMÁTICA PARA ENCRIPTAR
        code = code << 5;
        code = code - code + *key;
        /////////////////////////////////
        key++;
    }
    return code;
}

HashTable_t* CreateHashTable(int size)
{
    int i;
    HashTable_t *pht;
    struct HashNode **lists;

    pht = (HashTable_t*)malloc(sizeof(HashTable_t));

    lists = (struct HashNode**)malloc(sizeof(struct HashNode*)*size);

    pht->size = size;
    pht->lists = lists;

    for (i=0;i<size;i++)
        pht->lists[i]=NULL;

    return(pht);
}

void _DestroyList(HashList_t List)
{
    if (List==NULL)
        return;
    _DestroyList(List->pnext);
    free(List);
}

void DestroyHashTable(HashTable_t *pht)
{
    int i;

    if (pht==NULL)
        return;

    for(i=0; i< pht->size; i++)
        _DestroyList(pht->lists[i]);

    //free(pht->lists); ????
    free(pht);

    return;
}

HashList_t _AddToList(HashList_t list, char *key, char *value)
{
    if (list==NULL) {
        list=(struct HashNode*)malloc(sizeof(struct HashNode));
        list->key = key;
        list->value = value;
        list->pnext = NULL;
        return list;
    }

    if (strcmp(list->key,key)==0) {
        list->value=value;
        return list;
    }

    list->pnext=_AddToList(list->pnext, key, value);
    return list;

}

void AddToHashTable(HashTable_t *pht, char *key, char *value)
{
    int code;
    int offset;
    HashList_t list;

    // Crea el codigo
    code = HashCode(key);

    // pick the linked list
    offset = code % pht->size;
    _AddToList(pht->lists[offset],key,value);
    return;
}

HashList_t   _RemoveFromList (HashList_t list, char *key)
{
    if (list==NULL)
        return list;
    if (strcmp(list->key,key)==0) {
        HashList_t aux=list->pnext;
        free(list->pnext);
        return aux;
    }


    list->pnext=_RemoveFromList(list->pnext, key);
    return list;
}

void RemoveFromHashTable(HashTable_t *pht, char *key)
{
    int code;
    int offset;

    if(pht==NULL)
        return;

    code = HashCode(key);
    offset = code % pht->size;
    pht->lists[offset]=_RemoveFromList(pht->lists[offset], key);
    return;
}

char * _FindInList(HashList_t list, char *key)
{
    if (list==NULL)
        return NULL;
    if (strcmp(list->value,key)==0)
        return list->value;
    return _FindInList(list->pnext, key);
}
char * FindInHashTable(HashTable_t *pht, char *key)
{
    int code;
    int offset;
    struct hLinkedList *list, *prev;

    code = HashCode(key);
    offset = code % pht->size;
    return _FindInList(pht->lists[offset], key);

}

void _PrintList(HashList_t list)
{
    if (list==NULL) {
        printf("\n");
        return;
    }

    printf("%s -> %s ;\t", list->key, list->value);
    _PrintList(list->pnext);
}
void PrintHashTable(HashTable_t *pht)
{
    if (pht==NULL) {
        printf("El Hash Table está vacio\n");
        return;
    }

    int i;
    for (i=0; i<pht->size; i++) {
     printf("Lista %d: ", i);
    _PrintList(pht->lists[i]);
    }
    return;
}
