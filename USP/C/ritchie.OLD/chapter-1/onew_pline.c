#include <stdio.h>

#define IN	0
#define OUT	1

int main()
{
	int	c;
	int	wc = 0;
	int 	state = OUT;

	while ((c = getchar()) != EOF) {
		if (c == ' ') {
			if (state == IN) {
				putchar('\n');
			}
			state = OUT;
		}
		else if(c == '\t' || c == '\n')
			continue;
		else  if(state == OUT) {
			state = IN;
			wc++;
		}
		if (state != OUT)	putchar(c);
	}
	printf ("number of words = %d\n", wc);
}	
	

