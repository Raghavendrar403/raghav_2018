%{
#include<stdio.h>
int yylex();
void yyerror(char*);
extern char* yytext;
%}

%token KEYWORD OPERATOR

%%
word: KEYWORD		{printf("KEYWORDS->%s\n",yytext);}
    | '+'			{printf("OPERATOR->%c\n",$1);}
    | '-'			{printf("OPERATOR->%c\n",$1);}
    | '*'			{printf("OPERATOR->%c\n",$1);}
    | '/'			{printf("OPERATOR->%c\n",$1);}
	| ;
%%

int main()
{
	yyparse();
	return 0;
}

void yyerror(char *s) {
	printf("%s\n",s);
}
