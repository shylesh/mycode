#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct node {
	int val;
	struct node *next;
};

int insert(struct node **head, int index, int ele);

int main()
{
	struct node *head = NULL;
	struct node *n1, *n2, *n3, *n4;
	struct node *tmp;
	int count = 0;
	int ele, index = 3, i;

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

	for (tmp = head,i = 0 ; i < (index - 1); i++, tmp = tmp->next)
		;
	
	insert(&(tmp->next), index, 8 );

	printf ("after insertion\n");
	tmp = head;

	while (tmp) {
		printf ("%d,", tmp->val);
		tmp = tmp->next;
	}	

	
	

}

int 
insert (struct node **head, int index, int ele)
{
	struct node *tmp = *head;
	struct node *new = (struct node *) malloc (sizeof(*new));	
	
	new->val = ele;
	new->next = tmp;
	*head = new;
	return 0;	

}
	
