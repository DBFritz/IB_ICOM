#include <stdio.h>
#include <stdlib.h>
#include "trie.h"



static int toInt(char letra)
{
    if ('a' <= letra && letra <= 'z')
        return (letra-'a');
    else if ('A' <= letra && letra <= 'Z')
        return (letra-'A');
    return -1;

}

Trie_t * trieCreate()
{
    int i;
    Trie_t * newTrie = (Trie_t *) malloc(sizeof(Trie_t));
    if (newTrie == NULL) return NULL;

    newTrie->root = (Trie_node_t *) malloc (sizeof(Trie_node_t));

    if (newTrie->root == NULL)
    {
        free(newTrie);
        return NULL;
    }

    newTrie->root->isKey = FALSE;
    for(i=0;i<ALPHABET_SIZE;i++)
    {
        newTrie->root->children[i] = NULL;
    }

    newTrie->numKeys=0;
    return newTrie;
}

static void __insertKey(Trie_node_t *root, const char * key)
{
    int i;
    if (!*key)
    {
        root->isKey = TRUE;
        return;
    }
    if (root->children[toInt(*key)] == NULL)
    {
        root->children[toInt(*key)] = (Trie_node_t *)malloc(sizeof(Trie_node_t));
        root->children[toInt(*key)]->isKey = FALSE;
        for (i=0;i<ALPHABET_SIZE;i++)
            root->children[toInt(*key)]->children[i] = NULL;
    }
    __insertKey(root->children[toInt(*key)], key+1);
    return;
}

void trieInsertKey(Trie_t * pTrie, const char * key)
{
    pTrie->numKeys++;
    __insertKey(pTrie->root, key);
}

static BOOL __existKey(Trie_node_t *root, const char * key)
{
    if (root == NULL) return FALSE;
    if (!*key)
    {
        return root->isKey;
    }
    return __existKey(root->children[toInt(*key)], key+1);
}

BOOL trieExistKey(Trie_t *pTrie, const char *key)
{
    return __existKey(pTrie->root, key);
}

unsigned int trieKeysCount(Trie_node_t * root)
{
    if(root==NULL) return 0;
    int i;
    unsigned int numKeys = root->isKey;
    for(i=0;i<ALPHABET_SIZE;i++)
    {
        numKeys += trieKeysCount(root->children[i]);
    }
    return  numKeys;
}

BOOL trieCheck(Trie_t *pTrie)
{
    return (trieKeysCount(pTrie->root) == pTrie->numKeys);
}

Trie_node_t * trieFindNode(Trie_node_t * root, const char *prefix)
{
    if (root == NULL)   return NULL;
    if (!*prefix)       return root;
    return trieFindNode(root->children[toInt(*prefix)],prefix+1);
}

int trieNumWordsWithPrefix(Trie_t *pTrie, const char *prefix)
{
    return trieKeysCount(trieFindNode(pTrie->root, prefix));
}

void trieDestroyNode(Trie_node_t * root)
{
    if (root != NULL)
    {
        int i;
        for(i=0;i<ALPHABET_SIZE;i++)
        {
            trieDestroyNode(root->children[i]);
        }
    }
    free(root);
}

void trieDestroy(Trie_t * pTrie)
{
    trieDestroyNode(pTrie->root);
    free(pTrie);
}


