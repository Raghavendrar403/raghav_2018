%{
#include<stdio.h>
%}

multiline 	\/\*
end 		\*\/	

%%
\/\/.*	;
{multiline}(.|\n)*{end} ;
.	{ECHO;}
%%

int main(int argc, char *argv[])
{
	FILE *f1, *f2;
	if((argc >1) && (f1 = fopen(argv[1], "r")) && (f2 = fopen(argv[2], "w")))
	{
		yyin = f1;
		yyout = f2;
	}
	else
	{
		fprintf(stderr,"provide proper file names\n");
		exit(0);
	}
	yylex();
}
