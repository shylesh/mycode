#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
	do_daemon();

}

do_daemon()
{
	pid_t	pid;

	pid = fork();

	if (pid == -1)
		exit(1);
	else if (pid)
		exit (0);

	if (setsid() == -1)
		return;
	close (STDIN_FILENO);
	close (STDOUT_FILENO);
	close (STDERR_FILENO);

	while(1);
}
