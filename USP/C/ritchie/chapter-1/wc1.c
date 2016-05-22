#include <stdio.h>

#define IN	0
#define OUT	1

int main()
{
	int	c;
	int	wc = 0;
	int 	state = OUT;

	while ((c = getchar()) != EOF) {
		if (c == ' ')
			state = OUT;
		else if(c == '\t' || c == '\n')
			continue;
		else  if(state == OUT) {
			state = IN;
			wc++;
		}
	}
	printf ("number of words = %d\n", wc);
}	
	

