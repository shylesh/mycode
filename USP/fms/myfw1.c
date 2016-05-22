#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/types.h>
#include <errno.h>

void f1(const char *);
void f2(const char *);

int main (int argc, char *argv[])
{
	printf ("argv : %zu\n", argv[1]);
	f1(argv[1]);

}

void
f1(const char *path)
{
	printf ("f1: %zu\n", path);
	f2(path);
}

void
f2(const char *path)
{
	DIR *dp;
	struct dirent *de;
	struct stat *sbuf;

	printf ("f2: %zu\n", path);
	printf ("string is %s\n", path);

	if ((stat (path, sbuf)) != 0)
		err_exit ("stat failed\n");
	printf ("ptr is %zu, str: %s\n",path, path);
	if ((dp = opendir (path)) == NULL)
		err_exit ("opendir failed\n");

	while ((de = readdir (dp)) != NULL) {
		printf ("%s", de->d_name);
	}



}
