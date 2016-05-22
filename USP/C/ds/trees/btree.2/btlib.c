#include <stdio.h>
#include <stdlib.h>
#include "bt.h"

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

	printf ("inside print_tree\n");
	if (!root)
		return;
	else if (!(root->left) && !(root->right)) { 
			printf ("%d", root->ele);
			return;
	}
	else {
		print_tree (root->left);
		printf ("%d", root->ele);	
		print_tree (root->right);
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
