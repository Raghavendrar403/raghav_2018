#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#define MAXLEN 100

typedef struct tnode* tree_ptr;
typedef struct tnode {
	int count;
	char *word;
	tree_ptr left;
	tree_ptr right;
} tree_node;
void treeprint(tree_ptr root);
int get_word(char *w);
tree_ptr talloc();
char *str_dup(char *);
tree_ptr addtree(tree_ptr a, char *w);

int main()
{
	tree_ptr root = NULL;
	char *word = (char *)malloc(sizeof(char)*100);
	while(get_word(word) != EOF) {
		root = addtree(root, word);
	}

	treeprint(root);
}

int get_word(char *word)
{
	int c;
	char *w = word;

	while(isalpha(c = getchar()))
	{
		*w++ = c;
	}

	*w = '\0';

	if(c == EOF) {
		printf("End of the file\n");
		return EOF;
	}

	else 
		return 1;
}

tree_ptr addtree(tree_ptr p, char *word)
{
	int cond;
	if(p == NULL) {
		p = talloc();
		p->word = str_dup(word);
		p->left = p->right = NULL;
		p->count = 1;
	} else if((cond = strcmp(word, p->word)) == 0) 
		p->count++;
	else if(cond < 0) 
		p->left = addtree(p->left, word);
	else
		p->right = addtree(p->right, word);

	return p;
}

tree_ptr talloc()
{
	return (tree_ptr)malloc(sizeof(tree_node));
}

char *str_dup(char *s)
{
	char *p = (char *) malloc(strlen(s));
	strcpy(p,s);
	return p;
}

void treeprint(tree_ptr p)
{
	if(p != NULL) {
		treeprint(p->left);
		printf("%4d %s\n",p->count, p->word);
		treeprint(p->right);
	}
}
