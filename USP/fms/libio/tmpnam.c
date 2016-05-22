#include <stdio.h>
#include <stdlib.h>

#define MAXCHAR		1024

int main(void)
{
	char	tmparr[L_tmpnam], get_buf[MAXCHAR];
	FILE	*fp;

	printf ("tmp = %s\n", tmpnam(NULL));

	if (!tmpnam (tmparr))
		err_exit ("tmpnam failed\n");
	printf ("%s\n", tmparr);

	if ((fp = tmpfile()) == NULL)
		err_exit ("tmpfile failed\n");

	if (fputs("Hello word on fp\n", fp) == EOF)
		if (ferror (fp))
			err_exit ("some error occured\n");
	rewind (fp);

	if (fgets(get_buf, MAXCHAR, fp) == NULL)
		err_exit ("fgets failed\n");

	fputs (get_buf, stdout);

	exit (0);
}
