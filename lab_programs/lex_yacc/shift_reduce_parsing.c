#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<stdbool.h>

char grammar[6][10];
char input[10];
char operators[2];
char term[2][2];

void reduce(char *, int *, char *);
int check_rhs(char *, int );
void replace(char *, int *, int);
int is_term(char *, char *);
void push(char *, int *, char *);

int main(int argc, char *argv[]) {
	int i = 0, flag = 0;
	int top = -1;
	char *ip;	/* pointer to the input string */
	char *nip;  /* pointer to the next input in the input string */
	strcpy(term[0],"id");
	strcpy(term[1],"*");
	strcpy(term[2],"+");
	operators[0] = '*';
	operators[1] = '+';
	char stack[100];
	printf("Enter the grammar rules\n");
	//for(i = 0; i<6; i++) {
	//	printf("Enter the rule %d: ",i);
	//	scanf("%s",grammar[i]);
	//}

	strcpy(grammar[0],"E->E+T");
	strcpy(grammar[1],"E->T");
	strcpy(grammar[2],"T->T*F");
	strcpy(grammar[3],"T->F");
	strcpy(grammar[4],"F->(E)");
	strcpy(grammar[5],"F->id");

	for(i = 0;i<6; i++)
		printf("%s\n",grammar[i]);

	printf("Enter the grammar: ");
	scanf("%s",input);

	ip = input;
	nip = ip+2;
	while(flag == 0) {
		if(((i = is_term(ip,nip)) != -1) && (*ip != '\0')) {
			push(stack,&top,ip);
			reduce(stack, &top, nip);
		}

		else 
			flag = 1;
	}
}

void reduce(char *stack, int *top, char *nip) {
	bool x = false;
	int i = 0; 			/* will hold the index of rule with matched RHS with the top of the stack */
	if(*nip != '*') {	/* the next input in the string should not be a * */
		while(!x) {
			if((check_rhs(stack, (*top))) != -1) {
				replace(stack,top,i);	
				printf("%10s %10s\n",stack,input);
			}

			else {
				x = true;
			}
		}
	}
}

int check_rhs(char *stack, int top) {
	int i = 0; 
	char *c;
	for(i = 5; i>=0; i--) {
		c = grammar[i] + strlen(grammar[i]) - 1;
		while(*(c++) == stack[top--])
			;
		if(*c == '>') {
			return i;
		}
	}
	return -1;
}

void replace(char *stack, int *top, int i) {
	char *c = grammar[i]+strlen(grammar[i]) - 1;
	while(*(c--) == stack[*(top)--]) {
			stack[*top] = 0;
	}
	if(*c != '>') {
		printf("An ERROR occured on line no: %d",__LINE__);
		exit(0);
	}
	
	c -= 2;

	stack[*(++top)] = *c;
}

int is_term(char *ip, char *nip) {
	int i = 0;
	for(i = 0; i<3; i++) {
		if(*ip == term[i][0]) {
			if(isalpha(*ip)) {
				ip = ip+2;
				nip = ip+2;
			}
			else {
				ip = ip+1;
				nip = ip+1;
			}
			return i;
		}
	}
	return -1;
}

void push(char *stack, int *top, char *ip) {
	if(isalpha(*ip)) {
		stack[++(*top)] = *ip;
		stack[++(*top)] = *(ip+1);
	}
	else
		stack[++(*top)] = *ip;
}
