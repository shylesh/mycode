#include <stdio.h>

int main()
{
	int nc = 0;
//	int c;

/*	while (getchar() != EOF ) 
		nc++;
	
*/

	for ( ; getchar() != EOF; nc++)
		;
	
	printf (" Total charecters are %2d\n", nc);
}
