#include <stdio.h>
#include <unistd.h>

void help();
void verbose();

int main(int argc, char *argv[])
{
	int	flag = 0;
	int	c;

	while ((c = getopt(argc, argv, "hvn:")) != -1) {
		switch(c) {
		case 'h':
			help();
			break;

		case 'v':
			verbose();
			break;
		case 'n':
			printf("%s", optarg);
			break;

		default :
			printf ("BOO BOO");
		}

	}
}
void
help()
{
	printf ("HELP");
}

void
verbose()
{
	printf ("VERBOSE");
}


