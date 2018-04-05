%{
#include<stdio.h>
#include "y.tab.h"
%}

identifier [a-zA-Z_][a-zA-Z0-9_]*	

%%
(if|else|while|for|do|int|char|float)	{return KEYWORD;}
[-+\*\/]	{return OPERATOR;}
{identifier} {printf("IDENTIFIER->%s\n",yytext);}
[ \t] 	;
(.|\n)	;
%%

int yywrap()
{
	return 0;
}
