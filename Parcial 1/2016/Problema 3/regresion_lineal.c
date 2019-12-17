//Adaptado de: Numerical Recipes: The Art of Scientific Computing in (15.2) Fitting Data to a Straight Line

//fitting a straight line y =a + bx to a set of points (xi ; yi) , without available errors.
//The answers are then available as the variables a, b, siga, sigb, chi2, and  sigdat.
//
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "regresion_lineal.h"


FitParams fitLineal(int N, double X[], double Y[]){
	double a, b, siga, sigb, chi2=0, sigdat=0; //Answers.
	//The uncertainties siga and sigb are estimated by assuming equal errors for all points, and that a straight line is a good fit.
	//The normalization of chi2 is to unit standard deviation on all points, and sigdat is set to the estimated error of each point.
	int i;
	double sx=0., sy=0., st2=0., t, sxoss;

	b=0.0;

    //Recorro el set de datos por 1era vez
	for (i=0;i<N;i++) {
        sx += X[i];
        sy += Y[i];
	}
	sxoss=sx/N;

	//Recorro el set de datos por 2da vez
	for (i=0;i<N;i++) {
        t    = X[i]-sxoss;
        st2 += t*t;
        b   += t*Y[i];
	//Accumulate sums ... ...without weights.
	}
	b   /= st2;
	a    = (sy-sx*b)/N;
	siga = sqrt((1.0+sx*sx/(N*st2))/N);
	sigb = sqrt(1.0/st2);

	for( i=0; i < N; i++ )
        chi2 += (Y[i]-a-b*X[i])*(Y[i]-a-b*X[i]);

	if( N > 2 )
        sigdat = sqrt(chi2/(N-2));

	siga *= sigdat;
	sigb *= sigdat;

	FitParams P = { a, b, siga, sigb, chi2, sigdat };
	return P;
}


