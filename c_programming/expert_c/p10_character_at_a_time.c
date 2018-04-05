#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
int main() {
	int c;
	system("stty raw");
	while(1) {
		c = getchar();
		printf("\n%c\n",c);
		if(c == 'g')
			break;
	}
	system("stty cooked");
}
