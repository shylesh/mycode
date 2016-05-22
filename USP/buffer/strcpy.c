#include <stdio.h>
#include <string.h>

void copy (char *);

int main()
{
	char src[] = "hello world this";

	copy(src);

	printf ("back");
}

void copy (char *src)
{

	char dst[2];
	strcpy (dst, src);
	printf ("%s", dst);
	return;
}
