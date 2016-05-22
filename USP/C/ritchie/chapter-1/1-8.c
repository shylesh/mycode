#include <stdio.h>

int main() 
{
	int	ntab = 0;
	int 	nspc = 0;
	int	nnl  = 0;
	int 	c;


	while (( c = getchar()) != EOF ) {
		if (c == '\t')	
			ntab++;
		else
		  if (c == ' ')	
			nspc++;
		else
		  if (c == '\n')
			nnl++;
	}
	
	printf ("No of tabs = %d\t, No of space = %d\t, No of new lines = %d", ntab, nspc, nnl);
} 
