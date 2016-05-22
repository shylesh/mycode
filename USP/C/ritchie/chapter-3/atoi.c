#include <stdio.h>
#include <ctype.h>

signed int atoi(char s[]);

int main()
{
	char	s[] = "-123";
	signed int	val;

	val = atoi(s);
	printf ("%d", val);
}


signed int 
atoi(char s[])
{
	int	i;
	int	val;
	int	sign = 1;

	for (i = 0; s[i] == ' '; i++)
		;

	if (s[i++] == '-')
		sign = -1;
	for( ; s[i] != '\0'; i++) 
		val = val * 10 + (s[i] - '0');
	return (sign * val);
}
	 	
