#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>

int main(int argc, char *argv[])
{

	int	fd;
	int	ret;
	int	val;
	int 	flags;

	if ((fd = open (argv[1], O_RDWR | O_APPEND)) == -1)
		err_exit ("open failed\n");

	if ((flags = fcntl (fd, F_GETFL, 0)) == -1)
		err_exit ("getfal failed\n");

	switch (flags & O_ACCMODE) {
		case O_RDONLY:
			printf ("file opened in readonly mode\n");
			break;

		case O_WRONLY:
			printf ("file opened in write only mode\n");
			break;
		case O_RDWR:
			printf ("file opened in rdwr mode\n");
			break;
		case default:
			break;
	}

	if (
