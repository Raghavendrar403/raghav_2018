%{
#include<stdio.h>
#include "y.tab.h"
%}

%%
if |
else |
while |
int |
double |
float |
char |
bool |
void |
long |
short |
byte {return KEYWORDS;}

[-+*/]	{return OPERATORS;}

[a-zA-Z_][a-zA-Z0-9_]*	{return IDENTIFIERS;}

[ \t]	{;}
\n		{;}
.		{;}
%%

int yywrap()
{
	return 1;
}
