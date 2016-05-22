#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int main()
{
	char patter[10] = "patXXXXXX";
	int ret = -1;
	int fd;
	char str[] = "hello world";

	fd = mkstemp(patter);
	if (ret == -1)
		printf("mkstemp failed %s", strerror(errno));



}


