#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct node {
	int val;
	struct node *next;
};

int pop(struct node **head);

int main()
{
	struct node *head = NULL;
	struct node *n1, *n2, *n3, *n4;
	int count = 0;
	int ele;

	n1 = (struct node *) malloc (sizeof(n1));
	n2 = (struct node *) malloc (sizeof(n2));
	n3 = (struct node *) malloc (sizeof(n3));
	n4 = (struct node *) malloc (sizeof(n4));

	head = n1;

	n1->val = 1;
	n2->val = 2;
	n3->val = 3;
	n4->val = 2;

	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next = NULL;

	count = pop(&head);
	count = pop(&head);
	count = pop(&head);
	count = pop(&head);
	printf ("count is %d\n", count);
}

int 
pop (struct node **head)
{
	struct node *tmp = *head;
	int ele;
	
	assert(*head != NULL);

	ele = tmp->val;
	*head = tmp->next;

	free(tmp);

	return ele;
}
