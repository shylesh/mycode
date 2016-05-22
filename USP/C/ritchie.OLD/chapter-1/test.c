#include <stdio.h>

#define SLASH '/'
#define STAR  '*'
#define IN	1
#define OUT	0
#define MAX	1024
	

int main()
{
	int	status = OUT;
	int	c;
	char	look_behind_char = 0;
	int	i = 0;
	char	back_array[MAX];
	int	j;


	while ((c = getchar()) != EOF) {

		if (c == '\n')	continue;

		else if (c == SLASH)  {
			/*check //  / **is this the beginning*/
			if (status == OUT) {
				look_behind_char = c;
				c = getchar();
				if (c == STAR) {
					i = 0;
					status = IN;
					back_array[i++] = look_behind_char;
					back_array[i++] = c;
					status = IN;
				}	

				else 	{
					putchar(look_behind_char);
					putchar(c);
				}
	
			} 
		}	

		else if (c == STAR) {

			/*check are we alrady inside comment */

				look_behind_char = c;
				c = getchar();
				if (status == IN) {
					if (c == SLASH)
						status = OUT;
					back_array[i++] = look_behind_char;
					back_array[i++] = c;
				}
				
				else {
					putchar(look_behind_char);
					putchar(c);
				}
		    
		}
	
		else if (status == IN ){
			back_array[i++] = c;

		}
	
		else putchar(c); 

	}	

	if (status == IN) {
	/* this is the state where comments was not ended 
 	 * so will not be considered as comment
 	 * just spit out
 	 */
		for (j = 0; j < i; j++)
			printf ("%c", back_array[j]);
	}


}
