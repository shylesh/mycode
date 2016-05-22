#include <stdio.h>

int main(int argc, char *argv[])
{
	while (--argc) {
		printf ("%s%s\n", *++argv, (argc > 0) ? " " : "");
	}
}
