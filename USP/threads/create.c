#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <errno.h>

void *tfunc (void *tid);

int main()
{
	pthread_t	tarray[10];
	int		ret;
	long		i;
	void 		*retval = (void *) malloc (sizeof(int));
	int		err;

	for (i = 0; i < 10; i++) {
		ret = pthread_create (&tarray[i], NULL, tfunc, (void *) i);
		if (errno)
			printf("couldn't create thread %d\n", i);
	}

	printf ("inside main\n");


	for (i = 0; i < 10; i++) {
		printf ("joining thread %d\n", i);
		err = pthread_join (tarray[i],(void **) &retval);
		if (errno)
			fprintf (stdout, "error with thread %d, %s", i, strerror (errno));
	}
}

void *
tfunc (void *tid)
{
	printf ("I am thread %d\n", (long) tid);
	return 0;
}
