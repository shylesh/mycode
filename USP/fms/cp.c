#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	int	s_fd, d_fd;
	int	count;
	char	buf[1024];
	int 	ret;


	if ((s_fd = open (argv[1], O_RDONLY)) == -1)
		err_exit ("OPEN FAILED FOR SOURCE\n");

	if ((d_fd = open (argv[2], O_RDWR | O_CREAT, S_IRWXU)) == -1)
		err_exit ("open failed for dest\n");

	while ((count = read(s_fd, buf, 1)) > 0) {
		if (*buf == '\0')	continue;
		while ((ret = write (d_fd, buf, count)) != count)
			;
	}

	close (s_fd);
	close (d_fd);
}


