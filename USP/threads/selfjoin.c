#include <stdio.h>
#include <pthread.h>
#include <errno.h>
#include <string.h>

int main()
{
	int		ret;

	pthread_join(pthread_self(), NULL);
		printf ("%s\n", strerror(errno));
}

