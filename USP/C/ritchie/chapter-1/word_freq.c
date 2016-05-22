#include <stdio.h>

#define GRAPH	#

int main()
{
	int	c;
	int	i;
	int	freq_arr[26];
	int	j;
	int	sum ;

	for (i = 0; i < 26; i++)
		freq_arr[i] = 0;	
	
	while ((c = getchar()) != EOF) {
		if (c == ' ' || c == '\n' || c == '\t')
			;

		++freq_arr[c - 'a'];	
	}

	/* draw histo */
	do {	
		for (i = 0, sum = 0; i < 26; i++) {
			if (freq_arr[i]) {
				printf ("%2c", '#');
				sum += freq_arr[i]--;
		
			}
			else printf ("%2c", ' '); 
		}
		printf ("\n");
	}while (sum);
	

	for (i = 0; i < 26; i++ )
		printf ("%2c", 'a' + i);

	
		
}
	
