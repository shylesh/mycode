#include <fcntl.h>

int main()
{
	int fd1, fd2;

	fd1 = open("/etc/passwd", O_RDONLY);
	fd2 = dup(fd1);

	printf ("%d \n %d", fd1, fd2);
	pause();
}
