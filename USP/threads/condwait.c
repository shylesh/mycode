#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#define MAX_THREADS	5

void *	pfunc (void *);

int			i;
pthread_mutex_t		mut = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t		cond = PTHREAD_COND_INITIALIZER;
int			scan;


int
main()
{
	pthread_t	workers[MAX_THREADS];
	int		ret;
	long		i;

	/* create the threads */
	for  (i  = 0; i < MAX_THREADS; i++) {
		ret = pthread_create (&workers[i], NULL, pfunc, (void *)i);
		if (ret)
			err_exit ("thread creation failed for\n");
	}

	while (1) {
		scanf ("%d", &scan);
		pthread_cond_signal(&cond);
	}

}

void *
pfunc (void *args)
{
	int	ret;
	long tid;

	tid = (long ) args;

	for (; ; ) {
		ret = pthread_mutex_lock (&mut);
		if (ret)
			err_exit ("mutex lock failed\n");

			while (scan == 0)
				pthread_cond_wait (&cond, &mut);

			printf ("scan = %d, tid = %ld\n", scan, tid);
			scan=0;
		ret = pthread_mutex_unlock (&mut);
		if (ret)
			err_exit ("mutex unlock failed\n");
	}
}

