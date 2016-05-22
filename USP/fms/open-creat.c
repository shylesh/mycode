/*
 *  Aim : create a file with O_CREAT flad
 */

#include <stdio.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>

void err_exit(const char *msg)
{
	perror (msg);
	exit(1);
}

int main()
{

	int fd;


	fd = open ("create.txt", O_RDWR | O_CREAT | O_TRUNC, S_IRWXU);

	if (fd == -1)
		err_exit ("open failed\n");
	else
		printf ("file created successfully\n");
}

