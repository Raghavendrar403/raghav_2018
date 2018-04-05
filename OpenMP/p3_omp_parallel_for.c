#include<omp.h>
#include<stdio.h>

int main()
{
	int n = 10;
	#pragma omp parallel for
	for(int i = 0; i<n; i++)
	{
		printf("Hello World from %d\n",omp_get_thread_num());
	}
}
