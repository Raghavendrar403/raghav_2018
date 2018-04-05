#include<omp.h>
#include<stdio.h>

int main()
{
	const int nt = omp_get_max_threads();
	printf("OpenMP with %d threads\n", nt);

	#pragma ommp parallel
	{
		printf("Hello World from thread %d\n",omp_get_thread_num());
	}
	
}
