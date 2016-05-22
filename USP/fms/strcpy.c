#include <string.h>
#include <stdio.h>

int main()
{
	char s1[1024];
	char *s2 = "hello";

	strcpy(s1, "/");
	s1 = s1 + 1;
	*s1 = 0;
	printf ("%s", s1);

	strcpy (s1, s2);

	printf ("%s", s1);
}

