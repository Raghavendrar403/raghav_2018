#include<stdio.h>

void a(), b(), c(), d(), e();

void a() {
	printf("a\n");
}

void b() {
	printf("b\n");
}

void c() {
	printf("c\n");
}

void d() {
	printf("d\n");
}

void e() {
	printf("e\n");
}

int main() {
	void (*states[])() = {a,b,c,d,e};
	int i = 0;
	for(i = 0; i<5; i++) {
		states[i]();
	}
}

