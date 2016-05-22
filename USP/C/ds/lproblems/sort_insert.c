#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct node {
	int val;
	struct node *next;
};

struct node *alloc_node( int ele);
int sorted_insert (struct node **head, struct node *new);

int main()
{
	struct node *head = NULL;
	struct node *n1, *n2, *n3, *n4;
	struct node *tmp;
	struct node *new;
	int count = 0;
	int ele, index = 3, i;

	n1 = (struct node *) malloc (sizeof(n1));
	n2 = (struct node *) malloc (sizeof(n2));
	n3 = (struct node *) malloc (sizeof(n3));
	n4 = (struct node *) malloc (sizeof(n4));

	head = n1;

	n1->val = 1;
	n2->val = 3;
	n3->val = 4;
	n4->val = 5;

	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next = NULL;

	for (tmp = head,i = 0 ; i < (index - 1); i++, tmp = tmp->next)
		;
	
	new = alloc_node(0);
	sorted_insert(&head, new);

	printf ("after insertion\n");
	tmp = head;
	while (tmp) {
		printf ("%d,", tmp->val);
		tmp = tmp->next;
	}	

	
	

}

struct node *
alloc_node (int ele)
{
	struct node *new = (struct node *) malloc (sizeof(*new));	
	
	new->val = ele;
	new->next = NULL;

	return new;

}
	
int
sorted_insert (struct node **head, struct node *new)
{
	struct node *temp = *head;
	struct node *prev= temp;


	printf ("inside sorted_insert\n");
	while (temp) {
		if (temp->val <= new->val) {
			prev = temp;
		}
		else {
			if (prev == temp) {
				new->next = *head;
				*head = new;
			}
			else {
				new->next = temp;
				prev->next = new;
			}
			return 0;
			
		}

		temp = temp->next;
	}

	new->next = NULL;
	prev->next = new;
	printf ("returning \n");

	return 1;
}
				
