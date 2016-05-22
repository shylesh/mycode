#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 4096

int main(int argc, char *argv[])
{
	int	c;
	FILE	*in;
	FILE	*out;

	if (!(in = fopen (argv[1], "r")))
		err_exit ("open failed for :read\n");

	if (!(out = fopen (argv[2], "w")))
		err_exit ("open failed for : write\n");

	while ((c = fgetc(in)) != EOF) {
		if (fputc (c, out) == EOF)
			break;
	}

	if (ferror(in))
		err_exit ("error occured in input\n");

	if (ferror(out))
		err_exit ("error occured in out\n");

	exit (0);
}
