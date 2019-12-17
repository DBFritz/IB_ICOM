#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "expresion.h"

void Exp_Print(Exp expr)
{
    if (expr==NULL) return;
    switch (expr->tipo)
    {
        case EXP_CONSTANT:  printf("%g", expr->args.value);
                            break;
        case EXP_COS:       fputs("cos(",stdout);
                            Exp_Print(expr->args.unary.Arg1);
                            putchar(')');
                            break;
        case EXP_DIV:       putchar('(');
                            Exp_Print(expr->args.binary.Arg1);
                            putchar('/');
                            Exp_Print(expr->args.binary.Arg2);
                            putchar(')');
                            break;
        case EXP_MINUS:     putchar('(');
                            Exp_Print(expr->args.binary.Arg1);
                            putchar('-');
                            Exp_Print(expr->args.binary.Arg2);
                            putchar(')');
                            break;
        case EXP_MULT:      //putchar('(');
                            Exp_Print(expr->args.binary.Arg1);
                            putchar('*');
                            Exp_Print(expr->args.binary.Arg2);
                            //putchar(')');
                            break;
        case EXP_PLUS:      putchar('(');
                            Exp_Print(expr->args.binary.Arg1);
                            putchar('+');
                            Exp_Print(expr->args.binary.Arg2);
                            putchar(')');
                            break;
        case EXP_SIN:       fputs("sin(",stdout);
                            Exp_Print(expr->args.unary.Arg1);
                            putchar(')');
                            break;
        case EXP_TAN:       fputs("tan(",stdout);
                            Exp_Print(expr->args.unary.Arg1);
                            putchar(')');
                            break;
        case EXP_VARIABLE:  putchar('X');
    }
}

double Exp_Evaluate(Exp expr, double X)
{
    if (expr!=NULL)
    switch (expr->tipo)
    {
        case EXP_CONSTANT:  return expr->args.value;
        case EXP_COS:       return cos(Exp_Evaluate(expr->args.unary.Arg1, X));
        case EXP_DIV:       return (Exp_Evaluate(expr->args.binary.Arg1, X)
                                    / Exp_Evaluate(expr->args.binary.Arg2, X));
        case EXP_MINUS:     return (Exp_Evaluate(expr->args.binary.Arg1, X)
                                    - Exp_Evaluate(expr->args.binary.Arg2, X));
        case EXP_MULT:      return (Exp_Evaluate(expr->args.binary.Arg1, X)
                                    * Exp_Evaluate(expr->args.binary.Arg2, X));
        case EXP_PLUS:      return (Exp_Evaluate(expr->args.binary.Arg1, X)
                                    + Exp_Evaluate(expr->args.binary.Arg2, X));
        case EXP_SIN:       return sin(Exp_Evaluate(expr->args.unary.Arg1, X));
        case EXP_TAN:       return tan(Exp_Evaluate(expr->args.unary.Arg1, X));
        case EXP_VARIABLE:  return X;
    }
    return X;
}

void Exp_Destroy(Exp expr)
{
    if (expr==NULL) return;
    switch (expr->tipo)
    {
        case EXP_COS:
        case EXP_SIN:
        case EXP_TAN:
            Exp_Destroy(expr->args.unary.Arg1);
            break;
        case EXP_DIV:
        case EXP_MINUS:
        case EXP_MULT:
        case EXP_PLUS:
            Exp_Destroy(expr->args.binary.Arg1);
            Exp_Destroy(expr->args.binary.Arg2);
            break;
        case EXP_CONSTANT:
        case EXP_VARIABLE: break;
    }
    free(expr);
}

Exp Exp_Derivate(Exp expr)
{
    if (expr!=NULL)
    switch (expr->tipo)
    {
        case EXP_CONSTANT:
            return Exp_CreateConst(0);
        case EXP_SIN:                                                                                       /**< cos(f(x)) f'(x) */
            return Exp_CreateBinary(EXP_MULT, Exp_CreateUnary(EXP_COS,Exp_Clone(expr->args.unary.Arg1)),
                                    Exp_Derivate(expr->args.unary.Arg1));
        case EXP_COS:                                                                                       /**< -1 sin(f(x)) f'(x) */
            return Exp_CreateBinary(EXP_MULT, Exp_CreateBinary(EXP_MULT, Exp_CreateConst(-1),
                                               Exp_CreateUnary(EXP_SIN,Exp_Clone(expr->args.unary.Arg1))),
                                    Exp_Derivate(expr->args.unary.Arg1));
        case EXP_MINUS:                                                                                     /**< f'(x)-g'(x) */
            return Exp_CreateBinary(EXP_MINUS, Exp_Derivate(expr->args.binary.Arg1),
                                    Exp_Derivate(expr->args.binary.Arg2));
        case EXP_MULT:                                                                                      /**< f'(x) g(x)+f(x) g'(x) */
            return Exp_CreateBinary(EXP_PLUS, Exp_CreateBinary(EXP_MULT,
                                                               Exp_Derivate(expr->args.binary.Arg1),
                                                               Exp_Clone(expr->args.binary.Arg2)),
                                                Exp_CreateBinary(EXP_MULT,
                                                               Exp_Clone(expr->args.binary.Arg1),
                                                               Exp_Derivate(expr->args.binary.Arg2)));
        case EXP_PLUS:
            return Exp_CreateBinary(EXP_PLUS, Exp_Derivate(expr->args.binary.Arg1),                         /**< f'(x)+g'(x) */
                                    Exp_Derivate(expr->args.binary.Arg2));
        case EXP_DIV:
           return Exp_CreateBinary(EXP_DIV,                                                                 /**< [f'(x) g(x)+f(x) g'(x)]/[g(x)*g(x)] */
                                   Exp_CreateBinary(EXP_MINUS, Exp_CreateBinary(EXP_MULT,
                                                               Exp_Derivate(expr->args.binary.Arg1),
                                                               Exp_Clone(expr->args.binary.Arg2)),
                                                Exp_CreateBinary(EXP_MULT,
                                                               Exp_Clone(expr->args.binary.Arg1),
                                                               Exp_Derivate(expr->args.binary.Arg2))),
                                   Exp_CreateBinary(EXP_MULT, Exp_Clone(expr->args.binary.Arg2), Exp_Clone(expr->args.binary.Arg2)));

        case EXP_TAN:                                                                                       /**< f'(x) /(cos(f(x))*cos(f(x)))] */
            return Exp_CreateBinary(EXP_DIV, Exp_Derivate(expr->args.unary.Arg1),
                                    Exp_CreateBinary(EXP_MULT, Exp_CreateUnary(EXP_COS, Exp_Clone(expr->args.unary.Arg1)),
                                                     Exp_CreateUnary(EXP_COS, Exp_Clone(expr->args.unary.Arg1))));
        case EXP_VARIABLE:
            return Exp_CreateConst(1);
    }
    return NULL;
}

