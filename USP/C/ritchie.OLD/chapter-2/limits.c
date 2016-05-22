#include <stdio.h>

int main()
{
	char c = 0;
	char an = c | 0XFF  ;
	signed char ch = 0;

	printf ("%d\n", c - 1);
	printf ("%d\n", an);
	printf ("%d\n", ~c  );
	printf ("%d\n", ~ch);

	while (++c) 
		printf ("%2d", c);

}
