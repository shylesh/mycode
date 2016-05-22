#include <stdio.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	int fd;
	int ret;
	char buf[100];

	if ((fd = open (argv[1], O_RDWR | O_APPEND)) == -1)
		err_exit ("open failed\n");

	if (lseek (fd, 150, SEEK_SET) == -1)
		err_exit ("lseek failed\n");

	if ((ret = read(fd, buf, 10)) != 10)
		err_exit ("read failed\n");
	printf ("%s", buf);

	if ((ret = write (fd, buf, ret)) != 10)
		err_exit ("write failed\n");
}
