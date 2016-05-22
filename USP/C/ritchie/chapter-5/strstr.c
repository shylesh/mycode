#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	char *str;
	char *src = argv[1];
	char *dst = argv[2];

	str = strstr(src, dst);

	if(!str)
		printf ("Not found\n");
	else
		printf ("%s\n", str);
} 
