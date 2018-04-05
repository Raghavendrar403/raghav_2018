#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<math.h>
#define NUMTHREADS 1000
void *runner(void *param);		/* the thread */
long x;
long task[NUMTHREADS+1];

int main(int argc, char *argv[])
{
	if(argc < 2) {
		fprintf(stderr, "USAGE: ./prime.out <int value>\n");
		exit(1);
	}

	if(atoi(argv[1]) < 2) {
		fprintf(stderr, "USAGE: %d must be >= 2\n",argv[1]);
		exit(1);
	}
	x = atoi(argv[1]);
	pthread_t tid[NUMTHREADS];
	printf("Prime numbers\n");
	int r;
	printf("2 ");
	for(r = 0; r<NUMTHREADS; r++) {
		task[r] = r*(x/NUMTHREADS);	
		if(task[r] % 2 == 0) task[r] = task[r] + 1;
	}
	task[0] = 3;
	task[NUMTHREADS] = x;
	long i = 0;
	for(i = 0; i<NUMTHREADS; i++)  {
		pthread_create(&tid[i], NULL, runner,(void *)i);
	}
	for(i = 0; i<NUMTHREADS; i++)  {
		pthread_join(tid[i], NULL);
	}
}

void *runner(void *param)
{
	int i, j, upper;
	long l;
	l = (long) param;
	i = task[l];
	upper = task[l+1];
	for(; i<upper; i += 2) {
		int trap = 0;
		//if((i%5) != 0) {
			for(j = 3; j<=sqrt(i); j += 2) {
				int result = i % j;
				if(result == 0) {
					trap = 1;
					break;
				}
			}
		//}
		
		//else
		//	trap = 1;

		if(trap == 0) {
			printf("%d ",i);
		}
	}

	pthread_exit(0);
}
