#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

static volatile sig_atomic_t	quitflag = 0;
static void 			sig_handler(int signum);

int
main()
{

	sigset_t zeroblock, newset, oldset;

	if (signal(SIGINT, sig_handler) == SIG_ERR)
		err_exit ("signal failed\n");

	if (signal(SIGQUIT, sig_handler) == SIG_ERR)
		err_exit ("signal failed\n");

	sigemptyset(&zeroblock);
	sigemptyset (&newset);
	sigaddset (&newset, SIGQUIT);

	if (sigprocmask (SIG_BLOCK, &newset, &oldset) == -1)
		err_exit ("sigprocmask failed\n");

	while (!quitflag)
		sigsuspend(&zeroblock);

	quitflag = 0;

	sigprocmask (SIG_SETMASK, &oldset, NULL);

}

static void
sig_handler (int signum)
{
	if (signum == SIGINT)
		return;
	else if (signum == SIGQUIT)
		quitflag = 1;
}

