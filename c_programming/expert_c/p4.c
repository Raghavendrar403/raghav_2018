#include<stdio.h>
#define peach int
typedef int banana;
int main() {
	unsigned peach i;		/* this is O.K*/
	unsigned banana y;		/* this part leads to an error 
	as you cannot a type specifier with a typedefed keyword*/
}

