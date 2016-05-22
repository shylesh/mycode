#include <stdio.h>

#define SWAP(type, a, b) \
	type temp;	 \
	temp = a;	 \
	a = b;		 \
	b = temp;

int main()
{
	int	i = 10;
	int 	j = 20;

	SWAP(int, i, j);
	printf ("%d\t%d", i, j);
}
	
	
