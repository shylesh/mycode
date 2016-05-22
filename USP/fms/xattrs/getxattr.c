#include <sys/types.h>
#include <attr/xattr.h>

int main(int argc, char *argv[])
{
	int	size;
	char 	*buf;

	if ((size = getxattr (argv[1], "user.my", buf, 0)) == -1)
		err_exit ("getxattr failed\n");

	if (!(buf = (char *) malloc (size)))
		printf ("malloc failed\n");

	if ((getxattr (argv[1], "user.my", buf, size)) == -1)
		err_exit ("getxattr failed\n");
	printf ("user.my : %s\n", buf);
}

