#include <stdio.h>
#include <stdlib.h>

struct node *rec(struct node *orig)
{
	struct node *newnode = NULL;

	if (!orig)	return NULL;

	else {
		newnode = (struct node *) malloc (sizeof(*newnode));

		newnode->data = orig->data;
		
		newnode->next = rec(orig->next);
	}

	return(newnode);
}	
		
			

		
