#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *next;
};
	

void push(struct node *head_ref, int data)
{
	struct node *ptr = NULL;
	ptr = (struct node *) malloc (sizeof(*ptr));

	ptr->data = 1;
	ptr->next = head_ref;
	head_ref = ptr;

}

int main()
{
	struct node *head = NULL;
	struct node *n1 = (struct node *) malloc (sizeof(n1));
	struct node *n2 = (struct node *) malloc (sizeof(n2));
	struct node *tmp = NULL;

	n1->data = 2;
	n1->next = n2;
	

	n2->data = 3;
	n2->next = NULL;

	head = n1;

	push(head, 1);

	for (tmp = head; tmp; tmp = tmp->next) {
		printf ("%d\t", tmp->data);
	}	

}
	


