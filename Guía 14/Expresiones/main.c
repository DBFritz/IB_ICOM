#include <stdio.h>
#include <stdlib.h>
#include "expresion.h"
int main()
{
    double i;
    Exp expr= Exp_CreateBinary(EXP_DIV,
                    Exp_CreateUnary(EXP_SIN,
                            Exp_CreateBinary(EXP_PLUS,
                                    Exp_CreateBinary(EXP_MULT,
                                            Exp_CreateConst(3),
                                            Exp_CreateVar()),
                                    Exp_CreateConst(4))),
                    Exp_CreateBinary(EXP_PLUS,
                            Exp_CreateConst(2),
                            Exp_CreateBinary(EXP_MULT,
                                    Exp_CreateConst(3),
                                    Exp_CreateUnary(EXP_COS,
                                            Exp_CreateBinary(EXP_DIV,
                                                    Exp_CreateVar(),
                                                    Exp_CreateBinary(EXP_PLUS,
                                                            Exp_CreateConst(2),
                                                            Exp_CreateVar()))))));
    Exp_Print(expr);
    //for (i=0; i <= 1; i += 0.01)
    //    printf("\nf(%g)=%g",i, Exp_Evaluate(expr, i));
    putchar('\n');
    Exp_Print(Exp_Derivate(expr));
}
