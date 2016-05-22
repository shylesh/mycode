#include <stdio.h>

void itoa(int	n, char s[]);

int 
main()
{
	int	n = 123;
	char	s[10];

	itoa(n, s);
}

void
itoa(int n, char s[])
{
	int i = 0;
	int a[10];
	int val = n;	
	int dig;

	while (val) {
		dig =  val % 10
		val /= 10;
		a[i++] = dig + '0';
	}
	a[i] = '\0';
}

