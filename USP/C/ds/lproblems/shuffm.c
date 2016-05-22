#include <stdio.h>
#include <stdlib.h>
#include <string.h>
	

struct node {
	int ele;
	struct node *next;
};

void
smerge (struct node **final, struct node *aref, struct node *bref);

int main()
{
	struct node *ahead = NULL;
	struct node *bhead = NULL;
	struct node *final = NULL;
	struct node *n1    = NULL;
	struct node *n2    = NULL;
	struct node *n3    = NULL;
	struct node *n4    = NULL;
	struct node *n5    = NULL;
	struct node *n6    = NULL;
	struct node *n7    = NULL;
	struct node *n8    = NULL;
	struct node *n9    = NULL;
	struct node *temp = NULL;
	int i;


	n1 = (struct node *) malloc (sizeof(struct node));
	n2 = (struct node *) malloc (sizeof(struct node));
	n3 = (struct node *) malloc (sizeof(struct node));
	n4 = (struct node *) malloc (sizeof(struct node));
	n5 = (struct node *) malloc (sizeof(struct node));
	n6 = (struct node *) malloc (sizeof(struct node));
	n7 = (struct node *) malloc (sizeof(struct node));
	n8 = (struct node *) malloc (sizeof(struct node));
	n9 = (struct node *) malloc (sizeof(struct node));

	ahead = n1;
	n1->ele = 1;
	n1->next = NULL;
	n2->ele = 2;
	n2->next = n3;
	n3->ele = 3;
	n3->next = n4;
	n4->ele = 4;
	n4->next = NULL;

	bhead = n5;
	n5->ele = 5;
	n5->next = NULL;
	n6->ele = 6;
	n6->next = n7;
	n7->ele = 7;
	n7->next = n8;
	n8->ele = 8;
	n8->next = n9;
	n9->ele = 9;
	n9->next = NULL;

	smerge(&final, ahead, bhead);

	printf ("after merging the list is \n");

	temp = final;

	while (temp) {
		printf ("%d", temp->ele);
		temp = temp->next;
	}
	
}
			

void
smerge (struct node **list, struct node *aref, struct node *bref)
{

	struct node *tmp = NULL;
	struct node *next = NULL;
	struct node *aux = *list;
	int flip = 0;

	
	if (!(aref && bref)) {
		*list = aref ? aref:bref;
		
	}

	else 	{
		*list = aux = tmp = aref;
		next = bref;
		
		tmp = tmp->next;
		while (tmp) {

			if(!next) break;
			else {

				aux->next = ((flip)? tmp:next);
				aux = aux->next;

				(flip)?(tmp = tmp->next):(next = next->next);
				flip = !flip;
			}
		}

	if (flip)     //reached the end of second list//
		aux->next = tmp;
	else
		aux->next = next;


	return;
	}
}
			
								
		
