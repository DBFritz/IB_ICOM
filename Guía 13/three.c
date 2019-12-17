int TreeNumNodes(Tree_t t)
{
	if(t == TREE_EMPTY)
	return 0;
	return 1 + TreeNumNodes(TREE_LEFT(t)) 
			+ TreeNumNodes(TREE_RIGHT(t));
}

// retorna verdadero/falso indicando si e existe o nó dentro de t
int TreeIsMember(int e, Tree_t t)
{
	if (t == TREE_EMPTY)
		return 0;
	if(TREE_CONT(t) == e)
		return 1;
	if( TREE_CONT(t) > e)
		return TreeIsMember(e, TREE_LEFT(t));
	return TreeIsMember(e, TREE_RIGHT(t));
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

// función auxiliary para crear un árbol de un solo nodo
Tree_t TreeCreateNode(int e)
{
Tree_t nT = (Tree_t) malloc(sizeof(struct TNode));
assert(nT);
TREE_CONT(nT) = e;
TREE_LEFT(nT) = TREE_RIGHT(nT) = TREE_EMPTY;
return nT;
}
// hace insersión ordenada en el árbol
Tree_t TreeInsertOrdered(int e, Tree_t t)
{
if(t == TREE_EMPTY)
return TreeCreateNode(e);
if(TREE_CONT(t) >= e)
TREE_LEFT(t) = TreeInsertOrdered(e, TREE_LEFT(t));
else
TREE_RIGHT(t) = TreeInsertOrdered(e, TREE_RIGHT(t));
return t;
}

void TreePrint(Tree_t t)
{
	if(t != TREE_EMPTY) {
		TreePrint(TREE_LEFT(t));
		printf("%d\n", TREE_CONT(t));
		TreePrint(TREE_RIGHT(t));
	}
}

// destruye el árbol, liberando recursos
void TreeDestroy(Tree_t t)
{
	if(t != TREE_EMPTY) {
		TreeDestroy(TREE_LEFT(t));
		TreeDestroy(TREE_RIGHT(t));
		free(t);
	}
}