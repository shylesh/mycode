#include <stdio.h>
#include <stdlib.h>
#include <string.h>
	

struct node {
	int ele;
	struct node *next;
};


struct node *
sort_intersect(struct node *l1,
		struct node *l2);

void
push (struct node **list, int ele);

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

	l1 = n1;
	n1->ele = 1;
	n1->next = n2;
	n2->ele = 15;
	n2->next = n3;
	n3->ele = 22;
	n3->next = n4;
	n4->ele = 29;
	n4->next = n5;
	n5->ele = 35;
	n5->next = NULL;


	l2 = n6;
	n6->ele = 19;
	n6->next = n7;
	n7->ele = 21;
	n7->next = n8;
	n8->ele = 30;
	n8->next = n9;
	n9->ele = 36;
	n9->next = NULL;

	for (temp = orig; temp; temp = temp->next) {
		n_ele++;
	}	

	orig = sort_intersect(l1, l2);

	if (!orig)
		exit(1);

	temp = orig;


	while (temp) {
		printf ("%d", temp->ele);
		temp = temp->next;
	}
	

}

struct node *
sort_intersect (struct node *l1, struct node *l2)
{
	struct node dummy;
	struct node *tail = &dummy;
	tail->next = NULL;

	while (l1 && l2) {
		if (l1->ele == l2->ele) {
			push (&(tail->next), l1->ele);
			tail = tail->next;
		}

		if (l1->ele < l2->ele) 
			l1 = l1->next;
		else
			l2 = l2->next;
	}	

	return (dummy.next);


}

void
push(struct node **list, int ele)
{
	struct node *tmp = NULL;

	tmp = (struct node *) malloc (sizeof(struct node));

	tmp->ele = ele;
	tmp->next = NULL;

	*list = tmp;
} 

	
