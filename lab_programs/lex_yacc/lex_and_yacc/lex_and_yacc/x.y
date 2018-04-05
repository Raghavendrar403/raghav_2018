%{
#include<stdio.h>
int yylex(void);
void yyerror(char *s);
%}

%token INTEGER

%%
program: 
        program expr '\n'       {printf("%d\n",$2);}
        |
        ;
expr:   INTEGER   {$$ = $1;}
        ;

%%

int main(void)
{
        yyparse();
}

void yyerror(char *s)
{
        printf("this is the shit: %s", s);
}
