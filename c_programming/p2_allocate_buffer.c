#include<stdio.h>
#include<stdlib.h>
#define ALLOCSIZE 10000

static char allocbuf[ALLOCSIZE]; /* Storage for allocation.*/
static char *allocp = allocbuf;

char *alloc(int n)				/* Return pointer to n characters*/
{
	if((allocbuf + ALLOCSIZE - allocp) >= n) {
		allocp += n;
		return allocp - n;
	} else
		return 0;
}

void afree(char *p)				/* Free storage pointed by p.*/
{
	if(p >= allocbuf && p < allocbuf + ALLOCSIZE)
		allocp = p;
}
