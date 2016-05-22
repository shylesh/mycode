#include <stdio.h>

int main()
{
	int 	flag = 0;
	int	c;

	while ((c = getchar()) != EOF) {
		if (c == ' ') 
			flag++;	
		else
			if (flag >= 1) {
				flag = 0;
				putchar (' ');
				putchar (c);
			}
			
		else
			putchar(c);
	}
			
}
	
