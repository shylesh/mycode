#include <stdio.h>

int to_lower(int c);


int main()
{
	int c;

	while ((c = getchar()) != EOF) {
		if (c == '\n')	continue;
		printf ("%c", to_lower(c));
	}

}

int
to_lower (int c)
{

	return (((c >= 'A') && (c <= 'Z')) ? (c - 'A' + 'a') : '0');
}

