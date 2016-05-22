#include <stdio.h>
void f();
void g(char *);

int main()
{
	f();
}

void f()
{
	char text[] = "abcdefghijklmnopqrstuvwxyz";
	g(text);
	printf ("hello");
}

void g(char *text)
{
	static int i;
	char buffer[3];

	for (i = 0; text[i]!='\0'; i++)
		buffer[i] = text[i];

	buffer[i] = '\0';
	printf ("%s", buffer);
	return;
}
