#include <stdio.h>
#include <stdlib.h>

void samp(char **s) 
{

	s = NULL;
}

int main()
{

	char *src = (char *) malloc (3);
	src = "hi";

	samp(&src);

	printf ("%s", src);
}
	
