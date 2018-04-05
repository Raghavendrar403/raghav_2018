#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
typedef struct symbols *symbol;
typedef struct symbols {
	char symbol;
	char *ptr;
	char follow[5];
} sym;
char rules[3][10];
char find_first(symbol);
void find_follow(symbol);
char start_sym;
void parse_output(symbol *, char *);
void pop(char *, int *);
void push(char *, int *, char *);
char message[100];
int M[6][2];
int main(int argc, char *argv[])
{
	int i, j, k = 0;
	M[0][0] = M[1][0] = M[2][0] = M[3][0] = M[4][0] = M[5][0] = 99;
	symbol *a = (symbol *)malloc(sizeof(sym)*5);
	char input_symbol[] = {'a','b','$'};
	printf("Enter the rules \n");
	for(i = 0; i<3; i++) {
		printf("Enter rule %d: ",i);
		scanf("%s", rules[i]);
	}
	
	for(i = 0; i<3; i++) {
		a[i] = (symbol) malloc(sizeof(sym));
		a[i]->symbol = rules[i][0];
		a[i]->ptr = rules[i];
	}
	start_sym = rules[0][0];

	for(i = 0; i<3; i++) {
		find_follow(a[i]);
	}

	for(i = 0, k = 0; i<3; i++) {
		for(j = 0; j<3; j++) {
			if(find_first(a[i]) == input_symbol[j]) {
				M[k][0] = i;
				M[k][1] = j;
				k++;
			}

			else if(find_first(a[i]) == '@') {
				if((a[i]->follow[0] == input_symbol[j]) ||(a[i]->follow[1] == input_symbol[j])) {
					M[k][0] = i;
					M[k][1] = j;
					k++;
				}
			}
		}
	}
	
	for(i = 0; i<6 && (M[i][0] != 99); i++) {
		printf("M[%c, %c] = %s\n", a[M[i][0]]->symbol, input_symbol[M[i][1]], a[M[i][0]]->ptr);
	}
	parse_output(a, input_symbol);
}

char find_first(symbol a) {
	char *c = a->ptr;
	while((*c++ != '>'))
		;
	if(islower(*c) || *c=='@')
	return *c;	
}

void find_follow(symbol sym)
{
	char c = sym->symbol;
	int i = 0, j = 0, k = 0;;
	for(i = 0; i<3; i++) {
		for(j = 0; j<10; j++) {
			if(rules[i][j] == c) {
				if((i == 0 && j == 0)) {
					sym->follow[k++] = '$';		
				}

				else if(rules[i][j+1] != '-') {
					sym->follow[k++] = rules[i][j+1];
				}
			}
		}
	}
}

void parse_output(symbol *a, char *input_symbol) 
{
	char input[10];
	printf("Enter the input: ");
	scanf("%s", input);
	char stack[100];
	int top = -1;
	stack[++top] = '$';
	stack[++top] = start_sym; 
	int i = 0, j = 0;
	printf("%10s %10s$ %20s\n",stack, input, message);
	while(input[i] != '\0') {
		if(stack[top] == input[i]) {
			pop(stack, &top);	
			input[i] = ' ';
			printf("%10s %10s$ %20s\n",stack, input, message);
			i++;
		}

		else {
			for(j = 0; j<6 && (M[j][0] != 99); j++) {
				if((a[M[j][0]]->symbol == stack[top]) && (input_symbol[M[j][1]] == input[i])) {
					pop(stack, &top);
					printf("%10s %10s$ %20s\n",stack, input, message);
					push(stack, &top, a[M[j][0]]->ptr);
					printf("%10s %10s$ %20s\n",stack, input, message);
				}
			}
		}

	}
}

void pop(char *stack, int *top) 
{
	char temp = stack[*top];
	stack[*top] = '\0';
	*top = *top-1;
	char mess[1] = {temp}; 
	strcpy(message,"poped: ");
	strcat(message,mess);
}

void push(char *stack, int *top, char *rule)
{
	int x = strlen(rule) - 1;
	int i = 0;
	if(rule[x] == '@') {
		;	
	}
	else {
		for(i = x; i>=0 && rule[i]!='>'; i--) {
			stack[++(*top)] = rule[i];
		}
	}
	char *mess = rule;
	strcpy(message,"pushed: ");
	strcat(message, mess);
}
