#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#define NTHREADS 4
#define N 1000
#define MEGEXTREA 1000000

pthread_attr_t attr;

void *do_work(void *thread_id)
{
	double A[N][N];
	int i, j;
	long tid;
	size_t stack_size;

	tid = (long) thread_id;
	pthread_attr_getstacksize(&attr, &stack_size);
	printf("Thread %ld: stack size:%li\n", tid, stack_size);
	for(i = 0; i<N; i++)
		for(j = 0; j<N; j++)
			A[i][j] = ((i*j)/3.452) +(N-i);
	
	pthread_exit(NULL);
}

int main(int argc, char *argv[])
{
	pthread_t threads[NTHREADS];
	size_t stack_size;
	int rc;
	long t;

	pthread_attr_getstacksize(&attr, &stack_size);
	printf("Default stack size: %li\n", stack_size);
	stack_size = sizeof(double)*N*N + MEGEXTREA;
	printf("Amount of stack size needed per thread: %li\n", stack_size);
	pthread_attr_setstacksize(&attr,stack_size);
	for(t = 0; t<NTHREADS; t++) {
		rc = pthread_create(&threads[t], &attr, do_work, (void *)t);
		if(rc)  {
			printf("ERROR: %d\n", rc);
			exit(-1);
		}
	}
	pthread_exit(NULL);
}
