#include <stdio.h>

int main(int argc, char	*argv[])
{

	extern char	**environ;
	int 		i;

	for (i = 0; i < argc; i++)
		printf ("%s\n", argv[i]);

	while (*environ)
		printf ("%s", *(environ++));



}
