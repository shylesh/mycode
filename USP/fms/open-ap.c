#include <stdio.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

void err_exit(const char *str)
{
	perror (str);
	exit(1);
}

int main()
{
	int fd;
	char buf[] = "hello world_append";

	fd = open ("file", O_APPEND | O_RDWR);

	if (fd == -1)
		err_exit("open failed\n");

	lseek (fd, 0, SEEK_SET);

	if (write (fd, buf, strlen(buf)) != strlen(buf))
		err_exit("write1 failed\n");
	lseek (fd, 0, SEEK_SET);

	if (write (fd, buf, strlen(buf)) != strlen(buf))
		err_exit("write2 failed\n");

	exit(0);
}
