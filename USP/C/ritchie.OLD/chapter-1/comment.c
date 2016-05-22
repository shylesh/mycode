#include <stdio.h>

#define SLASH '/'
#define STAR  '*'
#define IN	1
#define OUT	0
	

int main()
{
	int	status = OUT;
	int	c;
	int	look_behind_char = 0;
	int	i = 0;
	char	back_array[1024];

	while ((c = getchar()) != EOF) {

		if (c == '\n')	continue;

		else if (c == SLASH)  {
			/*check //  / **is this the beginning*/
			if (status == OUT) {
				look_behind_char = c;
				c = getchar();
				if (c == STAR) {
					status = IN;
					back_array[i++] = look_behind_char;
					back_arry[i++] = c;
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

			if (status == IN) {
				look_behind_char = c;
				c = getchar();
				if (c == SLASH) {
					status = OUT;
					back_array[i++] = look_behind_char;
					back_array[i++] = c;
				}
				
				else {
					putchar(look_behind_char);
					putchar(c);
				}
		    }
	
		}
	
		else putchar(c);

	}	
}
