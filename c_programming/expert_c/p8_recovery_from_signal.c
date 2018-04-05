#include<setjmp.h>
#include<signal.h>
#include<stdio.h>
#include<stdlib.h>
jmp_buf buf;
void handler(int s) {
	if(s == SIGINT) printf("now got a SIGINT signal \n");
	longjmp(buf,1);
	/* NOT REACHED*/
}

int main() {
	signal(SIGINT, handler);
	if(setjmp(buf)) {
		printf("BACK IN THE MAIN BITCHES\n");
		return 0;
	}
	else 
		printf("FIRST TIME \n");
loop:
	/* spin here waiting for ctrl-c */
	goto loop;
}
