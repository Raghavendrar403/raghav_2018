#include<stdio.h>
int main() {
	/* char, short are promoted to int and float to double */
	printf("char: %d \n", sizeof('A'));
	printf("float: %d \n", sizeof(1.231));
	printf("float: %d \n", sizeof(float));
}
