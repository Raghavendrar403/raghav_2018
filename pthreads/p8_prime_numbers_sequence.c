#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

void *runner(void *param);		/* the thread */
long x;

int main(int argc, char *argv[])
{
	clock_t t;
	double time_take;
	
	if(argc < 2) {
		fprintf(stderr, "USAGE: ./prime.out <int value>\n");
		exit(1);
	}

	if(atoi(argv[1]) < 2) {
		fprintf(stderr, "USAGE: %d must be >= 2\n",argv[1]);
		exit(1);
	}
	x = atoi(argv[1]);
	pthread_t tid;
	pthread_attr_t attr;

	printf("Prime numbers\n");

	// Get the deafult attributes
	printf("2 ");
	pthread_attr_init(&attr);
	t = clock();
	pthread_create(&tid, &attr, runner,argv[1]);
	pthread_join(tid, NULL);
	t = clock() - t;
	time_take = ((double)t) / CLOCKS_PER_SEC;
//	printf("\n COMPLETE in %f secs\n", time_take);
}

void *runner(void *param)
{
	int i, j, upper = atoi(param);
	for(i = 3; i<upper; i += 2) {
		int trap = 0;
		for(j = 3; j<=sqrt(i); j += 2) {
			int result = i % j;
			if(result == 0) {
				trap = 1;
				break;
			}
		}

		if(trap == 0) {
			printf("%d ",i);
		}
	}

	pthread_exit(0);
}
