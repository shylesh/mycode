#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>


exitError (const char *str)
{
	perror (str);
	exit (1);
}

int main()
{
	int fd;
	int ret;
	uid_t user;
	char buf[10] = "hello";

	user = getuid();
	if (ret == -1)
		exitError ("getuid failed\n");
	else
		printf ("getuid success %zu\n", user);


	fd = open ("hi", O_RDWR);
	if (fd == -1)
		exitError ("open failed\n");
	else
		printf ("fd = %d", fd);


	if (write (fd, buf, 10) != 10)
		exitError("write failed\n");
	else
		printf ("written %d bytes\n", 10);

}
