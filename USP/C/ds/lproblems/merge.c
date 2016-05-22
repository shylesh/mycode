#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
	int ele;
	struct node *next;
};
void
fb_split (struct node **orig, struct node **l1, 
          struct node **l2)
{
        struct node *fp = NULL;
        struct node *sp = NULL;
        struct node *prev = NULL;
	int nele = length(*orig);
        int even = (!(nele % 2));

        fp = sp = *orig;

        *l1 = *orig;

        if (nele <= 1)
                return;
                
        while (fp->next) {
        
                prev = sp;
                sp = sp->next;
        
                if (!(fp->next->next))  
                        fp = fp->next;
                else
                        fp = fp->next->next;
        }

        if (!even)   {
                prev = sp;
                sp = sp->next;
        }
        *l2 = sp;
        prev->next = NULL;
}




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




int
length (struct node *list)
{
	int length = 0;
	struct node *tmp = NULL;

	for (tmp = list; tmp; tmp = tmp->next, length++)
		;

	return length;
}
	

void
merge (struct node **list)
{

	struct node *l1 = NULL;
	struct node *l2 = NULL;


	if (!((*list)->next))
		return ;

	fb_split (list, &l1, &l2);
	
	merge (&l1);
	merge (&l2);

	*list = sort_merge(l1, l2);
}


int
main()
{
	struct node *orig = NULL;
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

	orig = n1;
	n1->ele = 1;
	n1->next = n2;
	n2->ele = 15;
	n2->next = n3;
	n3->ele = 21;
	n3->next = n4;
	n4->ele = 30;
	n4->next = n5;
	n5->ele = 35;
	n5->next = n6;

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

	merge(&orig);
	temp = orig;



	while (temp) {
		printf ("%d", temp->ele);
		temp = temp->next;
	}
	

}

		
