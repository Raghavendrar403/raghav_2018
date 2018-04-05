#include<stdio.h>
#include<omp.h>
void funA() {
	printf("Func A:%d\n",omp_get_thread_num());
}

void funB() {
	printf("Func B:%d\n",omp_get_thread_num());
}

int main() {
	#pragma omp parallel
	{
		#pragma omp sections
		{
			#pragma omp section
				(void) funA();

			#pragma omp section
				(void) funB();

			#pragma omp section
				(void) funA();

			#pragma omp section
				(void) funB();

			#pragma omp section
				(void) funA();

			#pragma omp section
				(void) funB();
		}
	}
}
