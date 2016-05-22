#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SPC ' '

struct node {
	char *word;
	int count ;
	struct node *left;
	struct node *right;
};

int getword(char *word);
struct node * addtree(struct node *root, char *word);
void traverse(struct node *root);

int 
main()
{
	char word[10];
	struct node * root = NULL;

	
	while (getword(word) != EOF) {
		root = addtree (root, word);
	}
	
	traverse(root);
}

int 
getword (char *word)
{
	char c;
	int i = 0;

	while ((c = getc(stdin)) != EOF && (c != '\n'))
		word[i++] = c;	
	if (c == EOF)
		return EOF;
	else {
		word[i] = '\0';
		return 1;
	}
} 
	
struct node *
addtree (struct node *p, char *word)
{
	int cnd;
	if (p == NULL) {
		p = (struct node *) malloc (sizeof(struct node));
		p->word = strdup(word);
		p->count = 1;
		p->left = p->right = NULL;
	} else if ((cnd = strncmp(p->word, word, 3)) == 0) 
			cnd = strcmp(p->word, word);
		
	else if (cnd > 0)
		p->left = addtree (p->left, word);
	else
		p->right = addtree (p->right, word);
	return p;
}
	
void
traverse (struct node *p)
{
	if (p != NULL) {
		traverse (p->left);
		printf ("%s,", p->word);
		traverse (p->right);
	}
}
	
	
	
