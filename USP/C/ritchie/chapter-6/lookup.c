#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXELE	101

struct lnode {
	struct lnode *next;
	char *str;
	char *rep;
} ;

static struct lnode * narray[MAXELE];

unsigned int hash (char *src);
struct lnode *lookup(char *src);
int install(char *src, char *rep);
void hashdisplay ();

int main()
{
	char src[10] ;
	char rep[10]  ;
	int ret;

	while (1) {	
		printf ("Enter string and replacement string:\n");
		scanf ("%s %s", src, rep);
	
		ret = install (src, rep);
		if (ret == 1)
			printf ("succesfully installed\n");
		else 
			printf ("installed failed\n");
		hashdisplay();			
	}
}	

unsigned int hash (char *src)
{
	unsigned int hashval = 0;
	unsigned int val;

	while (*src) 
		hashval = *(src++) + rand() * hashval;
	 ((val = hashval % MAXELE) <= 100) ? val : 0 ;
	printf ("val is %d\n", val);
	
}

struct lnode *lookup (char *src)
{
	struct lnode *p = NULL;

	if (!narray[hash(src)])
		return NULL;
	for (p=narray[hash(src)]; p != NULL; p = p->next)
		if(strcmp(src, p->str) == 0)
			return p;
	return NULL;
}

		
int install(char *src, char *rep)
{
	struct lnode *p = NULL	;
	struct lnode *base = NULL;
	unsigned int hashval;
	

	if ((p = lookup(src)) == NULL) {
		hashval = hash(src);
		p = (struct lnode *) malloc(sizeof(struct lnode));
		p->str = strdup(src);
		p->next = NULL;
		
		if ((base = narray[hashval]) == NULL)
			narray[hashval] = p;
			
		else {
			while (base->next != NULL)
				base = base->next;
			base->next = p;
		}
	} else 
		free ((void *)p->rep);

	if ((p->rep = strdup(rep)) != NULL)
		return 1;	
	return 0;
}	

void hashdisplay()
{
	int i;
	struct lnode *p = NULL;
	

	for (i = 0; i < MAXELE; i++) {
		if (narray[i] == NULL) 
				continue;
		
		else {
			for (p = narray[i]; p != NULL; ) {
				printf (" bucket = %d, src = %s, rep = %s\n",i, p->str, p->rep);
				p = p->next;
			}
				
		}
		
	}
}	
