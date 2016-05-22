#include <stdio.h>

struct node {
	int a;
	int b;
	int c;
} node_arr[] = {
	1,2,3,
	3,4,4,
	5,6,5
	};

int main()
{
	struct node *ptr;
	struct node a;
	struct mix {
		char c;
		int a;
		char ac;
	} ai;

	printf ("size of mix is %d\n", sizeof(ai));
	
	a.a = 10;
	a.b = 20;

	ptr = &a;

	printf ("size of ptr is %d", sizeof(ptr));
	printf ("size of a is %d", sizeof(a));
	printf ("size of the array is %d", sizeof(node_arr[0]));
}
	
