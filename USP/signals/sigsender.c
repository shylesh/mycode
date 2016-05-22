#define _POSIX_C_SOURCE  199309

#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <string.h>

void siaction (int signum, siginfo_t *sp, void *cont);

int main()
{

	struct sigaction	act;

	act.sa_sigaction = siaction;
	sigemptyset(&act.sa_mask);
	act.sa_flags = SA_SIGINFO;

	if (sigaction (SIGINT, &act, NULL) == -1)
		err_exit ("sigaction failed\n");

	sleep(10);
}

void
siaction (int signum, siginfo_t *sp, void *cont)
{

	printf ("inside handler\n");

	printf ("recieved  is %d\n", sp->si_signo);
	printf ("sender is %d\n", sp->si_pid);

}
