#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

int main()
{
    Tree_t arbolito = TREE_EMPTY;
    arbolito = TreeInsertOrdered("e", arbolito);
    arbolito = TreeInsertOrdered("c", arbolito);
    arbolito = TreeInsertOrdered("d", arbolito);
    arbolito = TreeInsertOrdered("a", arbolito);
    arbolito = TreeInsertOrdered("b", arbolito);
    arbolito = TreeInsertOrdered("k", arbolito);
    arbolito = TreeInsertOrdered("i", arbolito);
    arbolito = TreeInsertOrdered("m", arbolito);
    arbolito = TreeInsertOrdered("z", arbolito);
    return 0;
}
