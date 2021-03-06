#include<stdio.h>
#include<omp.h>
int main()
{
	#pragma omp parallel
	{
		printf("The parallel region is executed by the thread: %d\n", omp_get_thread_num());
		if(omp_get_thread_num() == 2)
			printf("Thread %d does things differently\n", omp_get_thread_num());
	}
	return 0;
}
