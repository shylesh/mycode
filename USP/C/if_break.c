#include <stdio.h>

int main()
{
	int i = 1 ;
	int rev=0;

	for ( ; (i < 0) && (!rev); i++) {
		printf ("enter");
		if ((i == 1) || (rev=1))
		{
			printf ("%d\n", i);
		}
	}
	printf("out when i = %d\n", i);
}
