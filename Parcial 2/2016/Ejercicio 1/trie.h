typedef enum { FALSE, TRUE } BOOL;

#define ALPHABET_SIZE 26

typedef struct trie_node {
    BOOL defineKey;    		                        // true/false si define o no una clave
    struct trie_node *children[ALPHABET_SIZE];      // puntero a los hijos de este prefix
} Trie_node_t;

typedef struct {
    Trie_node_t *root;		// contenedor real de datos
    unsigned int numKeys;	// número de claves en el trie
} Trie_t;

// chequea la consistencia de un trie
Trie_t *trieCreate();

// chequea la consistencia de un trie
void trieDestroy(Trie_t *pTrie);

// chequea la consistencia de un trie
void trieInsertKey(Trie_t *pTrie, const char key[]);

// chequea la consistencia de un trie
BOOL trieExistKey(Trie_t *pTrie, const char key[]);

// chequea la consistencia de un trie
BOOL trieCheck(Trie_t *pTrie);

// retorna la cantidad de claves  que comparten un prefix
int trieNumWordsWithPrefix(Trie_t *pTrie, const char *prefix);
