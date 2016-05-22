/*
 * This program demonstrates the file table
 * sharing between parent and child after
 * fork
 *
 */


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>

int
main()
{

	int	fd;
	pid_t	pid;
	char	template[12] = "hello.XXXXXX";
	int	flags;

	if ((fd = mkstemp(template)) == -1)
		err_exit ("mkstemp failed\n");

	flags = fcntl (fd, F_GETFL);

	printf ("flag O_APPEND before fork is : %s\n",
		(flags & O_APPEND) ? "ON" : "OFF");

	printf ("offset before fork is : %ld\n", lseek(fd, 0, SEEK_CUR));

	switch (pid = fork()) {

	case -1: printf ("fork failed\n");
		 exit(1);

	case 0:	printf ("inside child\n");
		 /* set O_APPEND to on */
		flags |= O_APPEND;
		fcntl (fd, F_SETFL, flags);
		/* change offset */
		lseek (fd, 1000, SEEK_CUR);
		exit (0);

	default:sleep(5);
		break;
	}

	/* inside parent check the flags and offset */
	printf ("inside parent \n");

	flags = fcntl (fd, F_GETFL);

	printf ("flag O_APPEND after fork is : %s\n",
		(flags & O_APPEND) ? "ON" : "OFF");

	printf ("offset after fork is : %ld\n", lseek(fd, 0, SEEK_CUR));

	exit (0);
}
