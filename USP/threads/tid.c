#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

pthread_t	trd;

void
printid (const char *str)
{
	pid_t		pid;
	pthread_t	tid;

	pid = getpid();
	tid = pthread_self();

	printf ("%s pid %u tid %u (0x%x)\n", str, (unsigned int) pid,
		(unsigned int) tid, (unsigned int) tid);


}

void *
thr_fn(void *arg) {
	printid ("New thread: ");
	return ((void *) 0);
}

int
main()
{

	int		ret;

	ret = pthread_create (&trd, NULL, thr_fn, NULL);

	if (ret)
		err_exit ("thread creation failed\n");

	printid ("main thred: ");
	sleep(1);
	exit (0);
}
