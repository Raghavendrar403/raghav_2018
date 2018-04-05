#include<omp.h>
#include<stdio.h>
int main()
{
	int total = 0;
	#pragma omp parallel for reduction(+: total)
	for(int i = 0; i<100; i++) {
		//#pragma omp critical 
		{
		total += 1;
		printf("Thread num:%d ,total: %d\n",omp_get_thread_num(), total);
		}	
	}
}
