#include <stdio.h>

void myprint(char *str);

int main()
{
	char str[10] = "helo";

	(*myprint)(str);
}

void myprint (char *str)
{
	printf ("%s", str);
}
