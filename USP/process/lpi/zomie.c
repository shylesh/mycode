#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <libgen.h>

int
main(int argc, char *argv[])
{

	pid_t		pid;
	char		cmd[100] = {0, };

	setbuf (stdout, NULL);

	switch (pid = fork()) {
	case -1:	err_exit ("fork failed\n");

	case 0: printf ("inside child \n");
		_exit(0);

	default: break;
	}

	sleep (10);

	snprintf (cmd, 100, "ps aux| grep a.out", basename(argv[0]));
	printf ("cmd = %s", cmd);
	system (cmd);
	sleep(10);

	exit (0);
}

