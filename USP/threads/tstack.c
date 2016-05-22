#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>

struct foo {
	int a, b, c, d;
};

void
printfoo (struct foo *fptr)
{

	printf ("a = %d\n", fptr->a);
	printf ("b = %d\n", fptr->b);
	printf ("c = %d\n", fptr->c);
	printf ("d = %d\n", fptr->d);
}

void *
t1_fn (void *ptr)
{

	struct foo f;
	f.a = 1;
	f.b = 2;
	f.c = 3;
	f.d = 4;

	printf ("t1:");
	printfoo (&f);

	pthread_exit ((void *) &f);

}

void *
t2_fn (void *ptr)
{

	printf ("thread 2\n");
	pthread_exit ((void *) 2);
}

int
main()
{
	int		ret;
	pthread_t	t1, t2;
	struct foo	foo;

	ret = pthread_create (&t1, NULL, t1_fn, NULL);

	if (ret)
		err_exit ("create failed\n");

	pthread_join (t1, (void *) &foo);

	ret = pthread_create (&t2, NULL, t2_fn, NULL);
	if (ret)
		err_exit ("creat faield\n");


	printf ("inside main\n");
	printfoo (&foo);

}
