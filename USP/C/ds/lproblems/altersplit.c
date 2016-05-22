#include <stdio.h>
#include <stdlib.h>
#include <string.h>
	

struct node {
	int ele;
	struct node *next;
};

void
mvnode( struct node **l1,
	struct node **l2);

void
alter_split (struct node *list, struct node **l1,
		struct node **l2);

int main()
{
	struct node *orig = NULL;
	struct node *l1= NULL;
	struct node *l2= NULL;
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
	int n_ele = 0;


	n1 = (struct node *) malloc (sizeof(struct node));
	n2 = (struct node *) malloc (sizeof(struct node));
	n3 = (struct node *) malloc (sizeof(struct node));
	n4 = (struct node *) malloc (sizeof(struct node));
	n5 = (struct node *) malloc (sizeof(struct node));
	n6 = (struct node *) malloc (sizeof(struct node));
	n7 = (struct node *) malloc (sizeof(struct node));
	n8 = (struct node *) malloc (sizeof(struct node));
	n9 = (struct node *) malloc (sizeof(struct node));

	orig = n1;
	n1->ele = 1;
	n1->next = NULL;
	n2->ele = 2;
	n2->next = NULL;
	n3->ele = 1;
	n3->next = n4;
	n4->ele = 2;
	n4->next = n5;
	n5->ele = 1;
	n5->next = n6;
	n6->ele = 2;
	n6->next = n7;
	n7->ele = 1;
	n7->next = n8;
	n8->ele = 2;
	n8->next = n9;
	n9->ele = 1;
	n9->next = NULL;

	for (temp = orig; temp; temp = temp->next) {
		n_ele++;
	}	

	alter_split (orig, &l1, &l2);

	temp = l1;

	printf ("l1:");
	while (temp) {
		printf ("%d", temp->ele);
		temp = temp->next;
	}
	

	temp = l2;

	printf ("\nl2:");
	while (temp) {
		printf ("%d", temp->ele);
		temp = temp->next;
	}
}

void
alter_split (struct node *list, struct node **l1,
	    struct node **l2)
{
	struct node *tmp = list;

	while (tmp) {
		mvnode (l1, &tmp);
		if(tmp != NULL) 
			mvnode (l2, &tmp);
		else
			return;
	}
}			
			
