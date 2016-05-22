#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>

int main()
{
	int fd;
	char preamble[] = "hello";
	char postamble[] = "world";


	fd = open ("holes", O_RDWR | O_CREAT, S_IRWXU);
	if (fd == -1)
		err_exit ("open failed\n");

	if (write (fd, preamble, 6) != 6)
		err_exit ("write failed\n");

	if (lseek (fd, 1020020, SEEK_CUR) == -1)
		err_exit ("lseek failed\n");

	if (write (fd, postamble, 6) != 6)
		err_exit ("write2 failed\n");
}

