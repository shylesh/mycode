#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

void
handler ()
{

}

int
main()
{

	pid_t			pid;
	sigset_t		new, old, empty;
	struct sigaction	act;
	int			status;

	sigemptyset (&empty);
	sigemptyset (&act.sa_mask);
	sigaddset (&act.sa_mask, SIGUSR1);
	act.sa_flags = SA_RESTART;
	act.sa_handler = handler;

	setbuf (stdout, NULL);

	if (sigaction(SIGUSR1, &act, NULL) == -1)
		err_exit ("sigaaction failed\n");

	if (sigprocmask (SIG_BLOCK, &act.sa_mask, NULL) == -1)
		err_exit ("sigprcmask failed\n");

	switch (pid = fork()) {
	case -1:	printf ("fork failed\n");
			err_exit ("fork failed\n");

	case 0:		printf ("msg1 from child\n");
			/*send SIGUSR1 to parent and wait */
			if (kill (getppid(), SIGUSR1) == -1)
				err_exit ("kill failed\n");

			if (sigsuspend (&empty) == -1)
				;

			printf ("msg3 from child\n");
			_exit(0);

	default: break;
	}


	/* wait for firt signal from child */
	if ((sigsuspend (&empty) == -1) && errno == EINTR )
		;

	printf ("inside parent\n");
	printf ("msg2 inside parent \n");

	/* send signal to child */
	if (kill (pid, SIGUSR1) == -1)
		err_exit ("kill failed in parent\n");

	wait (&status);

	exit (0);

}
