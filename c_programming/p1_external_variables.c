#include<stdio.h>
#include<stdlib.h>

#define MAXOP 100 	/*Maximum size of operator or operand.*/
#define NUMBER '0'	/*Signal that the number was found.*/
#define MAXVAL 100 /* Maximum depth of the stack.*/
int sp = 0; 		/* Next free stack position*/
double val[MAXVAL]; 	/* value stack*/

int getop(char []);
void push(double);
double pop(void);

/* Reverse polish calculator */ 
int main()
{
	int type;
	double op2;
	char s[MAXOP];

	while((type = getop(s)) != EOF) {
		switch(type) {
			case NUMBER:
				printf("\n NUMBER:%f\n",atof(s));
				push(atof(s));
				break;
			case '+':
				push(pop() + pop());
				break;
			case '-':
				push(pop() - pop());
				break;
			case '*':
				push(pop() * pop());
				break;
			case '/':
				op2 = pop();
				if(op2 != 0.0)
					push(pop()/pop());
				else
					printf("Divide by zero error\n");
				break;
			case '\n':
				printf("\t%g\n", pop());
				break;
			default:
				printf("Invalid character\n");
				break;
		}
	}

	return 0;
}


void push(double f)
{
	if(sp < MAXVAL) {
		val[++sp] = f;
		printf("Val of stack: %f\n",val[sp]);
	}
	else
		printf("Cannot push %f as the stack is full\n",f);
}

double pop(void)
{
	if(sp > 0) {
		printf("Val at %d pop: %f\n",sp, val[sp-1]);
		return val[--sp];
	
	}

	else {
		printf("ERROR: stack empty\n");
		return 0.0;
	}
}

#include<ctype.h>
int getch(void);
void ungetch(int c);

int getop(char s[])
{
	int i, c;
	while((s[0] = c = getch()) == ' ' || c == '\t')
		;
	s[1] = '\0';

	if(c == '\n')
		return '\n';

	if(!isdigit(c) && c != '.') {
		printf("LOL: %c\n",c);
		return c;	/* Not a number.*/
	}
	i = 0;
	if(isdigit(c))
		while(isdigit(s[++i] = c = getch()))

			;
	if(c == '.')
		while(isdigit(s[++i] = c = getch()))
			;

	s[i] = '\0';
	if(c!=EOF)
		ungetch(c);
	return NUMBER;
}

#define BUFFSIZE 100
int bufp = 0;
char buf[BUFFSIZE];

int getch(void)
{
	return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
	if(bufp >= BUFFSIZE)
		printf("ERROR: too many ungetch characters\n");
	else
		buf[bufp++] = c;
}
