#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

typedef struct {
	double *a;
	double *b;
	double sum;
	int veclen;
} DOTDATA;

#define NUMTHRDS 4
#define VECLEN 100
DOTDATA dotstr;
pthread_t call_thread[NUMTHRDS];
pthread_mutex_t mutex_sum;

void dotprod(void *arg)
{
	int i, start, end, len;
	long offset;
	double sum, *x, *y;
	offset = (long) arg;

	len = dostr.veclen;
	start = offset*len;
	end = start + len;
	x = dotstr.a;
	y = dotstr.b;

	sum = 0;
	for(i = start; i<end; i++) {
		sum += (x[i]*y[i]);
	}
	pthread_mutex_lock(&mutex_sum);
	dotstr.sum = sum;
	pthread_mutex_unlock(&mutex_sum);

	pthread_exit((void *) 0);
}

int main(int argc, char *argv[])
{
	long i;
	double *a, *b;
	void *status;
	pthread_attr_
}
