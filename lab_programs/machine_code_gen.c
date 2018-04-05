#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#define MAXLEN 4096

struct instruction {
	char add_1[3];
	char add_2[3];
	char add_3[3];
	char sym;
}; /* structure to hold all three addresses and the operator */
struct instruction inst = {0}; 
void address_store(char *); /* store the three addresses in the structure */
void process_inst(); /* process the three address instruction */

/* function to clear the contents of the structure */
void reset_inst() {
	strcpy(inst.add_1," ");	
	strcpy(inst.add_2," ");	
	strcpy(inst.add_3," ");	
	inst.sym = 0;
}

int main(int argc, char *argv[]) {
	FILE *fp;
	char line[MAXLEN];
	reset_inst();
	printf("STATEMENT: A=-B*(C+D)\n\n");
	if((fp = fopen(argv[1],"r")) == NULL) {
		printf("Error: cannot access file %s\n",argv[1]);
		exit(1);
	} else {
		while(fgets(line,MAXLEN,fp)) {
			address_store(line);
			process_inst();
			reset_inst();
			printf("\n");
		}
	}
}

void address_store(char *line) {
	char *c = line;
	inst.add_1[0] = *c++;
	if(isalnum(*c)) 
		inst.add_1[1] = *c++;
	c++;
	  
	inst.add_2[0] = *c++;
	if(isalnum(*c))
		inst.add_2[1] = *c++;

	if((*c != '\n') && (*c != EOF)) inst.sym = *c++;

	if((*c != '\n') && (*c != EOF)) {
		inst.add_3[0] = *c++;
		if(isalnum(*c))
			inst.add_3[1] = *c++;
    }
}

void process_inst() {
	if(inst.add_3[0] == ' ') {
		printf("MOV R1, %s\n",inst.add_2);	
		printf("MOV %s, R1\n",inst.add_1);
	}

	else {
		char oper[4];
		printf("MOV R1, %s\n",inst.add_2); 	
		printf("MOV R2, %s\n",inst.add_3); 	
		switch(inst.sym) {
			case '+': strcpy(oper,"ADD"); break;	
			case '-': strcpy(oper,"SUB"); break;
			case '*': strcpy(oper,"MUL"); break;
			case '/': strcpy(oper,"DIV"); break;
		}
		printf("%s R1, R2\n", oper);
		printf("MOV %s, R1\n", inst.add_1);
	}
}
