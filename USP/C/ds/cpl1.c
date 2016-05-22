#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int 		data;
	struct node	*next;
}NODE;

int main()
{
	NODE	*n1 = NULL;
	NODE	*n2 = NULL;
	NODE	*n3 = NULL;
	NODE	*head = NULL;
	NODE	*nhead = NULL;
	NODE	*tail = NULL;
	NODE	*current = NULL;
	


	n1 = (NODE *) malloc (sizeof(NODE));
	n2 = (NODE *) malloc (sizeof(NODE));
	n3 = (NODE *) malloc (sizeof(NODE));

	head = n1;
	n1->data = 1;
	n1->next = n2;

	n2->data = 2;
	n2->next = n3;

	n3->data = 3;
	n3->next = NULL;

	current = head;

	while (current ) {
		if (!nhead) {
			nhead = (NODE *) malloc (sizeof(NODE));
			nhead->data = current->data;
			nhead->next = NULL;
			tail = nhead;
		}

		else {
			tail->next = (NODE *) malloc (sizeof(NODE));
			tail = tail->next;
			tail->data = current->data;
			tail->next = NULL;
		}

		current = current->next;
	}

	printf ("after copying thecontents of the list are\n");
	current = nhead;

	while (current) {
		printf ("%d", current->data);
		current = current->next;
	}
}	


		
