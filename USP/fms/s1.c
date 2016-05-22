#include <stdio.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <stdlib.h>

#define errExit(msg) do { \
	perror (msg); exit (EXIT_FAILURE);\
	} while(0)

int main()
{

	struct rlimit current, new;
	struct rlimit *ptr = &new;

	ptr->rlim_cur = 1;
	ptr->rlim_max=2;

	if (prlimit (0, RLIMIT_NPROC, ptr, &current) == -1)
		errExit ("prlimit failed");
	printf ("the soft limit is %zu, hard limit is %zu\n", current.rlim_cur, current.rlim_max);
	printf ("after changing the limit is \n");
	if (prlimit (0, RLIMIT_NPROC, NULL, &current) == -1)
		errExit ("prlimit failed");
	printf ("the soft limit is %zu, hard limit is %zu\n", current.rlim_cur, current.rlim_max);
	fork();
	fork();
	fork();
	fork();
	fork();
	fork();
}



