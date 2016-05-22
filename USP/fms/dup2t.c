#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>

int main()
{
	int n_fd;
	int n1;

	n_fd = dup2(0, 7);
	n1 = dup(0);

	printf ("n1=  %d, n2 = %d\n",n1, n_fd);
}
