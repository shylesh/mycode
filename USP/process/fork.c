#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

int main()
{
	pid_t	pid;
	int	status;

	if ((pid = fork()) == -1)
		err_exit ("fork failed\n");
	else if (pid == 0) {
		/* inside child */
		printf ("inside child : %d\n", getpid());
		raise(SIGKILL);
		exit (0);
	}
	else

		/*inside parent */
		wait (&status);

		WIFEXITED(status) ? printf ("child successfully exited with status %d\n",
				   WEXITSTATUS(status)): printf ("child exited abnormally\n");

		WIFSIGNALED (status) ? printf ("%d\n", WTERMSIG (status)) :
				       printf (" ");
}
