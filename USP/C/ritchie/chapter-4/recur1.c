#include <stdio.h>

void printd(int i);

int main()
{
	int i = -123;

	printd(i);
}

void 
printd (int n)
{
	if (n < 0) {
		putchar ('-');
		n = -n;
	}

	if (n / 10)
		printd (n / 10);
	printf ("%c", n % 10 + '0');
}
