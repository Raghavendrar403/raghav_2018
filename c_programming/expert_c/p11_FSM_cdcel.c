#include<stdio.h>
#include<sdlib.h>
#include<string.h>
#include<ctype.h>

#define MAXTOKENS 100
#define MAXTOKELEN 64

enum type_tag { IDENTIFIER, QUALIFIER, TYPE};

struct token {
	char type;
	char string[MAXTOKELEN];
};

