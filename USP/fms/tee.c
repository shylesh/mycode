#include <stdio.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>



int main(int argc, char *argv[])
{
	int	fd;
	int	ret;
	int	count;
	char 	*buf;
	int	len;

	if ((fd = open (argv[1], O_RDWR | O_CREAT, S_IRWXU)) == -1)
		err_exit ("open failed\n");


	len = strlen (argv[2]);
	if (!len)
		printf ("nothing to print\n");
	else  {
		len++;
		buf = (char *) malloc (len);
		/* write to both stdou and file*/
		strncpy (buf, argv[2], len);

		if ((count = write (fd, buf, len)) != len)
			err_exit ("write failed\n");
		if (lseek(fd, 0, SEEK_SET) == -1)
			err_exit ("seek failed\n");

		if ((count = write (STDOUT_FILENO, buf, len)) != len)
			err_exit ("write failed\n");

	}
}
