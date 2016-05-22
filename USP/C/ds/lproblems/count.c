#include <stdio.h>
#include <stdlib.h>

struct node {
	int val;
	struct node *next;
};

int count_list (struct node *head, int key);
void delete_list (struct node **head);

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

	count = count_list (head, 2);
	printf ("count is %d\n", count);
	delete_list(&head);
}

int 
count_list (struct node *head, int key)
{

	struct node *tmp = head;
	int count = 0;

	while (tmp) {
		if (tmp->val == key)
			count++;
		tmp = tmp->next;
	}

	return count;
}
	
	
void
delete_list (struct node **head)
{
	struct node *tmp = *head;
	struct node *tmp1 ;

	while (tmp1 = tmp) {
		tmp = tmp->next;
		free(tmp1);
	}

	*head = NULL;
}
			
	

	
