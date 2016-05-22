#include <stdio.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{

	pid_t	pid;
	int	ret;

	if ((pid = fork()) == -1)
		err_exit ("fork failed\n");

	if (pid == 0) 	{
		sleep (10);
		ret = system ("ps aux");
		if (ret == -1)
			err_exit ("system failed\n");
		exit (0);
	} 	else 	{
			printf ("inside paretn\n");
			printf ("not waiting\n");
		}
		exit (0);
}
