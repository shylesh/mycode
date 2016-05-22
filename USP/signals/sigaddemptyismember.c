#include <string.h>
#include <signal.h>
#include <stdio.h>

int main()
{
	sigset_t	sign;
	int		signum;

	if (sigemptyset (&sign) == -1)
		err_exit ("sigemptyset failed\n");

	/* set only SIGINT */
	if (sigaddset (&sign, SIGINT) == -1)
		err_exit ("failed to set SIGINT\n");

	/* inspect the signal mask to check what has been set */
	for (signum = 1; signum <= NSIG; signum++) {
		if (sigismember (&sign, signum))
			printf ("%d--> %s\n", signum, strsignal(signum));

	}
}
