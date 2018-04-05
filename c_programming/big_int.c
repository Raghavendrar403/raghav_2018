#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

typedef struct bigint {
	char *num;
	int length;
}bigInt;

void bigInt_mul(bigInt *, bigInt*);
int main(int argc, char *argv[])
{
	int x;
	x = atoi(argv[1]);
	bigInt *number;
	number = (bigInt *)malloc(sizeof(bigInt));
	char *out = (char *)malloc(x);
	number->length = x;
	number->num = out;
	scanf("%s",out);
	printf("%s\n",number->num);
	bigInt *a = (bigInt *)malloc(sizeof(bigInt));
	bigInt_mul(a, number);
	printf("%s",a->num);
	
}

void bigInt_mul(bigInt *a, bigInt *b)
{
	int i = 0;
	int flag=0;
	int carry = 0;
	char *out = (char *)malloc(b->length + 1);
	a->num = (char *)malloc(b->length+1);
	out = a->num;
	for(i = b->length-1; i>=0;i--)	 {
		flag = (b->num[i] - '0')*2 + carry;
		carry = flag/10;
		out[i] = flag%10 + '0';
	}
	out[0] = carry;
	printf("%s\n",out);
	free(out);
}
