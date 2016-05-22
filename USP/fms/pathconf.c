#include <stdio.h>
#include <unistd.h>

int main()
{
	long long val;

	val = pathconf ("a.out", _PC_LINK_MAX);

	printf ("%zu", val);
}
