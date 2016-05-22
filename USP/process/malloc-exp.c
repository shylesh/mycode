#include <stdio.h>
#include <stdlib.h>

int main()
{
	char	*mem;
	int	i;

	mem = (char *) malloc (100);

	for (i = 0; i < 100; i++)
		printf ("%d\n", mem[i]);



}
