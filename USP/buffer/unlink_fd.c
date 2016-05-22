#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
	int ret = -1;
	int fd;
	char str[] = "hello world";

	fd = open("test", O_WRONLY|O_CREAT);
	if (fd == -1)
		printf("open failed %s", strerror(errno));

	if ((ret = unlink("./test")) == -1)
		printf ("close failed %s", strerror(errno));

	if((ret = write(fd, str, 10)) == -1)
		printf ("write failed %s", strerror(errno));
	printf ("write is success");


}


