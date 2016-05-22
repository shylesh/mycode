#include <stdio.h>

typedef void printer (const char *);

void invoke (printer *);

printer pr;

int main()
{
	invoke (pr);
}

void
invoke (printer *pfun)
{
	char 	*str = "hello world\n";

	pfun (str);

}

void
pr (const char *str)
{

	printf ("%s", str);

}
