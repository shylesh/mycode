#define _BSD_SOURCE
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void stat_dis (struct stat *st)
{

	mode_t mode;
	mode = st->st_mode;

	switch (mode ) {

	case S_IFREG: printf ("regular\n");
			break;
	case S_IFDIR: printf ("directory\n");
			break;
	default : printf ("unknown\n");
			break;

	}

	printf ("Inode = %zu\n", st->st_ino);
	printf ("No of links = %zu\n", st->st_nlink);
	printf ("Size = %zu\n", st->st_size);



}

int main(int argc, char *argv[])
{

	struct stat	sb;
	int 		ret;

	if ((ret = stat (argv[1], &sb)) == -1)
		err_exit ("stat failed on");

	stat_dis (&sb);



}
