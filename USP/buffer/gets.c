#include <stdio.h>

void read(char *);

int main()
{
	char buf[3];

	read(buf);
	printf ("%s", buf);
}

void read(char *buf)
{
	printf ("enter the string");

	gets(buf);
}
