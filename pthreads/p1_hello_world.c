#include<pthread.h>
#include<stdio.h>
#include<stdlib.h>
#define NUM_THREADS 5

void *print_hello(void *thread_id)
{
	long tid;
	tid = (long)thread_id;
	printf("Hello World! It's me thread #%ld\n",tid);
	pthread_exit(NULL);
}

int main(int argc, char *argv[])
{
	pthread_t threads[NUM_THREADS];
	int rc;
	long tasks_id[NUM_THREADS];
	int t;
	for(t = 0; t<NUM_THREADS; t++)
	{
		tasks_id[t] = t;
		rc = pthread_create(&threads[t], NULL, print_hello, (void *)tasks_id[t]);
		if(rc) {
			printf("pthreads_create ERROR: %d",rc);
			exit(-1);
		}
	}

	pthread_exit(NULL);
}
