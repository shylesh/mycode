#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <setjmp.h>

void sig_alarm (int signo);

jmp_buf env;

int main()
{
	int	ret;
	typedef void (sighandler)();
	char	buf[100];

	/* install handler for alarm */
	if (signal (SIGALRM, sig_alarm) == SIG_ERR)
		err_exit ("installing signal handler failed\n");
	if (setjmp(env) != 0)
		err_exit ("read blocked so failing\n");

	alarm(10);
	if ((ret = read (STDIN_FILENO, buf, sizeof(buf))) == -1)
		err_exit ("read failed\n");
	alarm (0);

	return;
}

void
sig_alarm (int signo)
{
	longjmp (env, 1);
}

