#ifndef TRIE_H_INCLUDED
#define TRIE_H_INCLUDED

typedef enum { FALSE, TRUE } BOOL;

#define ALPHABET_SIZE 26

typedef struct trie_node {
    BOOL isKey;             // true/false si define o no una clave
    struct trie_node *children[ALPHABET_SIZE];
} Trie_node_t;

typedef struct {
    Trie_node_t *root;      // contenedor real de datos
    unsigned int numKeys;   // número de claves en el trie
} Trie_t;




Trie_t *trieCreate();

// inserta una nueva clave si no está presente o
// lo marca con defineKey si ya existía como prefix de otras claves
void trieInsertKey(Trie_t *pTrie, const char *key);

// retorna verdadero/falso indicando si la clave existe.
BOOL trieExistKey(Trie_t *pTrie, const char *key);

// Chequea la consistencia entre la cantidad de nodos que dice el
// trie y la cantidad de nodos que definen key.
// Retorna TRUE/FALSE indicando si hay o nó consistencia.
BOOL trieCheck(Trie_t *pTrie);

// Retorna la cantidad de claves que tienen un prefix determinado.
int trieNumWordsWithPrefix(Trie_t *pTrie, const char *prefix);

// destruye un trie liberando todos los recursos alocados
void trieDestroy(Trie_t *pTrie);

#endif // TRIE_H_INCLUDED
