#include <stdio.h>
#include <unistd.h>

int
main(int argc, char *argv[])
{
	int	i;
	char	**ptr;
	extern char**	environ;

	printf ("execd: %d\n", getppid());

	printf ("welcome\n");
	for (i = 0; i < argc; i++)
		printf ("%d:%s\n", i, argv[i]);

	/* print env */
	for (ptr = environ; *ptr != NULL; ptr++)
		printf ("%s\n", *ptr);
	printf ("sleeping\n");
	printf ("awakened\n");


	exit (0);
}
