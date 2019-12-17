
typedef struct {
	double a, b, siga, sigb, chi2, sigdat;
} FitParams;

FitParams	fitLineal(int N, double X[], double Y[]);

