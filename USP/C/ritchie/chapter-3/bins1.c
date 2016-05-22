#include <stdio.h>

int	binsearch (int x, int v[], int n);

int main()
{
	int	v[23] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23};
	int	x = 4;
	int	ret = 0;
	
	printf ("array size = %d\n", sizeof(v));

	ret = binsearch (x, v, sizeof(v) / sizeof(int));	
	
	if (ret) 
		printf ("Element found at %d pos", ret);
	
	else
		printf ("Not found\n");
}

int
binsearch (int x, int v[], int n)
{
	int	low = 0;
	int	high = n - 1;
	int	mid;
	

	while (low <= high) {
		mid = (low + high) / 2;
		if (x == v[mid])
			return mid;

		else
			(x < v[mid]) ? (high = mid + 1) : (low =  mid + 1);
	}

	return 0;
}
	
