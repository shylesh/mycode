#include <stdio.h>
#include <stdlib.h>

void 		push (struct node **ref, int val);
struct node *	cp(struct node *l1);

typedef struct node {
	int	val;
	struct node *next;
} NODE;

void push (struct node **ref, int val)
{
	struct node *new = NULL;

	new = (NODE *) malloc(sizeof(NODE));
	new->data = val;
	new->next = NULL;

	*ref->next = new;
}

struct node *
cp (struct node *l1)
{
	struct node *current = l1;
	struct node *new = NULL;
	struct node *tail = NULL;
	

	while (current) {
		if (!new) {
			push(&new, current->data);
			
			
		
	
	
