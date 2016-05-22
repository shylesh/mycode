#include <stdio.h>

int main()
{
	int	c;
	int	flag=0;
	int	w_count = 0;

	while ((c = getchar()) != EOF) {
		if (c == ' ') {
			if(flag) {
				w_count++;
				flag = 0;
			}
		}
		else
		   flag=1;
	}
	if (flag)	w_count++;

	printf ("Number of words = %d\n", w_count);
}
