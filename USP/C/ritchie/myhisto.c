#include <stdio.h>

#define IN	0
#define OUT	1
#define SPACE	' '
#define GRAPH_CHAR '#'


int main()
{
	int	c;
	int	length;
	int	length_array[20];
	int	index = 0;
	int	state = OUT;
	int	i;
	int	j;

	for (i = 0; i < 20; i++)
		length_array[i] = 0;

	while ((c = getchar()) != EOF) {
		if(c == SPACE) {
			if(state == IN) {
				length_array[index] = length;	
				length = 0;
				index++;
			}
			state = OUT;
		}	
	
		else if (c == '\n' || c == '\t')
			continue;
	
		else  {
			if(state == OUT) {
				state = IN;
			}
			length++;
		}
	
			
	}

	index++;
	/* draw the chart */
	printf ("Number of words = %d\n", index);
	
	for (i = 0; i < index; i++) {
		printf ("%d", i );
		for (j = 0; j < length_array[i]; j++)
			printf ("%c", GRAPH_CHAR);
		printf ("\n");
	}
	
}
