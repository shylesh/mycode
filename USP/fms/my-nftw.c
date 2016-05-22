#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>

#define FILE_T	5
#define DIR_T	6


typedef int my_func (const char *fpath, const struct stat *sbuf,
			int type);  /* to be called by my_ftw   */
int my_ftw (const char *path);

my_func 	myfn;

/* Globals for count */
int nfiles = 0;
int ndirs = 0;
int nlinks = 0;
int nothers = 0;


int main(int argc, char *argv[])
{
	int	ret = 0;

	if (argc != 2)
		exit(1);

	if ((ret = my_ftw (argv[1])) == -1)
		printf ("something gone bad\n");

	printf ("stats is nfiles = %d, ndirs = %d, nlinks = %d, nothers = %d",\
		nfiles, ndirs, nlinks, nothers);

}

int my_ftw (const char *path)
{
	char *fpath = NULL;

	fpath = (char *) malloc (PATH_MAX);
	strncpy (fpath, path, strlen(path));
	*(fpath + strlen(path) + 1) = '\0';
	printf ("alloc: %s\n", fpath);
	return (do_dir(fpath));

}

int do_dir (const char *fpath)
{
	int		ret;
	struct stat  	buf;
	struct dirent 	*dent;
	DIR		*dp;
	char 		full_path[PATH_MAX];
	char		local_fpath[PATH_MAX] = {0, };
	char 		*ptr;

	/* return before recurse */
	if (!fpath)
		return;
	strncpy (local_fpath, fpath, strlen(fpath));
	local_fpath [strlen(fpath) + 1] = '\0';
	if ((ret = stat (local_fpath, &buf)) == -1)
		err_exit ("stat failed: pls check the path");

	if ((S_ISDIR (buf.st_mode)) == 0) {
		myfn (local_fpath, &buf, FILE_T);
		return;
	}

	ndirs++;
	if (!(dp = opendir (fpath)))
		err_exit ("opendir failed\n");


	strcat (local_fpath, "/");
	while ((dent = readdir (dp)) != NULL) {
		if (!(strcmp(".", dent->d_name)) || \
		    !(strcmp ("..", dent->d_name)))
			continue;

		if (snprintf (full_path, strlen(fpath), "%s", local_fpath) < 0)
			err_exit ("snprintf failed\n");

		strcat (local_fpath, dent->d_name);
		//do_dir (strcat (strcat(full_path, "/"), dent->d_name));
		do_dir (local_fpath);
		ptr = local_fpath + strlen(local_fpath) - strlen (dent->d_name);
		//++ptr;
		*ptr = '\0';
	}
	return;
}

int
myfn (const char *fpath, const struct stat *sbuf,
	int type)
{
	if  (S_ISREG(sbuf->st_mode))
		nfiles++;
	else
		if (S_ISLNK(sbuf->st_mode))
			nlinks++;
	else
		nothers++;

	return;



}
