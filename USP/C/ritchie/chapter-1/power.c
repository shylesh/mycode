#include <stdio.h>

int power(int base, int pow);

int main()
{
	int base = 2;
	int pow = 3;


	printf ("%d %d", power(base, pow), power(base, 8));
}
	
int
power (int base, int pow) 
{
	int	i;
	int 	ret = 1;

	for (i = 0; i < pow; i++)
		ret *= base;	
	return ret;
}
