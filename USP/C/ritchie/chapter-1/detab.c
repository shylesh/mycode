#include <stdio.h>

#define TAB_SPACE	4

int
main()
{
	int	c;
	int	i;

	while ((c =getchar()) != EOF) 
		if (c == '\t') 
			for (i = 0; i < TAB_SPACE; i++)
				putchar (' ');
		else
			putchar(c);

		
}
