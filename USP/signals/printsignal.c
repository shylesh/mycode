#include <signal.h>
#include <string.h>

int main()
{
	int	i;

	for (i = 0; i < 32; i++)
		printf ("%d-->%s\n", i, strsignal(i));
}
