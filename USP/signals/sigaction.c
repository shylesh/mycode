#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

void handle (int signum);

int main()
{

	int	ret;
	int	i = 1000000;
	struct sigaction sig;


	/* fill sigaction structure */
	sig.sa_handler = SIG_IGN;

	/* fill with empty signal set */
	if (sigemptyset(&sig.sa_mask) == -1)
		err_exit ("sigemptyset failed\n");

	/* reset the flags */
	sig.sa_flags = 0;

	if (sigaction (SIGINT, &sig, NULL) == -1)
		err_exit ("sigaction failed\n");

	//while (i--)	printf ("while\n");
	sleep(10);

	printf (" i am back\n");
}

void
handle (int signum)
{

	printf ("caught sigint \n");

}
