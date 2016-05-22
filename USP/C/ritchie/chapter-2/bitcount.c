#include <stdio.h>

int bitcount(int x);

int main()
{
	int	x = 0xF;
	int	count;

	count = bitcount(x);

	printf ("%d\n", count);
}

int bitcount(int x)
{
	int	count = 0;

	while (x){
		x &= (x-1);
		count++;
	}
	return count;
}
	
