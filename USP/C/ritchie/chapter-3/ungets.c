#include <stdio.h>
#include <ctype.h>

void ungets(char s[]);
int ungetch(int c);

int	line_count = 0;

int main()
{
	char 	s[1024];
	int	c;
	int	i = 0;

	while ((c = getchar()) != EOF) {
		if (c == '\n')
			line_count++;
		s[i++] = c;
	}	
	s[i] = '\0';

	if (line_count > 3)
		ungets(s);
	printf ("after ungets lines are: %s", s);
	printf ("===============");
	while (c = getchar())
		printf ("%c", c);
}

void
ungets(char s[])
{
	int	i = 0;
	int	local = 0;
	printf("line count is %d :", line_count);
	while (local < line_count) {
		if (s[i++] == '\n')
			local++;
	} 
	printf("value of local %d",local);
	i -= 2;

	while (s[i] != '\n') {
		ungetch(s[i]);
		i--;
	}
	s[++i] = '\0';
	printf ("string inside func is : %s", s);
}
		
int
ungetch(int c)
{
//	printf (" char pusing back is %c", c);
	ungetc(c, stdin);
}
