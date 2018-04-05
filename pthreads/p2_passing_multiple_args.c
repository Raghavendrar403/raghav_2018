#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#define NUM_THREADS 5
struct thread_data {
	int thread_id;
	int sum;
	char *message;
};

struct thread_data my_threads[NUM_THREADS];
void *print_hello(void *thread_args) 
{
	struct thread_data * mydata;
	mydata = (struct thread_data *) thread_args;
	int taskid = mydata->thread_id;
	char *hello_msg = mydata->message;
	printf("thread #%d says %s\n", taskid, hello_msg);
	pthread_exit(NULL);
}

int main(int argc, char *argv[])
{
	pthread_t threads[NUM_THREADS];
	int rc;
	int t = 0;
	for(t = 0; t<NUM_THREADS; t++)
	{
		my_threads[t].thread_id = t;
		my_threads[t].message = "Hello World LORD";
		rc = pthread_create(&threads[t],NULL,print_hello,(void *)&my_threads[t]);
	}
	pthread_exit(NULL);
}
