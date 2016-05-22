#include <stdio.h>
#include <stdlib.h>


struct node {
	int		data;
	struct node	*next;
} ;

int	l_length(struct node *ptr);

int main()
{
	struct node *head = NULL;
	struct node *second = NULL;
	int 	    len = 0;


	head = (struct node *) malloc (sizeof(*head));
	second = (struct node *) malloc (sizeof(*second));

	head->next = second;
	second->next = NULL;

	len = l_length(head);
	printf ("length of the list is %d\n", len);
}

int
l_length(struct node *ptr)
{
	struct node *temp;
	int count = 0;

	temp = ptr;

	while (temp) {
		count++;
		temp = temp->next;
	}

	return count;
}

	
