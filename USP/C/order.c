#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
	double n = 1;

	while (n <= 10000) {
		printf (" pow(2,n) = %zu \n", pow (2, 2));
		/*printf (" pow(pow(2,n), n) = %lld\n", pow(pow(n,2), 2));
		printf (" n logn = %ld\n", n * log(n));
		printf ("n2 = %ld\n", n * n);
		printf ("pow (logn, n) = %lld\n", pow(log(n), n)); */
		n *= 10;
	}
}
	 

