#include <stdio.h>
#include <time.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/time.h>

#define DATA_CHUNK	1024
#define ONE_MB		1073741824

int main(int argc, char *argv[])
{
	int 	fd, r_fd;
	char 	*data;
	struct timeval tv1, tv2;
	int 	count = 0;
	int	ret;
	int	w_bytes;

	data = (char *) malloc (ONE_MB);
	if (!data)
		err_exit ("malloc failed\n");

	if ((fd = open (argv[1], O_RDWR | O_CREAT | O_EXCL, S_IRWXU )) == -1)
		err_exit ("open failed\n");

	if ((r_fd = open ("/dev/urandom", O_RDONLY)) == -1)
		err_exit ("opening urandom failed\n");

	while (count <  ONE_MB) {
		if ((ret = read (r_fd, data,  1024)) == -1)
			err_exit ("read failed\n");
		count += ret;
	}

	/* buffered writes */
	gettimeofday (&tv1, NULL);
	printf ("sec=%zu,ms= %zu\n", tv1.tv_sec, tv1.tv_usec);
	if ((w_bytes = write (fd, data, count)) != count)
		err_exit ("write failed\n");
/*	if (fsync(fd) == -1)
		err_exit ("fsync failed\n"); */
	gettimeofday (&tv2, NULL);
	printf ("sec= %zu, ms=%zu\n",tv2.tv_sec, tv2.tv_usec);

	printf ("total time taken for write is  %zu\n", (tv2.tv_sec - tv1.tv_sec));
}






