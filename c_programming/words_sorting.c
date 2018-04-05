#include<stdio.h>
#include<curses.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#define MAXWORD 100

struct tnode {
	int count;
	char *word;
	struct tnode *left;
	struct tnode *right;
}*root;

struct tnode *addtree(struct tnode*,char *w);
struct tnode *talloc(void);
void treeprint(struct tnode *p);
//char *strdup(char *);

int getword(char *word, int lim)
{
	char *w = word;
	int c;
	while((c = getchar()) != )
		*w++ = ' ';
	
	*w = word;
	
	while((*w++ = getchar()) && --lim)
		;

	*w = '\0';
	return word[0];
}

int main()
{
	int n;
	char word[MAXWORD];
	while(getword(word,MAXWORD) != EOF)
		if(isalpha(word[0]))
			root = addtree(root, word);
	
	treeprint(root);
	return 0;
}

struct tnode *addtree(struct tnode *p,char *w)
{
	int cond;
	if(p == NULL) {
		p = talloc();
		p->word = w;
		p->left = NULL;
		p->right = NULL;
		p->count = 1;
	} else if((cond = strcmp(p->word, w)) == 0) {
		p->count++;	
	}

	else if(cond < 0) {
		p->left = addtree(p->left, w);
	}

	else
		p->right = addtree(p->right, w);
	
	return p;
}

struct tnode *talloc(void)
{
	struct tnode *p = NULL;
	p = (struct tnode *)malloc(sizeof(struct tnode));;
	return p;
}

//struct strdup(char *w)
//{
//	char *word = (char *) malloc(strlen(w)+1);
//	if(w != NULL)
//		strcpy(word,w);
//	return word;
//}

void treeprint(struct tnode *p) 
{
	if(p != NULL) {
		treeprint(p->left);
		printf("%4d %s\n", p->count, p->word);
		treeprint(p->right);
	}
}
