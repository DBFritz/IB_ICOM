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

/** \brief Retorna la cantidad de nodos de un árbol
    \param  t:  El arbol del cual contar la cantidad de nodos.
    \return La cantidad de nodos del árbol.                         */
int TreeNumNodes(Tree_t t);

/** \brief Averigua si el string e pertenece al árbol (ordenado) t
    \param  e:  el string a buscar
    \param  t:  el arbol en el cual buscar el string e
    \return TRUE si el e pertenece a t, FALSE si no pertenece.      */
int TreeIsMember(char * e, Tree_t t);

/** \brief Calcula y devuelve la cantidad de niveles de un árbol.
    \param  t:  el arbol del cual averiguar la altura
    \return La altura del árbol     */
int TreeHeight(Tree_t t);

/** \brief Función auxiliar para crear un árbol de un sólo nodo
    \param  e:  el string de la raiz del árbol
    \return El árbol creado    */
Tree_t TreeCreateNode(char * e);

/** \brief Inserta el string e ordenadamente en el árbol t
    \param  e:  el string a insertar
    \param  t:  el árbol a colocar
    \return El árbol con su string ya colocado*/
Tree_t TreeInsertOrdered(char * e, Tree_t t);

/** \brief Imprime el árbol t inOrder
    \param  t:  el árbol a imprimir     */
void TreePrint(Tree_t t);

/** \brief Hace madera con el árbol t.
    \param  t:  El árbol a talar        */
void TreeDestroy(Tree_t t);

#endif
