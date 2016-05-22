#include <stdio.h>
int ret(void);
int i = 1;

int main()
{
	int a;

	a = ret();
	printf ("%d", a);
}

int ret()
{
	return i++;
}
