#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <stdlib.h>

#define BUF_SIZ	10000

int main()
{

	int	ret;
	int	flags;
	int	ntowrite;
	int	nwrite;
	char	buf[BUF_SIZ];
	char	*ptr;

	flags = fcntl (STDOUT_FILENO, F_GETFL);
	if (flags == -1)
		err_exit ("getfal failed\n");

	ret = fcntl (STDOUT_FILENO, F_SETFL, flags | O_NONBLOCK);
	if (ret)
		err_exit ("setfl failed\n");

	ntowrite = read (STDIN_FILENO, buf, sizeof(buf));
	if (ntowrite == -1)
		err_exit ("read error");
	fprintf (stderr, "read %d bytes\n", ntowrite);

	ptr = buf;
	while (ntowrite > 0) {
		errno = 0;
		nwrite = write(STDOUT_FILENO, buf, ntowrite);
		fprintf (stderr, "nwrite=%d, errno=%d\n", nwrite, errno);

		if (nwrite > 0) {
			ptr += nwrite;
			ntowrite -= nwrite;
		}

	}
	exit(0);
}
