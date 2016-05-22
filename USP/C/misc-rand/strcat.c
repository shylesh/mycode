#include <stdio.h>
#include <string.h>

int main()
{
	char str1[100] = "hello";
	char str2[100] = "hi";
	char str3[100] = "toi";

	printf ("%s", strcat(str3, strcat(str1, str2)));
}
