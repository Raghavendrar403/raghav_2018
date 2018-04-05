#include<stdio.h>
#include<stdlib.h>
#include<omp.h>
#include<unistd.h>
int main() {
	int n = 5;
	int i, j;
	#pragma omp parallel for default(shared) schedule(runtime) private(i,j)
	for(i=0; i<n; i++)
	{
		printf("Iteration %d executed by thread %d\n", i, omp_get_thread_num());
		for(j=0; j<i; j++)
			system("ls");
	}
}
