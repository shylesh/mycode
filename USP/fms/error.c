#include <errno.h>
#include <stdio.h>

void err_exit (const char *msg);

void
err_exit (const char *msg)
{
	perror (msg);
	exit (1);
}
