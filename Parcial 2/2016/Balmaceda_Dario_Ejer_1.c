/////////////////////////////////////////////////////////////////////////////////////
// parte a)
void trieGetEnabledKeys(const Trie_t *trie, const char *prefix, int enabledKeys[ALPHABET_SIZE])
{
    int i;
    Trie_node_t *keyNode;
    trieSearchKey(trie, prefix, &keyNode);  // obtengo acceso al keyNode que termina de definir prefix
    assert(keyNode);    // nunca debería parar por una situación de un prefix no existente.
                        // se podría poner todo enabledKeys en 0
    for( i = 0; i <  ALPHABET_SIZE; i++)
        enabledKeys[i] = keyNode->children[i] ? 1 : 0;    // habilito/deshabilito teclas de acuerdo a que existan hijos par ese caracter

}

/////////////////////////////////////////////////////////////////////////////////////
// parte b)
#define MAX_KEY_LEN  32

// lista y manejo elemental de listas (no debería ser parte de lo que se evalúa, ya deberían tener estas funciones).
// hasta se le podrían dar.
typedef struct WordNode {
    char key[MAX_KEY_LEN];
    struct WordNode *pNext;
} *ListWord_t;

ListWord_t listInsertInTail(ListWord_t list, const char *cont)
{
    if(list == NULL) {
        list = (ListWord_t) malloc(sizeof(struct WordNode ));
        assert(list);
        strcpy(list->key, cont);
        list->pNext = NULL;
        return list;
    }
    list->pNext = listInsertInTail(list->pNext, cont);
    return list;
}

void listPrint(ListWord_t list)
{
    while(list) {
        printf("%s\n", list->key);
        list = list->pNext;
    }
}
void listDestroy(ListWord_t list)
{
    while(list) {
        ListWord_t toDelete = list;
        list = list->pNext;
        free(toDelete);
    }
}

// funciones realmente pedidas para la parte b)
ListWord_t trieCollectKeys(Trie_node_t *node, const char *prefix, ListWord_t keyList)
{
    int i;
    if(node->defineKey)
        keyList = listInsertInTail(keyList, prefix);

    for( i = 0; i <  ALPHABET_SIZE; i++) {
        if(node->children[i]) {
            char newPrefix[MAX_KEY_LEN];
            int len = strlen(prefix);
            strcpy(newPrefix, prefix);
            // agrega nuevo caracter al prefix y cierro el string
            newPrefix[len] = getCharForIndex(i);
            newPrefix[len+1] = 0;

            keyList = trieCollectKeys(node->children[i], newPrefix, keyList);
        }
    }

    return keyList;
}

ListWord_t trieGetKeys(const Trie_t *trie, const char *prefix)
{
    Trie_node_t *keyNode;
    int i;

    trieSearchKey(trie, prefix, &keyNode);
    if(keyNode == NULL)
        return NULL;

    return trieCollectKeys(keyNode, prefix, NULL);
}
