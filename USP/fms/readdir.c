#include <dirent.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <errno.h>

int  list_files (const char *dpath);
void usage();

int main(int argc, char *argv[])
{

	int	ret;

	if (argc < 2 || (strcmp (argv[1], "--help") == 0))
		usage();

	ret = list_files (argv[1]);
}

void usage()
{
	printf (".//%s %s", "./a.out", "fname");
	exit (1);
}

int list_files (const char *path)
{

	DIR 		*dirp;
	struct dirent 	*d_ent;
	int		ret;


	dirp = opendir(path);
	if (!dirp)
		err_exit ("opendir failed\n");

	for (; ;) {

		d_ent = readdir (dirp);
		if (!d_ent)
			break;

		printf ("%s\n",d_ent->d_name);

	}

	if (errno)
		err_exit ("some error occured\n");
}


