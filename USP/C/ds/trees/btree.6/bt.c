#include <stdio.h>
#include <stdlib.h>
#include "bt.h"


int main()
{

	char ch;
	int ele;
	struct node *root = NULL;
	int num;
	int depth = 0;

	while(1) {
		printf ("I/i to insert\n");
		printf ("P/p to print\n");
		printf ("C/c to count\n");
		printf ("D/d to max_depth\n");

		scanf (" %c", &ch);
		switch(ch) {
		case 'i': case 'I': 
			printf ("enter ele\n");
			scanf("%d", &ele);	
			root = insert(root, ele);
			break;

		case 'p': case 'P':
			print_tree(root);
			break;
		case 'c': case 'C':
			num = size(root);
			printf ("number of nodes = %d\n", num);		
			break;
		case 'd':
			depth = max_depth(root);
			printf ("max depth is %d\n", depth);
			break;	
		default: printf ("pls provide proper input\n");
		}
	}
}	

	
