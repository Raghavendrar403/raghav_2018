#include "apue.h"
#include<dirent.h>
#include<stdlib.h>
int main(int argc, char *argv[])
{
	DIR		*dp;
	struct dirent *dirp;
	
	if(argc!=2)
	{
		fprintf(stderr,"Usage: ls directory_name\n");
		return 1;
	}

	if((dp=opendir(argv[1]))==NULL)
		fprintf(stderr,"can't open %s",argv[1]);

	while((dirp=readdir(dp))!=NULL)
		printf("%s\n",dirp->d_name);
	closedir(dp);
	exit(0);
}
