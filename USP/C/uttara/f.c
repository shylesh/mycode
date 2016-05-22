#include <stdio.h>

int main()
{

	FILE	*fin, *fout;
	char	in[] = "input";
	char	out[] = "out";
	int	ret;
	char	buf[1024] = {0};
	char	buf1[1024] = {0};
	int	len;

	fin = fopen (in, "rw");
	if (!fin)
		printf ("fopen error\n");

	fout = fopen (out, "a");

	if (!fout)
		printf ("fopen write  error\n");

	fgets (buf, 1024, fin);
	printf ("read: %s", buf);
	printf ("%s", buf);

	fgets (buf1, 1024, fin);
	printf ("read from buf1: %s", buf1);
	printf ("%s", buf1);

	ret = fputs (buf, fout);
	if (feof(fout))
		err_exit ("fputs failed\n");
	if (ferror(fout))
		err_exit ("fputs failed\n");
	fflush (fout);

	fclose (fin);
	fclose (fout);
}


