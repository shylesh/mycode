#include <stdio.h>
#include <sys/types.h>
#include <errno.h>
#include <sys/wait.h>
#include <unistd.h>

int
my_system (char	*cmd);

int
main(int argc, char *argv[])
{

	return (my_system(argv[1]));

}

int
my_system (char *cmd)
{

	int	status;
	int	ret = -1;
	pid_t	pid;

	if ((pid = fork()) == -1)
		ret = -1;
	else if (pid == 0) {
		execl ("/bin/sh", "sh", "-c", cmd, NULL);
		_exit(-1);
	}
	else {
		while (waitpid (pid, &status, 0) < 0){
			if (errno != EINTR) {
				ret = -1;
				break;
			}

		}
	}

	printf ("%d", ret);
	return (ret);

}

