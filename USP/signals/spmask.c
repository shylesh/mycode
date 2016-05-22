#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

void sighandler (int signal);

int
main()
{

	sigset_t	newset, oldset, procmask;
	int		ret;

	if (signal (SIGQUIT, sighandler) == SIG_ERR)
		err_exit ("installing handler failed\n");

	/*add block SIGQUIT */
	if (sigemptyset(&newset) == -1)
		err_exit ("intializing newset failed\n");

	if (sigaddset(&newset, SIGQUIT) == -1)
		err_exit ("adding signal to set failed\n");

	if (sigprocmask (0, NULL, &oldset) == -1)
		err_exit ("procmask failed\n");

	if (sigprocmask (SIG_BLOCK, &newset, NULL) == -1)
		err_exit ("block failed\n");

	sleep (5);

	/* show pending sinal */
	if (sigpending (&procmask) != -1) {
		if (sigismember(&procmask, SIGQUIT) != -1)
			printf ("SIGQUIT is in pending list\n");
		else
			err_exit ("sigismember failed\n");
	}

	/* unblock the signal by  SIGSETMASK */
	if (sigprocmask (SIG_SETMASK, &oldset, NULL) == -1)
		err_exit ("unblocking failed\n");

	sleep(5);

}

void
sighandler (int signum)
{
	printf ("caught SIGQUIT\n");
}
