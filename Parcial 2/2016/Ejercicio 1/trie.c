#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <ctype.h>

#include "trie.h"

// función auxiliar: retorna el indice que le corresponde a un caracter dado
static int getIndexForChar(int c)
{
    int ret = toupper(c) - 'A';     //  calcula el indice pasando la letra a mayúscula
    assert(ret < ALPHABET_SIZE);
    return ret;
}

// función auxiliar: retorna el caracter que le corresponde a un indice dado
static int getCharForIndex(int i)
{
    assert(i >= 0 && i < ALPHABET_SIZE);
    return i + 'A';
}

// función auxiliar: crea un Trie_node_t vacío
static Trie_node_t *createNode(void)
{
    Trie_node_t *pNode;
    int i;

    pNode = (Trie_node_t *)malloc(sizeof(Trie_node_t));
    assert(pNode);

    pNode->defineKey = FALSE;

    for(i = 0; i < ALPHABET_SIZE; i++)
        pNode->children[i] = NULL;

    return pNode;
}

// función auxiliar: busca el nodo que termina de definir 'prefix'
// pone el nodo resultado en *pNode (NULL si el 'prefix' no existe)
static void trieSearchKey(const Trie_t *pTrie, const char prefix[], Trie_node_t **ppNode)
{
    int level;
    int length = strlen(prefix);

    *ppNode = pTrie->root;

    for( level = 0; (*ppNode) && level < length; level++ )
        (*ppNode) = (*ppNode)->children[getIndexForChar(prefix[level])];
}

// función auxiliar: destruye en forma recursiva un Trie_node_t
static void trieDestroyNodes(Trie_node_t *pNode)
{
    if(pNode) {
        int i;
        for(i = 0; i < ALPHABET_SIZE; i++)
            trieDestroyNodes(pNode->children[i]);
        free(pNode);
    }
}

// función auxiliar: retorna la cantidad de claves abajo del pNode (cuenta pNode si es clave)
static int trieNumKeys(Trie_node_t *pNode)
{
    int ret = 0;
    if(pNode) {
        int i;
        if(pNode->defineKey)
            ret = 1;
        for(i = 0; i < ALPHABET_SIZE; i++)
            ret += trieNumKeys(pNode->children[i]);
    }
    return ret;
}

///////////////////////////////////////////
// funciones de la interface
///////////////////////////////////////////

// crea un trie vacío
Trie_t *trieCreate()
{
    Trie_t *nt = (Trie_t *) malloc(sizeof(Trie_t));
    assert(nt);

    nt->root = createNode();
    nt->numKeys = 0;
    return nt;
}

// destruye un trie
void trieDestroy(Trie_t *pTrie)
{
    int i;
    trieDestroyNodes(pTrie->root);
    free(pTrie);
}

// agrega una nueva clave
void trieInsertKey(Trie_t *pTrie, const char key[])
{
    int level;
    int length = strlen(key);
    int index;
    Trie_node_t *pCursor;

    pCursor = pTrie->root;

    // va recorriendo el prefix, creando nodos si es necesario
    for( level = 0; level < length; level++ ) {
        index = getIndexForChar(key[level]);
        if( !pCursor->children[index] )
            pCursor->children[index] = createNode();

        pCursor = pCursor->children[index];
    }
    // marca defineKey en el ultimo valor de pCursor si es que no estaba ya definido como clave
    if( pCursor->defineKey == FALSE) {
        pCursor->defineKey = TRUE;
        pTrie->numKeys++;   // aumento la cantidad de claves del trie
    }
}

// retorna verdadero/falso indicando si la clave ya existe en el trie
BOOL trieExistKey(Trie_t *pTrie, const char key[])
{
    Trie_node_t *keyNode;
    trieSearchKey(pTrie, key, &keyNode);
    if(keyNode && keyNode->defineKey)
        return TRUE;
    return FALSE;
}

// chequea la consistencia de un trie
BOOL trieCheck(Trie_t *pTrie)
{
    int nk = trieNumKeys(pTrie->root);
    return nk == pTrie->numKeys;
}

// retorna la cantidad de claves  que comparten un prefix
int trieNumWordsWithPrefix(Trie_t *pTrie, const char *prefix)
{
    Trie_node_t *keyNode;
    trieSearchKey(pTrie, prefix, &keyNode);
    return trieNumKeys(keyNode);
}


