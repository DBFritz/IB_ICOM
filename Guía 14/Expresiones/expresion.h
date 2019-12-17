#ifndef EXPRESION_H_INCLUDED
#define EXPRESION_H_INCLUDED

typedef enum ExpT {
    EXP_CONSTANT,
    EXP_PLUS,
    EXP_MINUS,
    EXP_MULT,
    EXP_DIV,
    EXP_SIN,
    EXP_COS,
    EXP_TAN,
    EXP_VARIABLE
} ExpType;

typedef struct Exp_str {
    ExpType tipo;
    union {
        double value; // constants
        struct {
            struct Exp_str *Arg1, *Arg2; // binarias
        }binary;
        struct {
            struct Exp_str *Arg1; // unarias
        }unary;
    } args;
}*Exp;


/** \brief Recibe una expresi�n y la imprime
    \param expr:     La expresi�n a imprimir */
void Exp_Print(Exp expr);

/** \brief Evalua en la expresi�n expr el valor X
    \param expr:    La expresi�n en la que evaluar
    \param X:       El valor de X en el que evaluar
    \return El valor de la evaluaci�n.      */
double Exp_Evaluate(Exp expr, double X);

/** \brief Libera todos los recursos asociados a expr
    \param expr:    La expresi�n a liberar */
void Exp_Destroy(Exp expr);

/** \brief Calcule la expresi�n derivada anal�tica de la expresi�n
    \param expr:    La expresi�n a derivar
    \return La expresi�n de la derivada de expr     */
Exp Exp_Derivate(Exp expr);

/** \brief Crea y retorna una exprecci�n binaria
    \param type:    El tipo de expresi�n a crear
    \param expr1:   La expresi�n a operar
    \param expr2:   La otra expresi�n a operar
    \return La expresi�n binaria del tipo exp1 type expr2 (e.g expr1 * rxp2)   */
Exp Exp_CreateBinary(ExpType type, Exp expr1, Exp expr2);

/** \brief Crea y retorna una exprecci�n unaria
    \param type:    El tipo expresi�n a crear
    \param expr1:    La expresion a cual aplicarte type
    \return La expresi�n binaria del type expr1 (e.g sin( expr1 )   */
Exp Exp_CreateUnary(ExpType type, Exp expr1);

/** \brief Crea y retorna una constante
    \param value:   El valor de la constante
    \return La expresi�n de la constante   */
Exp Exp_CreateConst(double value);

/** \brief Crea y retorna una exprecci�n binaria
    \param type:    El tipo de expresi�n
    \return La expresi�n binaria del tipo exp1 type expr2 (e.g 3 * X)   */
Exp Exp_CreateVar();

/** \brief Cree y retorne un clon de la expresi�n recibida
    \param e:    La expesi�n a clonar
    \return El Clon de la expresi�n   */
Exp Exp_Clone(Exp e);

Exp Exp_Simplify(Exp e);

#endif // EXPRESION_H_INCLUDED
