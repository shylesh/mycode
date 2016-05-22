#include <stdio.h>

#define PRINT(x)	printf (#x "= %d", x);

int main()
{
	int	i = 10;

	PRINT(i++);
}