Exp Exp_CreateBinary(ExpType type, Exp expr1, Exp expr2)
{
    if (EXP_PLUS <= type && type <= EXP_DIV)
    {
        Exp binary = (Exp)malloc(sizeof(struct Exp_str));
        if (binary == NULL)
        {
            fputs("No se pudo alocar memoria", stderr);
            return NULL;
        }
        binary->tipo = type;
        binary->args.binary.Arg1 = expr1;
        binary->args.binary.Arg2 = expr2;
        return binary;
    }
    fputs("EL tipo ingresado no corresponde a una expresión binaria.\n",stderr);
    return NULL;
}

Exp Exp_CreateUnary(ExpType type, Exp expr1)
{
    if (EXP_SIN <= type && type <= EXP_TAN)
    {
        Exp unary = (Exp)malloc(sizeof(struct Exp_str));
        if (unary == NULL)
        {
            fputs("No se pudo alocar memoria", stderr);
            return NULL;
        }
        unary->tipo = type;
        unary->args.unary.Arg1 = expr1;
        return unary;
    }
    fputs("EL tipo ingresado no corresponde a una expresión unaria.\n",stderr);
    return NULL;
}

Exp Exp_CreateConst(double value)
{
    Exp constant = (Exp)malloc(sizeof(struct Exp_str));
    if (constant == NULL)
    {
        fputs("No se pudo alocar memoria", stderr);
        return NULL;
    }
    constant->tipo = EXP_CONSTANT;
    constant->args.value = value;
    return constant;
}

Exp Exp_CreateVar()
{
    Exp variable = (Exp)malloc(sizeof(struct Exp_str));
    if (variable == NULL)
    {
        fputs("No se pudo alocar memoria", stderr);
        return NULL;
    }
    variable->tipo = EXP_VARIABLE;
    return variable;
}

Exp Exp_Clone(Exp e)
{
    if (e==NULL) return NULL;
    Exp clone = (Exp)malloc(sizeof(struct Exp_str));
    if (clone==NULL)
    {
        fputs("No se pudo alocar memoria", stderr);
        return NULL;
    }
    clone->tipo = e->tipo;
    switch (e->tipo)
    {
        case EXP_COS:
        case EXP_SIN:
        case EXP_TAN:
            clone->args.unary.Arg1 = Exp_Clone(e->args.unary.Arg1);
            break;
        case EXP_DIV:
        case EXP_MINUS:
        case EXP_MULT:
        case EXP_PLUS:
            clone->args.binary.Arg1 = Exp_Clone(e->args.binary.Arg1);
            clone->args.binary.Arg2 = Exp_Clone(e->args.binary.Arg2);
            break;
        case EXP_CONSTANT:
            clone->args.value = e->args.value;
        case EXP_VARIABLE: break;
    }
    return clone;
}

int Exp_isConst(Exp e)
{
    switch (e->tipo)
    {
        case EXP_COS:
        case EXP_SIN:
        case EXP_TAN:
            return (Exp_isConst(e->args.unary.Arg1));
        case EXP_DIV:
        case EXP_MINUS:
        case EXP_MULT:
        case EXP_PLUS:
            return (Exp_isConst(e->args.binary.Arg1) && Exp_isConst(e->args.binary.Arg2));
        case EXP_CONSTANT:
            return 1;
        case EXP_VARIABLE: return 0;
    }
    return -1;
}

Exp Exp_Simplify(Exp e)
{
    if (Exp_isConst(e))
    {
        Exp aux = Exp_CreateConst(Exp_Evaluate(e, 0));
            switch (e->tipo)
        {
            case EXP_COS:
            case EXP_SIN:
            case EXP_TAN:
                Exp_Destroy(e->args.unary.Arg1);
            case EXP_DIV:
            case EXP_MINUS:
            case EXP_MULT:
            case EXP_PLUS:
                Exp_Destroy(e->args.binary.Arg1);
                Exp_Destroy(e->args.binary.Arg2);
            case EXP_CONSTANT:
                return 1;
            case EXP_VARIABLE: return 0;
        }
    }
}
