// Busca una Persona por DNI
int BuscaPersona(ArbolGen_t a, int dni){
	if (a==NULL)
		return 0;

	if (a->pers->dni == dni)
        return 1;

// Como no es un diccionario, debo buscar en todo el arbol
	if( BuscaPersona(a->padre,dni) || BuscaPersona(a->madre,dni) )
        return 1;

    return 0;
}

// Si encuentra a la persona en el arbol, retorna verdadero y 
// pone en *nivel el nivel donde se encuentra una persona en el arbol
// sino retorna falso y no modifica *nivel.
int NivelPersona(ArbolGen_t a, int dni, int * nivel){
	if (a==NULL)
		return 0;

	if (a->pers->dni == dni)
    {
        *nivel = 0;
        return 1;
    }

	if( NivelPersona(a->padre,dni,nivel) || NivelPersona(a->madre,dni,nivel) )
    {
        (*nivel)++;
        return 1;
    }
    return 0;
}

// Agrega a la lista que se le passa todos los ancestros comunes que encuentra 
// entre los arboles a y b. Es recursiva.
List_t ListaAncestrosComunes(ArbolGen_t a, ArbolGen_t b, List_t lac)
{
	// fin del arbol, retorno la lista sin modificar
    if (a==NULL)
        return lac;
	// encontre a la persona del nodo *a en el arbol b
	// entonces lo agrego a la lista.
    if (BuscaPersona(b,a->pers->dni))
        lac=ListNodeCreate(a->pers->dni,lac);
	
	// sigo recursivamente con el padre y la madre del nodo *a
	// ojo que esta funcion  puede modificar la lista!
    lac = ListaAncestrosComunes(a->padre,b,lac);
    lac = ListaAncestrosComunes(a->madre,b,lac);

	// retorno la lista con las modificaciones que hubieren ocurrido
    return lac;
}

double CoefRelacion(ArbolGen_t a, ArbolGen_t b)
{
    int gena,genb;
    double rab=0.0;

    List_t lac;
    List_t aux;

    aux = lac = ListaAncestrosComunes(a,b,LIST_EMPTY);
//    ListPrint(lac);

    while(aux!=LIST_EMPTY)
    {
        NivelPersona(a,LIST_CONT(aux),&gena);
        NivelPersona(b,LIST_CONT(aux),&genb);
        rab += 1.0/(1<<gena) * 1.0/(1<<genb);
        aux = aux->pNext;
    }

    ListDestroy(lac);
	return rab;
}

