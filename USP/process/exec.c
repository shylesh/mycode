#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

char	*env_arr[] = {"USER=unknown", "PATH=/tmp", NULL};

int
main (void)
{
	pid_t	pid;
	int	ret;

	if ((pid = fork()) == -1)
		err_exit ("fork failed\n");
	else if (pid == 0) {
		printf ("inside first child: %d\n", getpid());
		if (execle ("./execute", "execute", "myprog", (char *) 0, env_arr) < 0)
			err_exit ("exec failed\n");
	}
	printf ("parent: %d\n", getpid());


	printf ("returned from : %d\n", pid);

	if (WIFEXITED(ret))
		printf ("normal exit\n");
	else if (WIFSIGNALED(ret))
		printf ("%d\n", WTERMSIG(ret));

	exit (0);
}
