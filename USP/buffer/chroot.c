#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <dirent.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define ROOT "/"

int main(int argc, char *argv[])
{
	char dir[30] ;
	int	ret = -1;
	DIR *	dir_ptr = NULL;
	struct dirent * entry = NULL;
	char buf[50];

	strcpy(dir, argv[1]);

	ret = chdir(".");
	if (ret) {
		printf ("chdir failed\n");
		printf ("%s", strerror(errno));
		exit(1);
	}
	printf ("directory changed to %s\n", dir);
	printf ("%s", getcwd (buf, 50));

	ret = chroot(dir);
	if (ret) {
		printf ("chroot failed on %s\n", dir);
		printf ("%s", strerror(errno));
		exit(1);
	}

	dir_ptr = opendir("/");
	if (!dir_ptr) {
		printf ("opendir failed \n" );
		printf ("%s", strerror(errno));
		exit(1);
	}

	while ((entry = readdir(dir_ptr))) {

		printf ("%s\n", entry->d_name);
	}
}





