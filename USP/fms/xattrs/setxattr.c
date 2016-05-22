#include <sys/types.h>
#include <attr/xattr.h>


int main(int argc, char *argv[])
{
	char 	*val = "My first attr";
	int	size = strlen(val);


	if ((setxattr (argv[1], "user.linkxdffdattr", val, size, XATTR_REPLACE)) == -1)
		err_exit ("setxattr failed\n");
}
