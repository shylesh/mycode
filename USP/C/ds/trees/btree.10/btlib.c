#include <stdio.h>
#include <stdlib.h>
#include "bt.h"



#define max(x, y) ((x > y)?x : y)
struct node *
get_newnode (int ele);

void
print_tree_path (struct node *, int a[], int ele);

struct node *
insert (struct node *root, int ele)
{
	struct node *addr = NULL;

	if (!root) {	/*allocate new node */
		addr = get_newnode(ele);
		return addr;
	}

	else {
		if (ele < root->ele)
			root->left = insert(root->left, ele);
		else
			root->right = insert (root->right, ele);
	}

	return (root);
}


struct node *
get_newnode (int ele)
{
	struct node *ptr = NULL;

	ptr = (struct node *) malloc (sizeof (*ptr));

	ptr->ele = ele;
	ptr->left = NULL;
	ptr->right = NULL;

	return ptr;

}

void
print_tree (struct node *root)
{

	if (!root)
		return;
	else if (!(root->left) && !(root->right)) {
			printf ("%d", root->ele);
			return;
	}
	else {
		print_tree (root->left);
		print_tree (root->right);
		printf ("%d", root->ele);
	}
	return;
}

int
size (struct node *root)
{
	int count;

	if (!root)
		return 0;
	else if (!(root->left) && !(root->right))
		return 1;
	else
		count = 1 + size(root->left) + size(root->right);

	return count;
}

int
max_depth (struct node *root)
{

	int depth ;
	if (!root)
		return 0;

	else if (!(root->right) && !(root->left))
		return 1;
	else
		depth = 1 + max(max_depth(root->right) , max_depth(root->left));

	return depth;


}

int
has_path_sum (struct node *node, int sum)
{
	int ret = NOT_FOUND;

	if (!node)
		return;
	else
		if  (!(node->left) && !(node->right)) {
			sum = sum - node->ele;
			if (!sum)
				return FOUND;
			else
				return NOT_FOUND;
		}
	else {
		ret = ret || has_path_sum(node->left, (sum - (node->ele)));
		ret = ret || has_path_sum (node->right, (sum - (node->ele)));
	}

	return ret;
}

void print_paths (struct node *root)
{
	int path[1000];
	int len = 0;

	print_tree_path (root, path, len);

}

void print_tree_path (struct node *root, int path[], int len)
{
	int i;

	if (!root)
		return;

	if (!(root->left) && !(root->right)) {
		for (i = 0; i < len; i++)
			printf ("%d ", path[i]);
		printf ("%d\n", root->ele);
	}
	else  {
		path[len++] = root->ele;
		print_tree_path(root->left, path, len);
		print_tree_path(root->right,path, len);
	}

	return;
}

void mirror (struct node *root)
{
	struct node *temp = NULL;

	if (!root)
		return;

	else {
		temp = root->right;
		root->right = root->left;
		root->left = temp;
		mirror (root->right);
		mirror (root->left);
	}

	return;
}


void doubletree (struct node *root)
{

	struct node *new = NULL;
	struct node *temp = NULL;

	if (!root)
		return;

	else {
		new = get_newnode (root->ele);
		temp = root->left;
		root->left = new;
		new->left = temp;

		doubletree (root->left->left);
		doubletree (root->right);

	}

	return;
}


void
same (struct node *t1, struct node *t2)
{
	int ret = 0;

	ret = trav_tree (t1, t2);

	if (ret)
		printf ("same\n");
	else
		printf ("not same\n");

}

int
trav_tree(struct node *root1, struct node *root2)
{
	int same = 0;


	if (!root1 && !root2)
		return 1;
	else if ((root1 && !(root2)) ||
	     !(root1) && root2)
		return 0;

	else if ((root1->ele) == (root2->ele))
	{
		same = 1;
		same = trav_tree (root1->left, root2->left ) &&  trav_tree (root1->right, root2->right);
	}
	else	same = 0;

	return same;
}
