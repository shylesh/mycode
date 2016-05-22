#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
	int ele;
	struct node *next;
};

void
rec_rev(struct node **list);



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
	n2->ele = 2;
	n2->next = n3;
	n3->ele = 3;
	n3->next = n4;
	n4->ele = 4;
	n4->next = n5;
	n5->ele = 5;
	n5->next = n6;

	n6->ele = 6;
	n6->next = n7;
	n7->ele = 7;
	n7->next = n8;
	n8->ele = 8;
	n8->next = n9;
	n9->ele = 9;
	n9->next = NULL;


	for (temp = orig; temp; temp = temp->next) {
		n_ele++;
	}

	rec_rev(&orig);
	temp = orig;



	while (temp) {
		printf ("%d\n", temp->ele);
		temp = temp->next;
	}


}


/*void
rec_rev(struct node **head_ref)
{

	struct node *tmp = NULL;
	struct node *tmp1 = NULL;

	if (!(*head_ref))
		return;


	rec_rev (&(*head_ref)->next);
	tmp = tmp1 =  (*head_ref)->next;

	if (!tmp)
		return;
	while (tmp1->next)
		tmp1 = tmp1->next;
	tmp1->next = *head_ref;
	tmp1->next->next = NULL;

	*head_ref = tmp;

}*/

void
rec_rev (struct node **head)
{
	struct node *first = *head;
	struct node *rest = NULL;

	if (!(head))
		return;

	rest = first->next;

	if (!rest)	return;

	(
cd /va	log
ls
ls -lrt
estals -lrt
less my
GGGq
#
vim /et	rss
GGGGGGqrest);

	first->next->next = *head;
	first->next = NULL;


	*head = rest;
}











