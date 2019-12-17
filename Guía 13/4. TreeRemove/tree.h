#ifndef TREE_H
#define TREE_H

#define TREE_EMPTY NULL
#define TREE_CONT(t) ((t)->cont)
#define TREE_LEFT(t) ((t)->pLeft)
#define TREE_RIGHT(t) ((t)->pRight)

typedef struct TNode {
	int cont;
	struct TNode *pLeft;
	struct TNode *pRight;
} *Tree_t;

int TreeNumNodes(Tree_t t);

int TreeIsMember(int e, Tree_t t);

int TreeHeight(Tree_t t);

Tree_t TreeCreateNode(int e);

Tree_t TreeInsertOrdered(int e, Tree_t t);

void TreePrint(Tree_t t);


void TreeDestroy(Tree_t t);

#endif
