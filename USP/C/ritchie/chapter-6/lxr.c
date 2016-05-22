#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SPC ' '
#define MAX 10000
int line = 1;

struct node {
	char *word;
	int line[MAX];
	struct node *left;
	struct node *right;
};

int getword(char *word, FILE *);
struct node * addtree(struct node *root, char *word, int line_no);
void traverse(struct node *root);

int 
main(int argc, char *argv[])
{
	char word[1000];
	struct node * root = NULL;
	int line_no;
	FILE *fp;

	fp = fopen(argv[1], "r");

	
	while ((line_no = getword(word, fp)) != EOF) {
	//	printf (" line no from main is %d\n", line_no);
		if (isalpha(word[0])) {
				
			root = addtree (root, word, line_no);
		}
	}
	
	traverse(root);
}

int 
getword (char *word, FILE *fp)
{
	char c;
	int i = 0;
	int line_no;


	line_no = line;
	while ((c = getc(fp)) != EOF && (c != SPC) && (c != '\n'))
		word[i++] = c;	
	if (c == EOF)
		return EOF;
	else if (c == '\n') 
		line++;
	word[i] = '\0';
	//printf ("line num from getword is %d\n", line_no);
	return line_no;
	
} 
	
struct node *
addtree (struct node *p, char *word, int line_no)
{
	int cnd;
	int i;
	if (p == NULL) {
		p = (struct node *) malloc (sizeof(struct node));
		for (i = 0; i < MAX; i++)
			p->line[i] = 0;
		p->line[0] = line_no ;		
		p->word = strdup(word);
		p->left = p->right = NULL;
	} else if ((cnd = strcmp(p->word, word)) == 0) {
			for (i = 0; p->line[i]; i++)
				;
			p->line[i] = line_no;
		}
		
		
	else if (cnd > 0)
		p->left = addtree (p->left, word, line_no);
	else
		p->right = addtree (p->right, word, line_no);
	return p;
}
	
void
traverse (struct node *p)
{
	int i = 0;
	if (p != NULL) {
		traverse (p->left);
		printf ("%s->\t", p->word);
		for (i = 0; (i < MAX) && p->line[i]; i++)
			printf ("%d ", p->line[i]);
		printf ("\n");

		traverse (p->right);
	}
}
	
	
	
