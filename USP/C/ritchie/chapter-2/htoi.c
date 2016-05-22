#include <stdio.h>

int main()
{
	int	c;
	int	val = 0;

	while ((c = getchar()) != '\n') {
		if (c >= '0' && c <= '9')
			val = val * 16 + (c - '0');
		else 
			if (c >= 'a'  && c <= 'z') 
				val = val * 16 + (c - 'a' + 10);
		else
			if(c >= 'A' && c <= 'Z')
				val = val * 16 + (c - 'A' + 10);
	}

	printf ("%d\n", val);
}
