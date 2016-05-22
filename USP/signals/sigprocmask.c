#include <signal.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
	sigset_t	*set;
	sigset_t	*oldset;
	int		ret;

	oldset = (sigset_t *) malloc (sizeof(sigset_t));
	set = (sigset_t *) malloc (sizeof(sigset_t));

	if (sigemptyset (set) == -1)
		err_exit ("sigempty set failed\n");

	if (sigaddset (set, SIGINT) == -1)
		err_exit ("sigaddset failed\n");

	 /* get the oldset */
	if (sigprocmask (SIG_BLOCK, NULL, oldset) == -1)
		err_exit ("getting old sigset failed\n");

	/* add SIGINT to the set */
	if (sigprocmask (SIG_BLOCK, set, oldset) == -1)
		err_exit ("sigprocmask failed\n");

	/* want to sleep uninterruptibly */
	sleep (25);

	/* restore back */
	if (sigprocmask (SIG_SETMASK, oldset, NULL) == -1)
		err_exit ("revert back failed\n");

	/* now check again */
	sleep(25);

	return;
}

