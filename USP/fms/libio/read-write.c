#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <stdlib.h>

#define MAXBUF	4096

int main(int argc, char *argv[])
{
	int	in_fd;
	int	out_fd;
	int	ret;
	char	buf[MAXBUF];

	if (argc != 3) {
		fprintf (stderr, "%s in_file out_file\n", argv[0]);
		exit (1);
	}

	/* read from a file and write to another fd */
	if ((in_fd = open(argv[1], O_RDONLY)) == -1)
		err_exit ("opening file for reading failed\n");

	if ((out_fd = open (argv[2], O_WRONLY | O_CREAT)) == -1)
		err_exit ("opening file for write failed\n");

	while ((ret = read(in_fd, buf, MAXBUF)) != 0) {
		if (write(out_fd, buf, ret) != ret)
			err_exit ("write failed\n");
	}

	if (ret && errno)
		err_exit ("read failed\n");

	close (in_fd);
	close (out_fd);
}
