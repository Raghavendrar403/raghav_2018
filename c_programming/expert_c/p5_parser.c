#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#define MAXTOKENS 100
#define MAXTOKENLEN 64

enum type_tag {IDENTIFIER, QUALIFIER, TYPE};
struct token {
	char type;
	char string[MAXTOKENLEN];
};

int top=-1;
struct token stack[MAXTOKENS];
struct token this;

#define pop stack[top--]
#define push(s) stack[++top]=s

/* figure out the identifier */
enum type_tag classify_string(void) {
	char *s = this.string;
	if(!strcmp(s,"const")) {
		strcpy(s,"readonly");
		return QUALIFIER;
	}

	if (!strcmp(s,"volatile")) return QUALIFIER;
	if (!strcmp(s,"short")) return TYPE;
	if (!strcmp(s,"int")) return TYPE;
	if (!strcmp(s,"char")) return TYPE;
	if (!strcmp(s,"float")) return TYPE;
	if (!strcmp(s,"signed")) return TYPE;
	if (!strcmp(s,"double")) return TYPE;
	if (!strcmp(s,"long")) return TYPE;
	if (!strcmp(s,"unsigned")) return TYPE;
	if (!strcmp(s,"void")) return TYPE;
	if (!strcmp(s,"struct")) return TYPE;
	if (!strcmp(s,"union")) return TYPE;
	if (!strcmp(s,"enum")) return TYPE;
	return IDENTIFIER;
}

void gettoken(void) 	/* read next token into "this" */
{
	char *p = this.string;
	/* read past any spaces */
	while((*p = getchar()) == ' ')
		;
	
	if(isalnum(*p)) {
		/* starts with [A-Z][0-9] read the Identifier */
		while(isalnum(*++p = getchar())) ;
		ungetc(*p, stdin);
		*p = '\0';
		this.type = classify_string();
		return ;
	}

	if(*p == '*') {
		strcpy(this.string,"pointer to");
		this.type = '*';
		return ;
	}

	this.string[1] = '\0';
	this.type = *p;
	return ;
}

/* piece of code that undestandeth all parsing */

void read_to_first_identifier()
{
	/* get the first token */
	gettoken();
	while(this.type != IDENTIFIER) {
		push(this);
		gettoken();
	}
	printf("%s is ",this.string);
	gettoken();
}

void deal_with_arrays()
{
	while(this.type=='[') {
		printf("array");
		gettoken(); 	/* get the size of the array */
		if(isdigit(this.string[0])) {
			printf("0..%d ",atoi(this.string) - 1);
			gettoken();	/* read the next ']' */
		}
		gettoken();
		printf("of ");
	}
}

void deal_with_func_args() {
	while(this.type!=')') {
		gettoken();
	}

	gettoken();
	printf("function returning ");
}

void deal_with_pointers() {
	while(stack[top].type == '*') {
		printf("%s ",pop.string);
	}
}

void deal_with_declarator()
{
	/* deal with possible array function following */
	switch(this.type) {
		case '[': deal_with_arrays(); break;
		case '(': deal_with_func_args(); break;
	}

	deal_with_pointers();

	/* process tokens that we stacked while dealing with the identifier */
	while(top>=0) {
		if(stack[top].type == '(') {
			pop;
			gettoken(); 	/* read past ')' */
			deal_with_declarator();
		} else {
			printf("%s ",pop.string);
		}
	}
}

int main() {
	/* put tokens on stack until we reach the identifier */
	read_to_first_identifier();
	deal_with_declarator();
	printf("\n ");
	return 0;
}
