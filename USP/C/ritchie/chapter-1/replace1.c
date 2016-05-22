#include <stdio.h>

int main()
{
	int c;


	while ((c = getchar()) != EOF) {


	if (c == '\b')
		printf ("back space");
	else
		if (c == '\\')
			printf ("back slash");
	else
		printf ("No match\n");
	}

}
