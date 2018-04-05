/* This program is an example of how programs can run parallel*/
#include<stdio.h>
#include<string.h>
#include<unistd.h>
char msg[50] = "uninitialized";

void *WatchMessage() {
	printf("child process: Address of msg is %p and msg=%s\n", &msg, msg);
	sleep(2);
	printf("child process: A few seconds later, msg=%s\n", msg);
}

void *change_message()
{
	sleep(1);
	strcpy(msg, "I'm a little teapot");
	printf("Parent process : %p %s\n", &msg, msg);
}

int main()
{
	int pid, stat;
	pid = fork();
	// w copies of original process, one with pid = 0(parent) and other with pid != 0(child)
	if(pid != 0)  {
	WatchMessage();
	}
	else
	change_message();
}
