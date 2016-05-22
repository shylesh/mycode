#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

void handle (int signum)
{
	if (signum == SIGABRT)
		return;
}

int
main()
{

	signal (SIGABRT, handle);
	abort();
	printf ("back to main\n");

}
