#include <stdio.h>

#define defval 1


struct b {
	int l;
	struct  {
		int a ;
		int b ;
	};

	int i;

};

int main()
{
	struct b test;

	printf ("%d", test.a);
}

