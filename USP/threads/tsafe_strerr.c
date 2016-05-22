#define _GNU_SOURCE

#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <pthread.h>
#include <stdlib.h>

#define MAXLEN	100

void * pfunc (void *);
void destructor (void *);
void create_key(void);

pthread_once_t	once = PTHREAD_ONCE_INIT;
pthread_key_t	key ;

void
destructor (void *buf)
{
	if(buf)
		free((char *)buf);

}
void
create_key (void)
{
	int	ret;

	ret = pthread_key_create (&key, destructor);
	if (ret)
		err_exit ("key_create failed\n");
}

char *
my_sterr(int err)
{
	int	ret;
	char	*buf = NULL;

	ret = pthread_once (&once, create_key);
	if (ret)
		err_exit ("once failed\n");

	buf = pthread_getspecific (key);
	if (!buf) {
		buf = malloc (MAXLEN + 1);
		if (!buf)
			err_exit ("malloc failed\n");
		ret = pthread_setspecific (key, buf);
		if (ret)
			err_exit ("setspecific failed\n");
	}

	if  (((err < 0) || err > _sys_nerr) || _sys_errlist[err] == NULL)
		snprintf (buf, MAXLEN, "invalid errno");
	else {
		snprintf (buf, MAXLEN,"%s", _sys_errlist[err]);
		buf[MAXLEN + 1] = '\0';
	}

	return buf;

}

void *
pfunc (void *ptr)
{

	char	*str;

	str  = my_sterr(ENOENT);
	printf ("inside thread: %s", str);

}

int
main()
{
	pthread_t	t;
	int		ret;
	char		*str;

	str = my_sterr(EINVAL);
	ret = pthread_create(&t, NULL, pfunc, NULL);
	if (ret)
		err_exit ("create failed\n");


	printf ("main: %s\n", str);
	pthread_join (t, NULL);

}



