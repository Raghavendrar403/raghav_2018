#include<stdio.h>
void strcat(char *s, char *t)
{
	while(*s != '\0')
		s++;
	
	while(*s++ = *t++)
		;
}

int main(int argc, char *argv[])
{
	char *ptr1 = argv[1];
	char *ptr2 = argv[2];
	char *ptr = ptr1;
	
	strcat(ptr1, ptr2);
	while(*ptr)  {
		printf("%c", *ptr);
		ptr++;
	}

	printf("\n");
}
