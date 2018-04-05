#include<stdio.h>
#include<omp.h>
int main() {
	int a, b[10], n = 10, i = 0;	
	#pragma omp parallel shared(b) private(i,a)
	{
		#pragma omp single	 
		{
			a = 10;
			printf("Thread: %d\n", omp_get_thread_num());
		}

		#pragma omp for
		for(i=0; i<n; i++)
			b[i] = a;
	}

	for(i=0; i<n; i++)
		printf("b[%d]: %d\n", i, b[i]);
}
