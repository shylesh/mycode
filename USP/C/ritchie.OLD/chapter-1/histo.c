#include <stdio.h>

#define IN	0
#define OUT	1
#define SPACE	' '

int main()
{
	int	c;
	int	i, j;
	int	status = OUT;
	int	length_array[20];
	int	length = 0;

	for (i = 0; i < 20; i++)
		length_array[i] = 0;


	while ((c = getchar()) != EOF) {
		if (c == SPACE) {
			if(status == IN) {
				++length_array[length];
			}
			status = OUT;
			length = 0;
		}

		else
			if (c == '\n' || c == '\t')
				continue;
		else {
			if(status == OUT)
				status = IN;
			length++;		
		}	
	}

	
