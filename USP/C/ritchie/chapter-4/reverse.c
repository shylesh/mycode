#include <stdio.h>

int	reverse (char s[]);

int main()
{
	char s[] = "hello";

	reverse(s);
	printf ("%s\n", s);
}

int
reverse (char s[])
{
	int	c;
	static int i = 0;
	

	if (s[i] == '\0') {
		i = 0;
		return;
	}

	else {
		c = s[i++];
		reverse(s);
	}

	s[i++] = c;
}
