%{
#include<stdio.h>
#include<stdlib.h>
#include "y.tab.h"
void yyerror(char *s);
int state = 0;
int x = 0;
%}

%%
							

[0-9]+          {if(!state && !x) {
                        yylval = atoi(yytext);
                        state = 1;        
                        return INTEGER;
                        }
                else
                        yyerror("Invalid statement!");
                }

[-+*/\n]          {if(state == 1 && x == 0)
                 {
               		state = 0;
					return *yytext;
                 }
				 else
					yyerror("Invalid statement");
                }

.		yyerror("Invalid character");

%%

int yywrap(void)
{
	return 1;
}
