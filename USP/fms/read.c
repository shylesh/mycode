#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>

void err_exit (const char *msg)
{
	perror (msg);
	exit (1);
}

int main(int argc, char *argv[])
{
	int fd;
	size_t count;
	char buf[PATH_MAX];

	if ((fd = open (argv[1], O_RDONLY)) == -1)
		err_exit ("open failed\n");


	if ((count = read (fd, (void *)buf, -10)) > 0)
		printf ("%s, %d", buf, count);
	else {
		printf ("inside else\n");
		perror ("read failed");

	}
}


