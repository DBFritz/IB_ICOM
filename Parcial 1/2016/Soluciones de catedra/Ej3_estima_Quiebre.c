//Primer Parcial ICOM 2016	Ejercicio 3 
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define NDATOS_MAX	256				//Cantidad máxima de datos a leer

//estrucutra para almacenar datos del ajuste lineal
typedef struct {			
	double a, b, siga, sigb, chi2,sigdat;
}FitPARAMS;

//Función para fitear una recta y=a+b*x a los N datos formados por los pares X[i],Y[i] con i en [0:N-1]
FitPARAMS	Fit_Lineal(int N, double X[], double Y[]);

int estimaQuiebre(int Ndatos,double X[],double Y[]);

int main(int argc,char **argv)
{
	//argc indica la cantidad de argumentos luego del ejecutable
	if(argc!=2){fprintf(stderr,"Ingresar el nombre del archivo de lectura como primer argumento");return 0;}

	int i=0;
	double senial=0,X[NDATOS_MAX]={0},Y[NDATOS_MAX]={0};

	//--------------------------------------------------------------//
	//Abre el archivo con el nombre que se dio por linea de comandos
	FILE *fid=fopen(argv[1],"r");
	//Lee el archivo y guardo el dato 
	//Termina al llegar al final del archivo (fscanf devuelve EOF al llegar al final) o al leer NDATOS_MAX
	for(i=0;	fscanf(fid,"%lf",&senial)!=EOF  || i< NDATOS_MAX	;i++)
	{	
		X[i]=i;	Y[i]=senial;
	}
	fclose(fid);
	int Ndatos	=	i;						//Cantidad de datos, pueden ser menos que NDATOS_MAX
	//--------------------------------------------------------------//

	fprintf(stdout,"Indice del QUIEBRE i=%d\n",estimaQuiebre(Ndatos,X,Y));

return 0;
}

int estimaQuiebre(int Ndatos,double X[],double Y[]){
	//El esquema es fitear dos rectas en simultaneo, una a la derecha de del punto "n" y otra a la izquierda
	//Guardo los parámetros de cada recta en dos estructuras diferentes:
	FitPARAMS Pderecha,Pizquierda;

	double	xquiebre=0;		//absisa de la intersección entre las dos rectas
	int		iquiebre=0;		//Este va a ser el indice que voy a retornar, i.e. la parte entera de xquiebre	
	double	chi2_conjunto=0,chi2_min=1e12;	
	int	n;			//cantidad de puntos a fitear por la recta de la izquierda

	//Fitea por lo menos 3 puntos
	for(n=3;n	<=	Ndatos-3;	n++){

		//Fitea los primeros "n" datos, siempre arrancado de X[0] hasta X[n-1]
		Pizquierda	=	Fit_Lineal(n,X,Y);	

		//Fitea "Ndatos-n" arrancando desde X[n] hasta el último valor del vector X[Ndatos-1]
		Pderecha	=	Fit_Lineal(Ndatos-n,X+n,Y+n);	//Si confunde, ver la función Fit_Lineal

		//Criterio para decir cuando dos rectas tienen la misma pendiente
		//La diferencia entre las pendientes es menor al 1%
		if(fabs(Pderecha.b-Pizquierda.b)<0.01*Pderecha.b){fprintf(stdout,"UNA SOLA RECTA\n"); return 0;}

		//absisa de la intersección entre las dos rectas (hacer la cuenta)
		xquiebre	=	(Pderecha.a-Pizquierda.a)/(Pizquierda.b-Pderecha.b);	
	
		//Calculo el chi cuadrado conjunto y me fijo si es el mínimo
		chi2_conjunto= Pderecha.chi2+Pizquierda.chi2;
		if(chi2_conjunto<chi2_min){chi2_min=chi2_conjunto;	iquiebre=xquiebre;}
	}

	return iquiebre;
}	



//Adaptado de: Numerical Recipes: The Art of Scientific Computing in (15.2) Fitting Data to a Straight Line
//fitting a straight line y =a + bx to a set of points (xi ; yi) , without available errors. 
//The answers are then available as the variables a, b, siga, sigb, chi2, and  sigdat.

FitPARAMS	Fit_Lineal(int N, double X[], double Y[]){
	double a, b, siga, sigb, chi2=0, sigdat=0; //Answers. 
	//The uncertainties siga and sigb are estimated by assuming equal errors for all points, and that a straight line is a good fit. 
	//The normalization of chi2 is to unit standard deviation on all points, and sigdat is set to the estimated error of each point.
	int i;
	double sx=0.,sy=0.,st2=0.,t,sxoss;
	b=0.0;
	//Recorro el set de datos por 1era vez
	for (i=0;i<N;i++) {
		sx += X[i];
		sy += Y[i]; 
	}
		sxoss=sx/N;

	//Recorro el set de datos por 2da vez
	for (i=0;i<N;i++) {
		t	=	X[i]-sxoss;
		st2 +=	t*t;
		b	+=	t*Y[i];
	//Accumulate sums ... ...without weights.
	}
	b		/=	st2;
	a		=	(sy-sx*b)/N; 
	siga	=	sqrt((1.0+sx*sx/(N*st2))/N); 
	sigb	=	sqrt(1.0/st2);

	for (i=0;i<N;i++) chi2 += (	(Y[i]-a-b*X[i])*(Y[i]-a-b*X[i])	);

	if (N > 2)	sigdat	=	sqrt(chi2/(N-2));

	siga *= sigdat;
	sigb *= sigdat;

	//Declaro e inicializo la estructura que voy a retornar
	FitPARAMS P={a,b,siga,sigb,chi2,sigdat};
	return P;
}
