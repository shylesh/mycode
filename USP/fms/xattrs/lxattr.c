#include <sys/types.h>
#include <attr/xattr.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	ssize_t size;
	char 	val[1024];
	char 	*key_buf;
	int	i, j;

	if ((size = listxattr (argv[1], key_buf, 0)) == -1)
		err_exit ("listxattr failed\n");
	printf ("%d\n", size);

	key_buf = (char *) malloc (size);

	if ((listxattr (argv[1], key_buf, size)) == -1)
		err_exit ("listxattr failed\n");

//	for (j = 0; j < size; j++)
//		printf ("%c", *(key_buf + j));

	for (i = 0; i < size;  )
	{
		if (getxattr (argv[1], key_buf, val,  1024) == -1)
			err_exit ("getxattr failed\n");

		printf ("%s:%s\n", key_buf, val);
		i += (strlen(key_buf) + 1);
		key_buf = key_buf + i;

	}


}
