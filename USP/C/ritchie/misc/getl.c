#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int
main()
{
	char *linearr[10];
	int i;
	size_t n = 5;
	ssize_t read;
	FILE *fp;

	//linearr[0] = (char *) malloc(20);

	fp = fopen ("/etc/passwd", "r");
	if (fp == NULL)
		exit(EXIT_FAILURE);

	for (i = 0; (read = getline(&linearr[i], &n, fp) != -1) && (i < 10); i++) {
		printf ("total = %zu, n = %zu",  read, n);
	}
}
	
