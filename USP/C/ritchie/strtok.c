#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	char *string ;
	char *dst = NULL;
	char *saveptr = (char *) malloc(100);

	string = (char *) malloc(100);

	strcpy (string, argv[1]);

	dst = strtok_r(string, "=", &saveptr);
	printf ("%s\n", dst);

	dst = strtok_r (NULL, "=", &saveptr);
		printf ("%s", dst);
	dst = strtok_r(NULL, "=", &saveptr);
		printf ("%s", saveptr);
}
