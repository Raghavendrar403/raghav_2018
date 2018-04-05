#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int m;
int n;
void matrix_multiply();
struct matrix {
	double *a;
	double *b;
	double *c;
} p;
int main(int argc, char *argv[])
{
	int i, j;
	double elapsed;
	clock_t t;
	m = atoi(argv[1]);
	n = atoi(argv[2]);
	if(!(p.a = (double *)malloc(sizeof(double)*m*n)))
	printf("ERROR\n");
	p.b = (double *)malloc(sizeof(double)*m*n);
	p.c = (double *)malloc(sizeof(double)*m*n);


	for(i = 0; i<m; i++) 
		for(j = 0; j<n; j++) 
			p.a[i*n+j] = 0.0;

	for(i = 0; i<m; i++) 
		for(j = 0; j<n; j++) 
			p.c[i*n+j] = rand()%10;

	for(i = 0; i<m; i++) {
		for(j =0; j<n; j++) {
			p.b[i*n+j] = rand()%10;
		}
	}
	t = clock();
	matrix_multiply();
	t = clock() - t;
	elapsed = (double)t/CLOCKS_PER_SEC;

	printf("\n TIME TAKEN IN s: %f\n",elapsed);
	free(p.a);
	free(p.b);
	free(p.c);
}

void matrix_multiply()
{
	int i, j = 0, k = 0;
	for(i = 0; i<m; i++) 
		for(j = 0; j<n; j++) {
			for(k = 0; k<n; k++)
			p.a[i*n+j] += p.b[i*n+k] * p.c[k*n+j];
		}
}

