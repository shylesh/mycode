#include <stdio.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
	if (lseek (STDIN_FILENO, 0, SEEK_CUR) ==  -1)
		err_exit ("seek failed\n");
	else
		printf ("seek succeeded\n");
}
