#include <stdio.h>

int main() {
	int i,j,m,n;

	printf("Ingrese el valor de m (cantidad de filas):");
	scanf("%d", &m);
	printf("Ingrese el valor de n (cantidad de columnas):");
	scanf("%d", &n);
	for (i = 0; i <= m; i++)
	{
		for (j = 0; j <= n; j++)
		{
			printf("%d%d\t", i, j);
		}
		printf("\n");
	}
	return 0;
}
