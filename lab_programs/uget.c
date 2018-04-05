#include<stdio.h>

int main() {
	char a;
	a = getchar();
	printf("%c",a);
	ungetc(a,stdin);
	a = getchar();
	printf("%c",a);
	ungetc(a,stdin);
	a = getchar();
	printf("%c",a);
	ungetc(a,stdin);
	a = getchar();
	printf("%c",a);
}
