#include <stdio.h>
#include <stdlib.h>

int main()
{
	int	num;

	printf ("enter the num\n");
	scanf ("%d", &num);

	while(num > 2) {
		if ((num % 2) || ((num / 2) % 2))
		{
			printf ("Not a power of 2\n");
			exit(0);
		}

		num = num / 2;
	}
	printf (" pow of 2 \n");

}
