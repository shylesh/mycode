#include <stdio.h>

int main()
{
	unsigned char c = 0;
	unsigned char an = c | (unsigned char)0XFF  ;
	signed char ch = 0 | (signed char)0xFF;

	printf ("%d\n", c );
	printf ("%d\n", an);
	printf ("%d\n", ~c);
	printf ("%d\n", ++ch);


}
