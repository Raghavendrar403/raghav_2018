digits  [0-9]
letters [a-zA-Z]
%{
#include<stdio.h>
int count = 0;
%}
%%
{letters}({letters}|{digits})*    count++;
%%

int main()
{
        yylex();
        printf("The no.of identifiers is: %d\n", count);
        return 0;
}
