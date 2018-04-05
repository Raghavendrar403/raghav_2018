#include<stdio.h>
int main() {
	int apple;
	char orange;
	float banana;
	int x = 10;
	int *p = &x;

	apple = sizeof(int)**p;
	printf("%d\n",apple);
}
