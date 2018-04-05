#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

typedef struct bigint* bip;

typedef struct bigint {
	char *number;
	int length;
} bint;
void getword(bip);
int main(int argc, char *argv[])
{
	if(argc < 2) {
		printf("Not enough arguments\n");
		exit(0);
	}

	bip a = (bip)malloc(sizeof(bint));
	a->length = atoi(argv[1]);
	printf("%d\n",a->length);
	a->number = (char *)malloc(a->length);
	getword(a);
	printf("%s \n",a->number);
}

void getword(bip a)
{
	char *c;
	c = (char *)malloc(a->length);
	c = a->number;

	while(isalnum(*c++ = getchar()) && strlen(a->number)<=a->length-1)
		;
	*c = '\0';
}
