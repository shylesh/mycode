/*
 *  This program waits for all the threads
 *  to join
 */

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void * t_func (void *);

pthread_mutex_t		mux = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t		cond = PTHREAD_COND_INITIALIZER;

enum tstate  {
	T_ALIVE,
	T_TERMINATED,
	T_JOIN
};

struct tinfo {
	pthread_t	tid;
	enum tstate 	state;
	int		sleeptime;
}*threads;

int	nthreads = 0;
int	reaped = 0;

main(int argc, char *argv[])
{

	int	ret;
	int	i;

	nthreads = argc - 1;

	if (argc < 2 || (!strcmp(argv[1], "--help"))) {
		printf ("Usage: %s $1 $2 ...", argv[0]);
		exit(1);
	}

	threads = calloc (argc - 1, sizeof (*threads));

	/* create the threads */
	for (i = 0; i < (argc - 1); i++) {
		threads[i].state = T_ALIVE;
		threads[i].sleeptime = atoi (argv[i + 1]);
		ret = pthread_create (&threads[i].tid, NULL, t_func, (void *)i);
		if (ret)
			err_exit ("create failed for %d\n", i);
	}

	/* do cond_wait */
	pthread_mutex_lock (&mux);
	while (reaped != nthreads) {
		ret = pthread_cond_wait (&cond, &mux);
		if (ret)
			err_exit ("cond wait failed\n");

		/* find which is the reaped thread */
		for (i = 0; i < nthreads; i++) {
			if (threads[i].state == T_TERMINATED) {
				threads[i].state = T_JOIN;
				pthread_join (threads[i].tid, NULL);
				reaped++;
			}
		}
	}
	pthread_mutex_unlock (&mux);
}

void *
t_func (void *idx)
{
	int	i = (int) idx;

	printf ("sleeping thread %d for %d time\n", i, threads[i].sleeptime);
	sleep (threads[i].sleeptime);

	threads[i].state = T_TERMINATED;

	pthread_cond_signal (&cond);
	return;
}
