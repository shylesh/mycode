#include <stdio.h>
#include <string.h>

void move(char *arr1);

int main()
{
	char arr[10] = "helloworld";

	move(arr);
}

void move(char *src)
{
	int i=12 ;
	char dst[];

	for (i = 0; src[i] != '\0'; i++)
		dst[i] = src[i];
	dst[i] = '\n';
	printf ("%d", strlen(dst));
}
