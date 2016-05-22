#include <stdio.h>

#define MAXBUF	4096

int main (int argc, char *argv[])
{
	FILE	*f_in;
	FILE	*f_out;
	int	ret;
	char	buf[MAXBUF];

	if ((f_in = fopen (argv[1], "r")) == NULL)
		err_exit ("opening f_in failed\n");

	if ((f_out = fopen (argv[2], "w")) == NULL)
		err_exit ("writing f_out failed\n");

	while (fgets (buf, MAXBUF, f_in) != NULL) {
		if (fputs (buf, f_out) < 0)
			err_exit ("fputs failed\n");
	}
}
