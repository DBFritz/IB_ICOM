#ifndef TREE_H
#define TREE_H

typedef struct TNode {
	int cont;
	struct TNode *pLeft;
	struct TNode *pRight;
} *Tree_t;

#define TREE_EMPTY NULL
#define TREE_CONT(t) ((t)->cont)
#define TREE_LEFT(t) ((t)->pLeft)
#define TREE_RIGHT(t) ((t)->pRight)

// retorna la cantidad de nodos del árbol
int TreeNumNodes(Tree_t t);

// retorna verdadero/falso indicando si e existe o nó dentro de t
int TreeIsMember(int e, Tree_t t);

int TreeHeight(Tree_t t);

// función auxiliary para crear un árbol de un solo nodo
Tree_t TreeCreateNode(int e);

// hace insersión ordenada en el árbol
Tree_t TreeInsertOrdered(int e, Tree_t t);

void TreePrint(Tree_t t);

// destruye el árbol, liberando recursos
void TreeDestroy(Tree_t t);

#endif
