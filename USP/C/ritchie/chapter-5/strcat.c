#include <stdio.h>

char *strcat (char *src, char *dst);

int main()
{
	char	src[100] = "hello";
	char	dest[100] = "hi";

	strcat(src, dest);
	printf ("%s", src);
}

char *
strcat (char *src, char *dst)
{
	while (*src != '\0')
		src++;

	while ((*src++ = *dst++) != '\0')
		;
	return src;
}
	
