#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{

	char		*argvec[10];
	char		*envec[10] = { "myname=shylesh",
				       "iam=don",
				       NULL
				     };

	/* prepare argv for calle */

	argvec[0] = strrchr (argv[1], '/');

	if (!argvec[0])
		argvec[0] = argv[1];
	else
		argvec[0]++;

	argvec[1] = "HELLO";
	argvec[2] = "WORLD";
	argvec[3] = NULL;

	execve (argvec[0], argvec, envec);

	err_exit ("exec failed\n");

}
