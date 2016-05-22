#include <stdio.h>

int * tab()
{

	
}


void victim()
{
	int *p;

	p = tab();
	printf ("%d", *p);
}

int main()
{
	victim();
}
