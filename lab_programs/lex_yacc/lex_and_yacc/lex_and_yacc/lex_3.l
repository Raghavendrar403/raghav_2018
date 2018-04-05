/* counts the no.of characters in the input */
%{
#include<stdio.h>
int nchar = 0, nlines = 0, nwords = 0;
%}
%%
\n      {nlines++; nchar++;}
[^ \t\n]+       {nwords++; nchar += yyleng;}
.       {nchar++;}
%%

int main(void)
{
        yylex();
        printf("%d\t%d\t%d\n", nchar, nwords, nlines);
        return 0;
}
