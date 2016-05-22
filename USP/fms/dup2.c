#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdio.h>

#define E_INVAL	-2
#define E_RANGE  -3

int err;

int main(int argc, char *argv[])
{
	int ret;
	int fd;
	int i = 0;

	while (i++ < 50) {

	if ((fd = open (argv[1], O_RDWR)) == -1)
		err_exit ("open failed\n");

	if ((ret = dup2 (fd, atoi(argv[2]))) == -1)
		err_exit ("dup_2 failed\n");
	else
		printf ("dup_2 success\n");
	}
	while (1)
		;
}

