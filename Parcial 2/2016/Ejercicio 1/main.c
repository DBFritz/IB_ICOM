#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <ctype.h>
#include "trie.h"
#define MAX_KEY_LEN 32

typedef struct WordNode {
    char key[MAX_KEY_LEN];
    struct WordNode *pNext;
} *ListWord_t;

void trieGetEnabledKeys(const Trie_t *trie, const char *prefix, int enabledKeys[ALPHABET_SIZE]);

ListWord_t trieGetKeys(const Trie_t *trie, const char *prefix);

void listPrint(ListWord_t lst){
    while(lst) {
        puts(lst->key);
        lst = lst->pNext;
    }
    puts("");
}

void listDestroy(ListWord_t lst){
    if(lst==NULL)
        return;
    listDestroy(lst->pNext);
    free(lst);
}


int main(){
    Trie_t* pTrie=trieCreate();

    FILE *stream = fopen("calles.txt", "r");
    assert(stream != NULL);

    char str[128]={0};

    while (fscanf(stream, "%s", str) == 1) {
        printf(">>%s<<\n", str);
        trieInsertKey(pTrie, str);
    }

    fclose(stream);

    printf("Chequeo: %d\n", trieCheck(pTrie));

    ListWord_t l = trieGetKeys(pTrie, "M");
    printf("\nclaves con M =====>\n");
    listPrint(l);
    listDestroy(l);

    l = trieGetKeys(pTrie, "MO");
    printf("\nclaves con MO =====>\n");
    listPrint(l);
    listDestroy(l);

    l = trieGetKeys(pTrie, "MOR");
    printf("\nclaves con MOR =====>\n");
    listPrint(l);
    listDestroy(l);

    trieDestroy(pTrie);

    return 0;
}

static int getIndexForChar(int c){
    int ret = toupper(c) - 'A';     //  calcula el indice pasando la letra a mayúscula
    assert(ret < ALPHABET_SIZE);
    return ret;
}

static int getCharForIndex(int i){
    assert(i >= 0 && i < ALPHABET_SIZE);
    return i + 'A';
}

static void trieSearchKey(const Trie_t *pTrie, const char prefix[], Trie_node_t **ppNode){
    int level;
    int length = strlen(prefix);

    *ppNode = pTrie->root;

    for( level = 0; (*ppNode) && level < length; level++ )
        (*ppNode) = (*ppNode)->children[getIndexForChar(prefix[level])];
}

void trieGetEnabledKeys(const Trie_t *trie, const char *prefix, int enabledKeys[ALPHABET_SIZE]){
    int i;
    Trie_node_t * trieFinded = NULL;
    trieSearchKey(trie, prefix, &trieFinded);
    if (trieFinded)
        for(i=0;i<ALPHABET_SIZE;i++)
            enabledKeys[i] = (trieFinded->children[i]!=NULL);
    else
        for(i=0;i<ALPHABET_SIZE;i++)
            enabledKeys[i] = 0;
    return;
}

ListWord_t ListNodeCreate(char * e, ListWord_t tail){
    ListWord_t newL = (ListWord_t ) malloc(sizeof(struct WordNode));
    assert(newL);
    strcpy(newL->key,e);
    newL->pNext = tail;
    return newL;
}

static ListWord_t _trieGetKeys(Trie_node_t *trie, const char *prefix, ListWord_t list){
    if (trie == NULL) return list;
    int i;

    if (trie->defineKey)
        list = ListNodeCreate(prefix, list);

    char newPrefix[MAX_KEY_LEN];
    int enabledKeys[ALPHABET_SIZE];

    for(i=0;i<ALPHABET_SIZE;i++)
        enabledKeys[i] = (trie->children[i]!=NULL);

    strcpy(newPrefix, prefix);
    for(i=0;i<ALPHABET_SIZE;i++)
        if (enabledKeys[i])
        {
            newPrefix[strlen(prefix)] = getCharForIndex(i);
            newPrefix[strlen(prefix)+1] = 0;

            list = _trieGetKeys(trie->children[i], newPrefix, list);
        }

    return list;
}

ListWord_t trieGetKeys(const Trie_t *trie, const char *prefix)
{
    Trie_node_t * trieFinded = NULL;
    trieSearchKey(trie, prefix, &trieFinded);
    ListWord_t newList = NULL;
    newList = _trieGetKeys(trieFinded, prefix, newList);
    return newList;
}
