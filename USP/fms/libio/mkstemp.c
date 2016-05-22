#include <stdio.h>
#include <stdlib.h>

int main()
{
	char	template[1024] = "./tmpfile.XXXXXX";
	int	fd;

	if ((fd = mkstemp (template)) == -1)
		err_exit ("mkstemp failed\n");

}
