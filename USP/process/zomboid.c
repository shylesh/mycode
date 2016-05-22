#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{

	pid_t	pid;
	int	ret;

	if ((pid = fork()) == -1)
		err_exit ("fork failed\n");
	else if (pid == 0) {
		if ((pid = fork()) == -1)
			err_exit ("fork failed inside first child\n");
		else if (pid == 0) {
			printf ("inside second child\n");
			printf ("my parent is %d\n", getppid());
			sleep(1000);
		}
		else
			exit (0);
	}
	else
		if (wait (&ret) == -1)
			err_exit ("wait failed\n");
}
