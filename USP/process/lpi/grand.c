#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{

	pid_t		pid;

	switch (fork()) {

	case -1:	err_exit ("fork failed\n");

	case 0:		switch (fork()) {
			case -1: err_exit ("fork failed\n");
			case 0:  while (1)	printf ("%d\n", getppid());
			default: _exit(0);
			}

	default: sleep(10);
	}

	wait (NULL);
	printf ("done waiting\n");
}
