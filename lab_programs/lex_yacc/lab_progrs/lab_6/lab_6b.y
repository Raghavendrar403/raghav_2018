%{
#include<stdio.h>
#include<stdlib.h>
int yylex();
void check();
void yyerror(char *s);
void print_count();
extern char *yytext;
extern FILE *yyin;
int key;
int op;
int id;
%}

%token KEYWORDS IDENTIFIERS OPERATORS

%%

program: program KEYWORDS {printf("%s-->KEYWORD\n",yytext); key++; check();}
		|
		;

program : program OPERATORS {printf("%s-->OPERATOR\n",yytext); op++; check();}
		;

program : program IDENTIFIERS {printf("%s-->IDENTIFIERS\n",yytext); id++; check();}
		;

%%

void check() {
	if(yytext[0] == EOF)
		print_count();
		
}
void yyerror(char *s)
{
	printf("%s %s\n",yytext,s);
}

void print_count()
{
	printf("\n\n");
	printf("KEYWODS: %d\n", key);
	printf("OEPRATORS: %d\n", op);
	printf("IDENTIFIERS: %d\n", id);
}

int main(int argc, char *argv[])
{
	key = op = id = 0;
	yyin = fopen(argv[1],"r");
	yyparse();
	print_count();
	return 0;
}
