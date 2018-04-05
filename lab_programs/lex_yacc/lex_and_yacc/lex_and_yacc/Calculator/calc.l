%{
#include<stdlib.h>
#include<stdio.h>
void yyerror(char *);
#include "y.tab.h"
%}

%%

[a-z]	{
			yylval = *yytext - 'a';
		 	return VARIABLE;
		}

[0-9]+	{
			yylval = atoi(yytext);
			return INTEGER;
		}

[-+*/()=\n]	{
				return *yytext;
			}

[ \t]	;	/* Skip whitespace */

.			yyerror("Unknown character.\n");

%%

int yywrap(void)
{
	return 1;
}
