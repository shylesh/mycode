#include <stdio.h>

#define MASK 0177

int main()
{
	int	a = 1024;

	printf ("%d\n", a);

	a = a & MASK;

	printf ("%d", a);
}
