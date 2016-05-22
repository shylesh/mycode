#include <stdio.h>
#include <stdlib.h>
#include <string.h>
	

struct node {
	int ele;
	struct node *next;
};

struct node *
append (struct node **aref, struct node **bref);

int main()
{
	struct node *ahead = NULL;
	struct node *bhead = NULL;
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
	n1->next = n2;
	n2->ele = 2;
	n2->next = n3;
	n3->ele = 3;
	n3->next = n4;
	n4->ele = 4;
	n4->next = NULL;

	bhead = n5;
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

	append(&ahead, &bhead);

	printf ("after appending the list is \n");

	temp = ahead;

	while (temp) {
		printf ("%d", temp->ele);
		temp = temp->next;
	}
	printf ("val of b is %d\n", bhead);
	
}
			

struct node *
append (struct node **aref, struct node **bref)
{
	struct node *temp = NULL;
	struct node *tail = NULL;

	temp = *bref;

	tail = *aref ;

	if(!tail) {
		if(*aref = *bref) {
			*bref = NULL;
			return *aref;
		}
	
		return NULL;
	}

	

	while (tail->next)
		tail = tail->next;


		tail->next = temp;
	


	*bref = NULL;

	return *aref;
}

		
