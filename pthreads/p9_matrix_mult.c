#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<time.h>
#define NUM_THREADS 5
long x;
void *matrix_multiply();
struct matrix {
	double *a;
	double *b;
	double *c;
} ;
int m;
int n;
int task[NUM_THREADS+1];
struct matrix p;
int main(int argc, char *argv[])
{
	struct timespec start, finish;
	double elapsed;
	int i, j;
	pthread_t threads[NUM_THREADS];
	m = atoi(argv[1]);
	n = atoi(argv[2]);
	if(!(p.a = (double *)malloc(sizeof(double)*m*n)))
		printf("\n ERROR\n");
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
	long l;
	for(i = 0; i<NUM_THREADS; i++) {
		task[i] = i*m/NUM_THREADS;
	}
	task[i] = m;
	clock_gettime(CLOCK_MONOTONIC, &start);
	for(l= 0;l<NUM_THREADS; l++) {
		pthread_create(&threads[l],NULL, matrix_multiply,(void *)l); 
	}
	for(l= 0;l<NUM_THREADS; l++) {
		pthread_join(threads[l], NULL);
	}
	clock_gettime(CLOCK_MONOTONIC, &finish);
	elapsed = (finish.tv_sec - start.tv_sec);
	elapsed += (finish.tv_sec - start.tv_sec)/1000000000.0;
	//for(i = 0; i<m; i++) {
	//	for(j = 0; j<n; j++) {
	//		printf("%f ",i,j,p.c[i*n+j]);
	//	}
	//	printf("\n");
	//}
	//printf("\n");
	//for(i = 0; i<m; i++) {
	//	for(j = 0; j<n; j++) {
	//		printf("%f ",i,j,p.b[i*n+j]);
	//	}
	//	printf("\n");
	//}
	//printf("\n");
	//for(i = 0; i<m; i++) {
	//	for(j = 0; j<n; j++) {
	//		printf("%f ",i,j,p.a[i*n+j]);
	//	}
	//	printf("\n");
	//} 
	printf("\n-- TIME TAKEN IN sec: %f\n",elapsed);

	free(p.a);
	free(p.b);
	free(p.c);
}

void *matrix_multiply(void *x)
{
	int k = 0;
	long i = task[(long)x];
	int j;
	for(; i<task[(long)x+1]; i++) {
		for(j = 0; j<n; j++) {
			for(k = 0; k<n; k++) {
				p.a[i*n+j] += p.b[i*n+k] * p.c[k*n+j];
			}
		}
	}
}

