#include <stdio.h>
#include <stdlib.h>
#include "tree.h"
#include <string.h>

/****************************************************
 * \brief The size (number of nodes) of a Tree t
 *
 * @param t  Tree to count nodes.
 * @return Number of nodes.
 * @authr Fritz
 ****************************************************/
int TreeNumNodes(Tree_t t)
{
	if(t == TREE_EMPTY)
	return 0;
	return 1 + TreeNumNodes(TREE_LEFT(t))
			+ TreeNumNodes(TREE_RIGHT(t));
}

int TreeIsMember(char * toFind, Tree_t t)
{
	if (t == TREE_EMPTY)
		return 0;
	if (strcmp(TREE_CONT(t),toFind) == 0)
		return 1;
	if ( strcmp(TREE_CONT(t),toFind) > 0)
		return TreeIsMember(toFind, TREE_LEFT(t));
	return TreeIsMember(toFind, TREE_RIGHT(t));
}

int TreeHeight(Tree_t t)
{
	int hl, hr;
	if (t == TREE_EMPTY)
		return 0;
	hl = TreeHeight(TREE_LEFT(t));
	hr = TreeHeight(TREE_RIGHT(t));
	return 1 + ((hl > hr) ? hl : hr);
}

Tree_t TreeCreateNode(char * e)
{
    Tree_t nT = (Tree_t) malloc(sizeof(struct TNode));
    if (nT== NULL) return NULL;
    TREE_CONT(nT) = e;
    TREE_LEFT(nT) = TREE_RIGHT(nT) = TREE_EMPTY;
    return nT;
}

Tree_t TreeInsertOrdered(char * e, Tree_t t)
{
    if(t == TREE_EMPTY)
    return TreeCreateNode(e);
    if(strcmp(TREE_CONT(t),e) >=0)
        TREE_LEFT(t) = TreeInsertOrdered(e, TREE_LEFT(t));
    else
        TREE_RIGHT(t) = TreeInsertOrdered(e, TREE_RIGHT(t));
    return t;
}

void TreePrint(Tree_t t)
{
	if(t == TREE_EMPTY) return;
    TreePrint(TREE_LEFT(t));
    puts(TREE_CONT(t));
    TreePrint(TREE_RIGHT(t));
}

void TreeDestroy(Tree_t t)
{
	if(t != TREE_EMPTY) {
		TreeDestroy(TREE_LEFT(t));
		TreeDestroy(TREE_RIGHT(t));
		free(t);
	}
}

void TreePrintLevel(Tree_t tree, int level)
{
    if (tree== TREE_EMPTY) return;
    if (level == 0) puts(TREE_CONT(tree));
    TreePrintLevel(TREE_LEFT(tree),level-1);
    TreePrintLevel(TREE_RIGHT(tree),level-1);
}

void TreePrintAllLevels(Tree_t tree)
{
    int i;
    for(i=0;i<TreeHeight(tree);i++)
        TreePrintLevel(tree, i);
}

/* QUÉ FEO ESTÁ ESTO, ARREGLAR */
Tree_t TreeMinTree(Tree_t tree, char * a, char * b)
{
    if ((strcmp(TREE_CONT(tree),a) == 0) && (TreeIsMember(b,tree))) return tree;
    if ((strcmp(TREE_CONT(tree),b) == 0) && (TreeIsMember(a,tree))) return tree;
    if ((TreeIsMember(a,TREE_LEFT(tree)) && TreeIsMember(b,TREE_RIGHT(tree)))
        || (TreeIsMember(a,TREE_RIGHT(tree)) && TreeIsMember(b,TREE_LEFT(tree))))
            return tree;
    if ((TreeIsMember(a,TREE_LEFT(tree)) && TreeIsMember(b,TREE_LEFT(tree))))
        return TreeMinTree(TREE_LEFT(tree), a, b);
    if ((TreeIsMember(a,TREE_RIGHT(tree)) && TreeIsMember(b,TREE_RIGHT(tree))))
        return TreeMinTree(TREE_RIGHT(tree), a, b);
    return NULL;
}

int TreeDistanceToRoot(char * toFind, Tree_t t)
{
	if (t == TREE_EMPTY)
		return -1;
	if (strcmp(TREE_CONT(t),toFind) == 0)
		return 0;
	if ( strcmp(TREE_CONT(t),toFind) > 0)
		return 1+TreeDistanceToRoot(toFind, TREE_LEFT(t));
	return 1+TreeDistanceToRoot(toFind, TREE_RIGHT(t));
}
int TreeDistance(Tree_t tree, char * a, char * b)
{
    Tree_t treeMin = TreeMinTree(tree, a, b);
    return (TreeDistanceToRoot(a,treeMin) + TreeDistanceToRoot(b,treeMin));
}
