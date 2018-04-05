#include "apue.h"
int main(int argc, char *argv[])
{
	char 	buf[MAXLINE];
	pid_t	pid;
	int 	status;

	printf("----------------------------------------\n");
	while(fgets(buf, MAXLINE, stdin) != NULL)
	{
		// Replace newline with null character
		// because execlp expects a null at the end
		// and fgets puts a new-line character at the end
		if(buf[strlen(buf)-1] == '\n')
			buf[strlen(buf)-1] = 0;
		
		if((pid=fork()) < 0)
		{
			fprintf(stderr,"fork error");
			exit(0);
		}

		else if(pid == 0)
		{
			execlp(buf, buf, (char *)0);	
			fprintf(stderr,"Could'nt execute %s",buf);
			exit(127);
		}

		if((pid=waitpid(pid,&status,0))<0)
			fprintf(stderr,"waitpid error");
		printf("----------------------------------------\n");

	}
	exit(0);
}
