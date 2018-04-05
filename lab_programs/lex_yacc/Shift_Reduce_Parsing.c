#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct production {
	char lhs;
	char rhs[10];
} grammar[10];

int main(int argc, char *argv) 
{
	int i = 0;
	printf("\n Enter the grammar: \n");
	for(i = 0; i<4; i++) {
		grammar[i].lhs = getchar();
	}

	for(i = 0; i<4; i++)
		printf("%c ", grammar[i].lhs);
}
