#include <dirent.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <errno.h>
#include <stddef.h>

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
	struct dirent	**dref;
	int		ret;
	int		de_size;


	dirp = opendir(path);
	if (!dirp)
		err_exit ("opendir failed\n");

	de_size = offsetof(struct dirent, d_name) + NAME_MAX + 1;
	d_ent = (struct dirent *)malloc (de_size);
	if (!d_ent)
		err_exit ("malloc failed\n");

	for (; ;) {

		ret = readdir_r (dirp, d_ent, dref);

		if (*dref == NULL)
			break;

	printf ("%s\n",d_ent->d_name);

	}

	if (errno)
		err_exit ("some error occured\n");
}


