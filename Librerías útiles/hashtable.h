
#ifndef algo
#define algo

// Nodo de lista
typedef struct HashNode
{
    char *key;
    char *value;
    struct HashNode *pnext;
} *HashList_t;

// Hashtable
typedef struct HashTable
{
    int size;
    struct HashNode **lists;
} HashTable_t;

//Crea un hash para un nombre
int HashCode(char *key);

// Crea un HashTable
HashTable_t* CreateHashTable(int size);

// Destruye el hash table
void DestroyHashTable(HashTable_t * pht);
void _DestroyList(HashList_t List);

// Agrega un string a la ht
HashList_t _AddToList(HashList_t list, char *key, char *value);
void AddToHashTable(HashTable_t *pht, char *key, char *value);

// Remueve un String de la ht
HashList_t   _RemoveFromList (HashList_t list, char *key);
void RemoveFromHashTable(HashTable_t *pht, char *key);

// Busca un key en la ht y retorna un puntero al value
char * _FindInList(HashList_t list, char *key);
char * FindInHashTable(HashTable_t *pht, char *key);

// imprime la ht
void PrintHashTable(HashTable_t *pht);

#endif
