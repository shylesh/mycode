#include <stdio.h>
#include <stdlib.h>
#include "bt.h"


#define max(x, y) ((x > y)?x : y)
struct node *
get_newnode (int ele);

struct node *
insert (struct node *root, int ele)
{
	struct node *addr;

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
