#include <stdlib.h>
#include <stdio.h>

static void my_exit1 (void);
static void my_exit2 (void);

int main()
{

	printf ("hello world\n");

	if (atexit (my_exit1))
		err_exit ("atexit failed for e1\n");
	exit (0);

	if (atexit (my_exit2))
		err_exit ("atexit failed for e2\n");
}

static void
my_exit1 (void)
{

	printf ("inside  exit1\n");

}

static void
my_exit2 (void)
{

	printf ("inside  exit2\n");
	exit (0);

}


