#include <stdio.h>
#include <stdlib.h>
#include "three.h"

Tree_t TreeMin(Tree_t tree)
{
    while (TREE_LEFT(tree) != TREE_EMPTY) tree=TREE_LEFT(tree);
    return tree;
}

Tree_t TreeMax(Tree_t tree)
{
    while (TREE_RIGHT(tree) != TREE_EMPTY) tree=TREE_RIGHT(tree);
    return tree;
}

Tree_t TreeFind(int e, Tree_t t)
{
	if (!TreeIsMember(e, t))
		return TREE_EMPTY;
	if(TREE_CONT(t) == e)
		return t;
	if( TREE_CONT(t) > e)
		return TreeFind(e, TREE_LEFT(t));
	return TreeFind(e, TREE_RIGHT(t));
}

/*
void TreeRemoveRoot(Tree_t tree)
{
    if (TREE_LEFT(tree) == TREE_EMPTY && TREE_RIGHT(tree) == TREE_EMPTY)
    {
        TreeDestroy(tree);
        return;
    }
    Tree_t nextTree;
    if (TREE_LEFT(tree) != TREE_EMPTY)
    {
        nextTree = TreeMax(TREE_LEFT(tree));
        TREE_CONT(tree) = TREE_CONT(nextTree);
        TreeRemoveRoot(nextTree);
    }
    else if (TREE_RIGHT(tree) != TREE_EMPTY)
    {
        nextTree = TreeMin(TREE_RIGHT(tree));
        TREE_CONT(tree) = TREE_CONT(nextTree);
        TreeRemoveRoot(nextTree);
    }
    return;
}

Tree_t TreeRemove(Tree_t tree, int e)
{
    TreeRemoveRoot(TreeFind(e, tree));
    return tree;
}
*/

/*
Tree_t TreeRemove(Tree_t tree, int e)
{
    if (!TreeIsMember(e, tree)) return tree;
    Tree_t toRemove = TreeFind(e, tree);
    if (TreeNumNodes(toRemove) == 1)
    {
        toRemove = TREE_EMPTY;
        return tree;
    }
    if (TreeNumNodes(TREE_RIGHT(toRemove)) >0)
    {
        Tree_t treeNext = TreeMin(TREE_RIGHT(toRemove));
        TREE_CONT(toRemove) = TREE_CONT(treeNext);
        TreeRemove(treeNext, TREE_CONT(treeNext));
    }
    else if (TreeNumNodes(TREE_LEFT(toRemove)) >0)
    {
        Tree_t treeNext = TreeMax(TREE_LEFT(toRemove));
        TREE_CONT(toRemove) = TREE_CONT(treeNext);
        TreeRemove(treeNext, TREE_CONT(treeNext));
    }
    return tree;
}*/

void TreePrintLevel(Tree_t tree, int level)
{
    if (tree== TREE_EMPTY) return;
    if (level == 0) printf("%d\t", TREE_CONT(tree));
    TreePrintLevel(TREE_LEFT(tree),level-1);
    TreePrintLevel(TREE_RIGHT(tree),level-1);
}

void TreePrintAllLevels(Tree_t tree)
{
    int i;
    for(i=0;i<TreeHeight(tree);i++)
    {
        TreePrintLevel(tree, i);
        putchar('\n');
    }
}

int main()
{
    Tree_t arbolito = TREE_EMPTY;
    int i, ordenes[] = {13, 6, 2, 1, 5, 3, 4, 10, 7, 9, 8, 11, 12};
    for (i=0;i<13;i++)
    {
        arbolito = TreeInsertOrdered(ordenes[i], arbolito);
    }
    TreePrintAllLevels(arbolito);
    TreeRemove(arbolito, 6);
    putchar('\n');
    TreePrintAllLevels(arbolito);
}
