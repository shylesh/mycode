#include <stdio.h>

#define MAX(a, b)	(a > b) ? a : b
#define SQUARE(x)	(x * x)

int main()
{
	int	i = 2;
	int	j = 10;

	printf ("%d\n", MAX(i++, j++));
	printf ("%d", SQUARE(i++)); 
}
