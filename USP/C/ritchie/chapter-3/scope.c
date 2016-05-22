#include <stdio.h>

int i = 0;

int main()
{
	int i = 2;
	printf ("printf %d\n", i);
	{
		int i = 3;
		printf ("%d\n", i);
	}
	printf ("%d\n", i); 
}
