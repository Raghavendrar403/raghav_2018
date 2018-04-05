#include<stdio.h>
struct bit_field {
	unsigned int inactive	: 1;
	unsigned int 			: 1;
	unsigned int ref_count	: 6;
	unsigned int			: 1;
}bf;

int main() {
	bf.inactive +=	10;
	bf.ref_count += 7;
	bf.ref_count += 12;
	printf("%d %d \n",bf.inactive,bf.ref_count);
}
