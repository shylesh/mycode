#include <stdio.h>
#include <unistd.h>

int main()
{
	long long val;

	val = sysconf (_SC_PAGE_SIZE);

	printf ("%zu", val);
}
