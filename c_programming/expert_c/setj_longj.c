#include<setjmp.h>
#include<stdio.h>
jmp_buf buf;
void banana() {
	printf("in banan()\n");
	longjmp(buf,1);
	printf("NOT REACHED\n");
}

int main() {
	if(setjmp(buf)) {
		printf("BACK IN MAIN\n");
	}

	else {
		printf("first time through\n");
		banana();
	}
}
