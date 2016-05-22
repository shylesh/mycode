#include <unistd.h>
#include <stdio.h>
#include <limits.h>

int main()
{
	int	ret = -1;
	char 	cwd[PATH_MAX] = {0, };
	char	*cur_dir = NULL;
	char 	*retp ;

	if ((retp = getcwd (cwd, PATH_MAX)) == NULL)
		err_exit ("getcwd1 failed\n");

	printf ("cwd is %s\n", cwd);

	ret = chdir ("/home/redhat/Downloads/USP");
	if (ret == -1)
		err_exit ("chdir failed\n");

	if ((retp = getcwd (cur_dir, PATH_MAX)) == NULL)
		err_exit ("getcwd failed\n");

	printf ("new cwd is %s\n", cur_dir);

	printf ("successfully changed to %s\n", cur_dir);
}
