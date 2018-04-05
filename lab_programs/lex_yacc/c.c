#include<stdio.h>
int main() {
	int i = 10;
	while((printf("%d\n",i--)) && (i != 0))
	;
}
