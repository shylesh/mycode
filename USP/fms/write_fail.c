#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/time.h>
#include <sys/resource.h>

int main()
{
	struct rlimit rlim;
	int ret;

	ret = getrlimit (RLIMIT_NOFILE, &rlim);
	if (ret == -1) {
		printf ("error\n");
		exit (1);
	}

	printf (" %zu, %zu", rlim.rlim_cur, rlim.rlim_max);
}

