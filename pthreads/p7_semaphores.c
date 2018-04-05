#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>
#include<semaphore.h>

sem_t mutex;

void *thread(void *arg)
{
	// wait
	//printf("ENTERED THREAD: %ld\n",(long)arg);
	sem_wait(&mutex);
	printf("Entered...%ld\n",(long) arg);
	sleep(4);
	printf("Just Exiting...%ld\n",(long)arg);
	sem_post(&mutex);
}

int main()
{
	sem_init(&mutex, 0, 4);
	pthread_t t1, t2, t3, t4, t5;
	pthread_create(&t1, NULL, thread, (void *)1);
	//sleep(6);
	pthread_create(&t2, NULL, thread, (void *)2);
	pthread_create(&t3, NULL, thread, (void *)3);
	pthread_create(&t4, NULL, thread, (void *)4);
	pthread_create(&t5, NULL, thread, (void *)5);
	pthread_join(t1,NULL);
	pthread_join(t2,NULL);
	pthread_join(t3,NULL);
	pthread_join(t4,NULL);
	pthread_join(t5,NULL);
	sem_destroy(&mutex);
	return 0;
}
