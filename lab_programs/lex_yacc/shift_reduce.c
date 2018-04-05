#include<stdio.h>
#include<string.h>
char stk[20];
int top = 0;
char act[20];
char input[10];
int iindex = 0;
void printstack()
{
	int i = 0;
	for( i = 0; i<6; i++) printf("%c ", stk[i]);
	printf("\t %5s \t %5s\n",input,act);
}

int check_id() 
{
	int i = 0;
	for(i = 0; i<20; i++)
	{	
		if(stk[i] == 'i')
			return i;
	}
	return -1;
}

void check()
{	
	int x = 0, m=0;
	while(x!=1)	
	{
		int u = check_id();
		int i = 0;
		for(i = 0; i<9;i++)
		{
			
			if(u > -1)
			{	
				strcpy(act,"REDUCE: F->id");
				stk[u] = 'F';
				stk[u+1] = '#';
				top = u+1;
				printstack();
				u = check_id();
			}	

			if(stk[i] == 'F' && stk[0] == 'F')
			{	
				strcpy(act,"REDUCE: T->F\n");
				stk[i] = 'T';
				stk[i+1] = '#';
				top = i+1;
				printstack();
			}

			else if(i!=0 && stk[i] == 'F' && stk[i-1] == '+')
			{
				strcpy(act,"REDUCE: T->F\n");
				stk[i]  = 'T';
				stk[i+1] = '#';
				if(i!=0) x = 1;
				top = i+1;
				printstack();
			}

			if(stk[i] == 'T' && stk[i+1] =='*' && stk[i+2] == 'F')
			{
				strcpy(act,"REDUCE: T->T*F\n");
				stk[i] = 'T';
				stk[i+1] = '#';
				stk[i+2] = '#';
				top = i+1;
				printstack();
			}	

			if(stk[i] == 'E' && stk[i+1] == '+' && stk[i+2] == 'T' && stk[i+3] == '#')
			{
				strcpy(act,"REDUCE: E->E+T\n");
				stk[i] = 'E';
				stk[i+1] = '#';
				stk[i+2] = '#';
				x = 1;
				top = i+1;
				printstack();
				//i = 0;
				break;
			}


			if(stk[i] == 'T')
			{
				if(i == 0 && input[iindex] !='*') {
					strcpy(act,"REDUCE: E->T\n");
					stk[i] = 'E';
					stk[i+1] = '#';
					x = 1;
					top = i+1;
					printstack();
					break;
				}

				else if(stk[i+1] == '+') {
					strcpy(act,"REDUCE: E->T\n");
					stk[i] = 'E';
					stk[i+1] = '#';
					 x = 1;
					top = i+1;
					printstack();
					break;
				}
				else if(i == 0) {
					x = 1;
				}
			}

			m = 0;
			if(input[iindex] != '*' && stk[m] == 'E' && stk[m+1] == '+' && stk[m+2] == 'T' && stk[m+3] == '#') {
				strcpy(act,"REDUCE: E->E+T\n");
				stk[m] = 'E';
				stk[m+1] = '#';
				stk[m+2] = '#';
				x = 1;
				top = m+1;
				printstack();
				//i = 0;
				break;
			}

		}
	}
}
				

int main()
{
	char *header = "Stack\t\t input\t\t Action\t\t";
	scanf("%s",input);
	printf("%s\n",header);
	int input_pointer = 0;
	printf("-----\t\t -----\t\t -----\t\n");
	input[8] = '$';
	printf("$    \t\t %s\t\t \t\n",input);
	int i = 0;
	for(i = 0; input[i]!='$'; i++)
	{	
		if(input[i] == 'i' && input[i+1] == 'd')
		{
			iindex = i+2;
			strcpy(act,"Shift: id"); ;
			stk[top++] = 'i';
			stk[top++] = 'd';
			input[i] = ' ';
			input[i+1] = ' ';
			printstack();
			check();
			i = i+1;
		}

		else if(input[i] == '+' || input[i] == '*')
		{
			strcpy(act,"Shift +/*");
			stk[top++] = input[i];
			input[i] = ' ';
			printstack();
		}
	}
}
