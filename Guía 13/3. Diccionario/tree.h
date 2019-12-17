#ifndef TREE_H
#define TREE_H

typedef struct TNode {
	const char * cont;
	struct TNode *pLeft;
	struct TNode *pRight;
} *Tree_t;

#define TREE_EMPTY NULL
#define TREE_CONT(t) ((t)->cont)
#define TREE_LEFT(t) ((t)->pLeft)
#define TREE_RIGHT(t) ((t)->pRight)

int TreeNumNodes(Tree_t t);


int TreeIsMember(char * e, Tree_t t);

int TreeHeight(Tree_t t);

Tree_t TreeCreateNode(char * e);

Tree_t TreeInsertOrdered(char * e, Tree_t t);

void TreePrint(Tree_t t);


void TreeDestroy(Tree_t t);

void TreePrintAllLevels(Tree_t Arbol);

void TreePrintLevel(Tree_t Arbol, int level);

Tree_t TreeMinTree(Tree_t tree, char * a, char * b);

int TreeDistanceToRoot(char * toFind, Tree_t t);

int TreeDistance(Tree_t tree, char * a, char * b);

#endif
