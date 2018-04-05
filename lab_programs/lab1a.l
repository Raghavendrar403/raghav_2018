%{
#include<stdio.h>
int status = 1;
int plus = 0;
int mul = 0;
char arr[20];
int i = 0;
int ext();
int s_ext();
%}

%x OPER

%%
[a-zA-Z0-9]+    {BEGIN OPER;
                 status = 1;}
<OPER>"+"       {
                plus = plus + 1;
                arr[i] = '+';
                i = i+1;
                if(status == 1)
                {
                        status = 0;
                }
                else
                        ext();
                }
<OPER>"*"       {
                mul = mul + 1;
                arr[i] = '*';
                i = i+1;
                if(status == 1)
                {
                        status = 0;
                }
                else
                        ext();
                }
<OPER>[a-zA-Z0-9]+      {
                         if(!status)
                                status = 1;
                         else
                                ext();
                        }
<OPER>\n        {
                        s_ext();
                }

<OPER>.         {
                        ext();
                }

.       {ext();}

%%

int ext()
{
        status = 3;
        return 0;
}

int s_ext()
{
        if(status == 1)
                printf("Valid exp\n");
        else if(status == 0)
                printf("Invlaid exp\n");
        else if(status == 3)
                printf("Invlaid exp\n");
        printf("No.of plus: %d\n",plus);
        printf("No.of mul: %d\n",mul);
        for(int j = 0; j<i; j++)
        {
                printf("%c", arr[j]);
        }
        printf("\n");
        exit(0);
}

int main()
{
        yylex();
}
