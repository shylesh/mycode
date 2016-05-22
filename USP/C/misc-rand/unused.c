#include <stdio.h>

int fun(int a, int b);

int main()
{
	int a = 1;
	int b = 2;

	fun(a, b);
}

int fun(int a, int b)
{
	(void) b;
	printf ("%d", a);
}
