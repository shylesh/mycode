#define  _GNU_SOURCE

#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <pthread.h>

#define MAXLEN	100

void *	pfunc(void *);
char *	my_strerr(int err);

static __thread char	buf[MAXLEN];

char *
my_strerr (int err)
{

	if (err < 0 || err >= _sys_nerr || _sys_errlist[err] == NULL)
		snprintf (buf, MAXLEN, "invalid errno");
	else {
		snprintf (buf, strlen(_sys_errlist[err]), "%s\n", _sys_errlist[err]);
		buf[MAXLEN - 1] = '\0';
	}

	return buf;
}

void *
pfunc (void *ptr)
{

	char	*str;

	str = my_strerr(ENOENT);

	printf ("inside child thread: %s\n", str);

}

void
main()
{
	char		*str;
	int		ret;
	pthread_t 	t1;

	str = my_strerr(EINVAL);

	ret = pthread_create (&t1, NULL, pfunc, NULL);
	if (ret)
		err_exit ("create failed\n");

	printf ("inside main: %s\n", str);

}


