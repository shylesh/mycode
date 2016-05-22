#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
	int ele;
	struct node *next;
};

void
reverse (struct node **list);

void
move (struct node **new, struct node **tmp);


int
main()
{
	struct node *orig = NULL;
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
	n1->next = n2;
	n2->ele = 15;
	n2->next = NULL;
	n3->ele = 21;
	n3->next = n4;
	n4->ele = 30;
	n4->next = n5;
	n5->ele = 35;
	n5->next = n6;

	n6->ele = 19;
	n6->next = n7;
	n7->ele = 25;
	n7->next = n8;
	n8->ele = 31;
	n8->next = n9;
	n9->ele = 39;
	n9->next = NULL;


	for (temp = orig; temp; temp = temp->next) {
		n_ele++;
	}

	reverse(&orig);
	temp = orig;



	while (temp) {
		printf ("%d\n", temp->ele);
		temp = temp->next;
	}


}


void
reverse(struct node **head_ref)
{
	struct node *tmp = *head_ref;
	struct node *new = NULL;


	while (tmp) {
		move(&new, &tmp);
	}

	*head_ref = new;
}

void
move (struct node **new, struct node **tmp)
{
	struct node *inter = (*tmp)->next;

	(*tmp)->next = *new;
	*new = *tmp;
	(*tmp) = inter;
}
