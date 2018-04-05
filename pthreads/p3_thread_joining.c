#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<math.h>
#define NUM_THREADS 4

void *busy_work(void *t)
{
	int i;
	long tid;
	double result = 0.0;
	tid = (long) t;
	printf("Thread %ld starting.....\n",tid);
	for(i = 0; i<10000000; i++)
	{
		result = result + sin(i)*tan(i);
	}
	printf("Thread %ld done. Result = %e\n",tid, result);
	pthread_exit((void *)t);
}

int main(int argc, char *argvp[])
{
	pthread_t thread[NUM_THREADS];
	pthread_attr_t attr;
	int rc;
	long t;
	void *status;
	/* Inititalize and set deatached thread atribute. */
	pthread_attr_init(&attr);
	pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);

	for(t = 0; t<NUM_THREADS; t++)
	{
		printf("Main: creating thread %ld\n", t);
		rc = pthread_create(&thread[t], &attr, busy_work, (void *)t);
		if(rc) {
			printf("ERROR; return code from pthread_create is: %d",rc);
			exit(-1);
		}
	}

	/* Free attricute and wait for other attributes.*/
	pthread_attr_destroy(&attr);
	for(t = 0; t<NUM_THREADS; t++) {
		rc = pthread_join(thread[t], &status);
		if(rc) {
			printf("ERROR; return code from pthread_create is: %d",rc);
			exit(-1);
		}
		printf("Main complete join with thread %ld having status %ld\n",t,(long)status);
	}

	printf("Main program completed. Exitinf \n");
	pthread_exit(NULL);
}

