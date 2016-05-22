
#define _XOPEN_SOURCE 500
#include <ftw.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <stdint.h>

int	count=0;

static int
call_me (const char *fpath, const struct stat  *sb,
	     int type_flag, struct FTW *ftwbuf)
{
	printf ("%s\n", fpath);
	count++;
	return 0;
}




int main(int argc, char *argv[])
{

	int		nopenfd = 10;
	const char 	*dirpath = argv[1];
	int 		ret  = -1;
	int 		flag=0;

	flag = flag | FTW_PHYS;

	if ((ret = nftw (dirpath, call_me,
			 nopenfd, flag )) == -1)
	{
		err_exit ("nftw failed\n");
	}

	printf ("no of files = %d\n", count);
	exit (EXIT_SUCCESS);
}

