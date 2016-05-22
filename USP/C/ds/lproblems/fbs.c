#include <stdio.h>
#include <stdlib.h>
#include <string.h>
	

struct node {
	int ele;
	struct node *next;
};

void
fb_split(struct node **orig_ref, struct node **l1, struct node **l2, int n_ele);

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
	n1->next = n2;
	n2->ele = 2;
	n2->next = NULL;
//	n3->ele = 3;
//	n3->next = n4;
//	n4->ele = 4;
//	n4->next = n5;
//	n5->ele = 5;
//	n5->next = NULL;
//	n6->ele = 6;
//	n6->next = NULL;
//	n7->ele = 7;
//	n7->next = n8;
//	n8->ele = 8;
//	n8->next = n9;
//	n9->ele = 9;
//	n9->next = NULL;

	for (temp = orig; temp; temp = temp->next) {
		n_ele++;
	}	

	fb_split(&orig, &l1, &l2, n_ele);

	printf ("after split list l1 is \n");
	temp = l1;


	while (temp) {
		printf ("%d", temp->ele);
		temp = temp->next;
	}
	
	printf ("after split list l2 is \n");

	temp = l2;

	while (temp) {
		printf ("%d", temp->ele);
		temp = temp->next;
	}
}
			
/*void
fb_split(struct node **orig, struct node **l1, 
	 struct node **l2, int nele)
{
	struct node *fp = NULL;
	struct node *sp = NULL;
	struct node *tmp = NULL;
	struct node *prev = NULL;
	int l1_count = 0;
	int i = 0;

	*l1 = *orig;

	if (nele <= 1) 
		return;
	

	if(!(nele % 2)) 
		l1_count = (nele / 2);
	else
		l1_count = (nele / 2) + 1;

	for (tmp = *l1; i < l1_count; i++) {
		prev = tmp;
		tmp = tmp->next;
	}

	//split here
	
	prev->next = NULL;
	*l2 = tmp;

} */

void
fb_split (struct node **orig, struct node **l1, 
	  struct node **l2, int nele)
{
	struct node *fp = NULL;
	struct node *sp = NULL;
	struct node *prev = NULL;
	int even = (!(nele % 2));

	fp = sp = *orig;

	*l1 = *orig;

	if (nele <= 1)
		return;
		
	while (fp->next) {
	
		prev = sp;
		sp = sp->next;
	
		if (!(fp->next->next))	
			fp = fp->next;
		else
			fp = fp->next->next;
	}

	if (!even)   {
		prev = sp;
		sp = sp->next;
	}
	*l2 = sp;
	prev->next = NULL;
}
		

	
	
