#include <stdio.h>
#include <signal.h>
#include <setjmp.h>
#include <time.h>
#include <stdlib.h>

static void 			sig_usr1 (int signum);
static void			sig_alarm (int signum);
static void			pr_mask ();
static sigjmp_buf		maskbuf;
static volatile sig_atomic_t 	canjump;


int
main()
{

	/* install handlers */
	if (signal (SIGUSR1, sig_usr1) == SIG_ERR)
		err_exit ("signal failed\n");

	if (signal (SIGALRM, sig_alarm) == SIG_ERR)
		err_exit ("signal failed\n");

	if (sigsetjmp (maskbuf, 1) != 0) {
		printf ("\nmain\n");
		pr_mask ();
		exit (0);
	}

	canjump = 1;

	pause();



}


static void
sig_usr1 (int sig)
{
	time_t	start_time;

	printf ("inside usr1\n");
	pr_mask();
	alarm(3);

	start_time = time(NULL);

	for ( ; ;)
		if (time(NULL) > start_time + 5)
		break;
	pr_mask();
	canjump = 0;

	siglongjmp (maskbuf, 1);




}


static void
sig_alarm (int sig)
{

	printf ("inside alarm\n");
	pr_mask();


}

static void
pr_mask ()
{

	sigset_t	set;
	int		i;

	if (sigprocmask (0, NULL, &set) == -1)
		err_exit ("sigprocmask failed\n");

	for (i = 1; i < NSIG; i++) {
		if (sigismember (&set, i)) {
			if (i == 14)	printf ("SIGALARM");
			else if (i == 10) printf ("SIGUSR1");

		}

	}

}

