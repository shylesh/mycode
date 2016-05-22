#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{
	uid_t	uid;
	uid_t	euid;

	printf  ("%d\n",  getuid());
	printf ("%d", geteuid());
}
