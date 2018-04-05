#include<stdlib.h>
#include<unistd.h>
int main() {
	int i, *p;
	for(i = 0; i<10; i++) {
		p = (int *)malloc(1024);
		system("sleep 10");
	}
}
