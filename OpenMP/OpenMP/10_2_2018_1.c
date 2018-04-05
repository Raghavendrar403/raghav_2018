#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void mxv(int m, int n, double *restrict a, double * restrict b, double * restrict c);

int main(int argc, char *argv[])
{
	double *a, *b, *c;
	int i, j, m, n;

	printf("Please give m and n: ");
	scanf("%d %d", &m, &n);
	if((a = (double *)malloc(m*sizeof(double))) == NULL)
		perror("memmory allocation for a");
	if((b = (double *)malloc(m*n*sizeof(double))) == NULL)
		perror("memmory allocation for b");
	if((c = (double *)malloc(n*sizeof(double))) == NULL)
		perror("memmory allocation for c");

	printf("Initializing matrix B and vector C\n");
	for (j=0; j<n; j++)
		c[j] = 2.0;
	for (i=0; i<m; i++)
		for(j=0; j<n; j++)
			b[i*n+j] = i;

	printf("Executing mxv function for m = %d n = %d\n", m, n);
	(void) mxv(m,n,a,b,c);
	printf("Matrix B: \n");
	for (i=0; i<m; i++)
		for(j=0; j<n; j++)
			printf("%f ", b[i*n+j]);
	printf("\n");

	printf("Vector C: \n");
	for (i=0; i<n; i++)
		printf("%f ",c[i]);
	printf("\n");

	printf("Vector A: \n");
	for (i=0; i<m; i++)
		printf("%f ",a[i]);
	printf("\n");

	free(a);free(b);free(c);
	return 0;
}

void mxv(int m, int n, double * restrict a, double * restrict b, double * restrict c)
{
	int i, j;
/*#pragma omp parallel for default(none)\
	shared(m,n,a,b,c) private(i,j)*/
	clock_t begin = clock();
	for (i=0; i<n; i++)
	{
		a[i] = 0.0;
		for (j=0; j<n; j++)
			a[i] += b[i*n+j] * c[j];
	}
	clock_t end = clock();
	double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("Time taken: %f\n", time_spent);
}
