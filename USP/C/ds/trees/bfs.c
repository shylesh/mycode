#include <stdio.h>
#include <stdlib.h>

#define MAX	10
#define Q_FULL 2
#define Q_EMPTY 3

int	front = 0;
int	rear  = 0;

struct node {
	int		data;
	struct node 	*right;
	struct node 	*left;
};

typedef struct node NODE;

struct que{
	long long  ele[MAX];
	int	nele;
};

struct que q;

int enq (struct que *, long long ele);
int  deq (struct que *);



NODE * build_tree(int n_nodes);
void bfs(NODE *);

int
main()
{
	NODE	*TPTR = NULL;
	q.nele=0;

	if ((TPTR = build_tree(5)) == NULL) {
		printf ("build tree failed\n");
		err_exit ("btree failed\n");
	}

	bfs(TPTR);
}

NODE *
build_tree (int n_nodes)
{

	NODE	*root = NULL;
	NODE	*n1, *n2, *n3, *n4, *n5 = NULL;

	root = (NODE *) malloc (sizeof(NODE));
	if (!root)
		return NULL;
	root->data = 0;

	n1 = (NODE *) malloc (sizeof(NODE));
	n1->data = 1;

	n2 = (NODE*) malloc (sizeof(NODE));
	n2->data = 2;

	n3 = (NODE*) malloc (sizeof(NODE));
	n3->data = 3;

	n4 = (NODE*) malloc (sizeof(NODE));
	n4->data = 4;

	n5 = (NODE*) malloc (sizeof(NODE));
	n5->data = 5;

	root->left = n1;
	root->right = n2;
	n1->left = n3;
	n1->right = NULL;
	n2->right = n4;
	n2->left = NULL;
	n3->left = n5;
	n3->right = NULL;
	n4->left = NULL;
	n4->right = NULL;
	n5->left = NULL;
	n5->left = NULL;

	return root;
}

int
enq (struct que *q, long long addr)
{
	if (q->nele == MAX)
		return Q_FULL;

	q->ele[rear++] = addr;
	q->nele++;

	return 0;

}

int
deq (struct que *q)
{
	if (q->nele == 0)
		return Q_EMPTY;

	q->nele--;

	return q->ele[front++];

}


void
bfs (NODE *tptr)
{
	NODE 	*current = NULL;

	current = tptr;

	printf ("%d", current->data);

	while (current) {

			if (current->left)
				enq (&q, (long long) current->left);

			if (current->right)
				enq (&q, (long long) current->right);


		printf ("%d ", current->data);

		current = (NODE *) deq (&q);
	}


}
