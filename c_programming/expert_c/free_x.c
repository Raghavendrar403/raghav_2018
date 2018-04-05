#include<stdio.h>
#include<stdlib.h>
int main() {
	int *p = (int *)malloc(10);
	int i = 0;
	for(i = 0; i<10; i++) {
		p[i] = i;
		printf("%d\n",p[i]);
	}

	free(p);
	for(i = 0; i<10; i++) {
		printf("BULLSEYE\n");
		printf("%d\n",p[i]);
	}
	p = NULL;
	for(i = 0; i<10; i++) {
		printf("%d\n",p[i]);
	}

}
