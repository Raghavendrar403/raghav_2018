#include<signal.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

void handler(int s) {
	if(s == SIGBUS) printf("got a bus error signal\n");
	if(s == SIGSEGV) printf("now got a segmentation fault error\n");
	if(s == SIGKILL) printf("now got an illegal instruction signal\n");
	exit(1);
}

int main() {
	int *p = NULL;
	signal(SIGBUS, handler);
	//signal(SIGSEGV,handler);
	signal(SIGKILL, handler);
	while(1) ;
	//*p = 0;
}
