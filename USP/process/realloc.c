#include <stdio.h>
#include <stdlib.h>

int main()
{
	char	*buf;
	char	*buf1;
	int	i;

	buf = malloc (10);
	printf ("%p", buf);
	for (i = 0; i < 10; i++)
		buf[i] = ('a' + i);
	buf[i + 100] = '\n';
	buf[++i] = '\n';
	buf[++i] = '\n';
	buf[100] = 'a';

	printf ("%c", buf[100]);

	buf = realloc (buf, 26);

	printf ("realloc: %p",  buf);
	for (i = 10; i < 26; i++)
		buf[i] = ('a' + i);

	printf ("%s", buf);




}
