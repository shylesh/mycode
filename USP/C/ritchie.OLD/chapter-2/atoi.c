#include <stdio.h>

int main()
{
	char 	s[10];
	int	c;
	int	val = 0;
	

	while ((c = getchar()) != '\n') {
		val = (val * 10 + (c - '0')) ;
	}

	printf ("number is %d\n", val);
}
	
