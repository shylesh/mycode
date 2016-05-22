#include <stdio.h>
#include <stdlib.h>

struct node {
	int ele;
	struct node *next;
};

void push(struct node **ref, int ele);
void buildlist(struct node **head);

int main()
{
	struct node *head = NULL;
	struct node *temp = NULL;
	
	buildlist(&head);
	push(&head, 1);
	
	printf ("elements of the list are\n");
	
	temp = head;
	while (temp) {
		printf ("%d\n", temp->ele);
		temp = temp->next;
	}
}

void buildlist(struct node **head)
{
	struct node *n1, *n2, *n3;

	n1 = (struct node *) malloc(sizeof (*n1));
	n2 = (struct node *) malloc(sizeof (*n2));
	n3 = (struct node *) malloc(sizeof (*n3));

	
	*head = n1;
	n1->ele = 2;
	n1->next = n2;
	n2->ele = 3;
	n2->next = n3;
	n3->ele = 4;
	n3->next = NULL;
}

void push(struct node **head_ref, int ele)
{
	struct node *temp;

	temp = (struct node *) malloc (sizeof(struct node));
	temp->ele = 1;
	temp->next = *head_ref;
	*head_ref = temp;
} 
