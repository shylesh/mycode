#include <sys/file.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int main(int argc, char *argv[])
{

	int	fd;

	if (argc != 2) {
		printf ("USAGE: %s <filename>", argv[0]);
		exit (1);
	}


	fd = open (argv[1], O_RDWR);

	// place a writelock

	if ((flock (fd, LOCK_EX | LOCK_NB)) != 0)
		printf ("%s\n", strerror (errno));
	else
		printf ("lock succeded\n");

	sleep(10);

	if ((flock (fd, LOCK_EX)) != 0)
		printf ("%s\n", strerror(errno));
	else
		printf ("lock succeede\n");
	sleep(5);

}


