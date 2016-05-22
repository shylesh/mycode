#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main()
{
	char	*path = "/dev/fd/1";
	int	fd;

	unlink(path);
	if ((fd = creat(path, O_RDWR)) < 0)
		err_exit ("creat failed\n");


}
