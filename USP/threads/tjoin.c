#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *
t1_fn (void *ptr)
{
	printf ("thread 1 exiting:\n");
	return ((void *) 1);
}

void *
t2_fn (void *ptr)
{
	printf ("thread 2 exiting:\n");
	pthread_exit ((void *) 2);
}

int
main()
{

	int		ret;
	pthread_t	t1, t2;
	int		retval;

	ret = pthread_create (&t1, NULL, t1_fn, NULL);

	if (ret)
		err_exit ("creation failed\n");

	ret = pthread_create (&t2, NULL, t2_fn, NULL);

	if (ret)
		err_exit ("creation failed\n");


	ret = pthread_join (t1, &retval);

	printf ("t1 exited with status %d\n", retval));

	pthread_join (t2, &retval);

	printf ("t2 exited with status %d\n", (int *)retval);
}
