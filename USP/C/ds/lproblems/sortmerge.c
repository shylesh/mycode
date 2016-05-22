#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct node {
	int ele;
	struct node *next;
};

void
mvnode( struct node **l1,
	struct node **l2);

struct node *
sort_merge(struct node *l1,
		struct node *l2);

int main()
{
	struct node *orig = NULL;
	struct node *l1= NULL;
	struct node *l2= NULL;
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
	int n_ele = 0;


	n1 = (struct node *) malloc (sizeof(struct node));
	n2 = (struct node *) malloc (sizeof(struct node));
	n3 = (struct node *) malloc (sizeof(struct node));
	n4 = (struct node *) malloc (sizeof(struct node));
	n5 = (struct node *) malloc (sizeof(struct node));
	n6 = (struct node *) malloc (sizeof(struct node));
	n7 = (struct node *) malloc (sizeof(struct node));
	n8 = (struct node *) malloc (sizeof(struct node));
	n9 = (struct node *) malloc (sizeof(struct node));

	l1 = n1;
	n1->ele = 1;
	n1->next = n2;
	n2->ele = 15;
	n2->next = n3;
	n3->ele = 21;
	n3->next = n4;
	n4->ele = 30;
	n4->next = n5;
	n5->ele = 35;
	n5->next = NULL;


	l2 = n6;
	n6->ele = 19;
	n6->next = n7;
	n7->ele = 25;
	n7->next = n8;
	n8->ele = 31;
	n8->next = n9;
	n9->ele = 39;
	n9->next = NULL;

	for (temp = orig; temp; temp = temp->next) {
		n_ele++;
	}

	orig = sort_merge(l1, l2);

	temp = orig;


	while (temp) {
		printf ("%d", temp->ele);
		temp = temp->next;
	}


}

/*struct node *
sort_merge (struct node *a, struct node *b)
{

	struct node *list = NULL;
	struct node *tmp  = NULL;
	struct node *tmp1 = NULL;
	struct node *prev = NULL;
	int	flag = 0;

	if (!a)
		return list = b;
	else if(!b)
		return list = a;

	else
		if (a->ele < b->ele)  {
			tmp = list = a;
			tmp1 = b;

		}

		else  {
			tmp = list = b;
			tmp1 = a;
		}

	while (tmp && tmp1) {
		if (tmp->ele < tmp1->ele) {
			prev = tmp;
			tmp = tmp->next;
			continue;
		}

		prev->next = tmp1;

		if (tmp1->next->ele && (tmp->ele < tmp1->next->ele)) {
			tmp1 = tmp1->next;
			prev->next->next = tmp;
			prev = tmp;
			tmp = tmp->next;

			continue;
		}
		else  {
			tmp1->next = tmp;
			break;
		}



		prev->next->next = tmp1->next;
		tmp1 = tmp;
		tmp = prev->next->next;
	}

	if ((tmp == NULL) && tmp1)

		prev->next = tmp1;
	else if (tmp && (tmp1 == NULL))
*/


/*struct node *
sort_merge (struct node *a, struct node *b)
{
	struct node dummy;
	struct node *tail = &dummy;



	while (1) {
		if (a == NULL) {
			tail->next = b;
			break;
		}
		else
			if (b == NULL) {
				tail->next = a;
				break;
			}

		else {
			if (a->ele < b->ele)
				mvnode (&(tail->next), &a);

			else
				mvnode (&(tail->next), &b);
		    }
		tail = tail->next;
	}

	return (dummy.next);
}
*/

/*struct node *
sort_merge (struct node *a, struct node *b)
{
	struct node *head = NULL;
	struct node **localref = &head;



	while (1) {
		if (a == NULL) {
			*localref = b;
			break;
		}

		else
			if (b == NULL) {
				*localref = a;
				break;
			}
		else {
			if (a->ele < b->ele)
				mvnode (localref, &a);
			else
				mvnode (localref, &b);
		}

		localref = (&(*localref)->next);
	}

	return head;
} */

struct node *
sort_merge (struct node *a, struct node *b)
{

	struct node *head = NULL;

	if (a == NULL)	return b;
	else
		if (b == NULL) return a;

	else  {
		if (a->ele < b->ele) {
			head = a;
			head->next = sort_merge (a->next, b);
		}
		else {
			head = b;
			head->next = sort_merge (a, b->next);
		}
	}

	return head;
}

























