#include <stdio.h>
#include <stdlib.h>
#include "bt.h"


int main()
{

	char ch;
	int ele;
	struct node *root = NULL;

	while(1) {
		printf ("I/i to insert\n");
		printf ("P/p to print\n");

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
		default: printf ("pls provide proper input\n");
		}
	}
}	

	
