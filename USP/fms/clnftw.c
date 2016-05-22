#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>
#include <limits.h>
#include <errno.h>
#include <string.h>

/* my func */
typedef int Myfunc (const char *, const struct stat *, int);

static Myfunc 	myfunc;
static int	myftw (char *, Myfunc *);
static int	dopath (Myfunc *);
char *		path_alloc (int *);

static long nreg, ndir, nblk, nchr, nfifo, nslink,nsock, ntot;


int
main(int argc, char *argv[])
{
	int 	ret;

	if (argc !=2 )
		err_exit ("usage: ftw <starting path>\n");

	ret = myftw (argv[1], myfunc);	 /* does everyting */

	ntot = nreg + ndir + nblk + nchr + nfifo + nslink + nsock + ntot;
	if (ntot == 0)
		ntot = 1;
	printf ("regular files = %7ld, %5.2f %%\n", nreg,
		 nreg * 100.0 / ntot);
	printf ("dir files = %7ld, %5.2f %%\n", ndir,
		 ndir * 100.0 / ntot);
	printf ("blk files = %7ld, %5.2f %%\n", nblk,
		 nblk * 100.0 / ntot);
	printf ("char files = %7ld, %5.2f %%\n", nchr,
		 nchr * 100.0 / ntot);
	printf ("fifo files = %7ld, %5.2f %%\n", nfifo,
		 nfifo * 100.0 / ntot);

	exit (ret);
}


/*
 * some useful macros
 */
#define FTW_F	1	/* file other than directory */
#define FTW_D	2	/* directory */
#define FTW_DNR	3	/* directory not readable */
#define FTW_NS	4	/* file can't be statd */

static char *fullpath; 	/* contains full pathname for every file */

static int
myftw (char *pathname, Myfunc *func)
{
	int len;
	fullpath = path_alloc (&len);

	strncpy (fullpath, pathname, len);
	fullpath[len] = '\0';
	printf ("fullpath= %s\n", fullpath);

	return (dopath (func));
}


/*
 *  routine for proper mem allocation for path
 */
#ifdef PATH_MAX
static int pathmax = PATH_MAX;
#else
static int pathmax = 0;
#endif


#define PATH_MAX_GUESS	1024

char *
path_alloc (int *sizep)
{
	char 	*ptr;
	int 	size;

	if (pathmax = pathconf ("/", _PC_PATH_MAX) < 0) {
		if (errno = 0)
			pathmax = PATH_MAX_GUESS;
		else
			err_exit ("pathconf error for _PC_PATH_MAX");
	} else {
		pathmax++;
	}

	size = 1024;

	if ((ptr = (char *) malloc (size)) == NULL)
		err_exit ("malloc failed\n");

	if (sizep != NULL)
		*sizep = size;

	return (ptr);
}


/*
 * descend through dir tree
 * if file : then call lstat() and call func()
 * if dir : then recurse again inside
 */
static int
dopath (Myfunc *func)
{

	struct stat	sbuf;
	int		ret;
	DIR		*dp;
	struct dirent	*de;
	char 		*ptr;

	if (lstat (fullpath, &sbuf) == -1)
		err_exit ("lstat failed\n");

	if (S_ISDIR (sbuf.st_mode) == 0)
		return (func (fullpath, &sbuf, FTW_F));

	/* its a dir so recurse and get all the entries */
	if ((ret = func(fullpath, &sbuf, FTW_D)) != 0)
		return (ret);

	ptr = fullpath + strlen(fullpath);
	*ptr++ = '/';
	*ptr = 0;

	if ((dp = opendir(fullpath)) == NULL)
		return (func(fullpath, &sbuf, FTW_DNR));

	while ((de = readdir(dp)) != NULL) {
		if (!(strcmp(de->d_name, ".")) || !(strcmp(de->d_name, "..")))
			continue;

		strcpy (ptr, de->d_name);

		if ((ret = dopath(func)) != 0)
			break;
	}
	ptr[-1] = 0;

	if (closedir (dp) < 0)
		err_exit ("close dir failed\n");

	return (ret);
}

static int
myfunc (const char *pathname, const struct stat *statptr, int type)
{

	switch (type) {
	case FTW_F:
		switch (statptr->st_mode & S_IFMT) {
		case S_IFREG:	nreg++;		break;
		case S_IFBLK:	nblk++;		break;
		case S_IFCHR:	nchr++;		break;
		case S_IFIFO:	nfifo++; 	break;
		case S_IFLNK:	nslink++;	break;
		case S_IFSOCK:	nsock++;	break;
		}
		break;

	case FTW_D:
		ndir++;
		break;

	case FTW_DNR:
		err_exit ("can't read dir\n");
		break;

	case FTW_NS:
		err_exit ("stat failed");
		break;

	default:
		err_exit ("unknoown type");
	}

	return (0);
}



