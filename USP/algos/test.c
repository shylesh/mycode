#include <stdio.h>

void func(int a[]);

int main()
{
	int a[] = {1,2,3,4,5};

	printf ("address of a in main is %p\n", a);
	printf ("size of array is %d\n", (sizeof (a) / sizeof(a[0])));

	func(a);

}

void
func(int a[])
{
	printf ("inside func %p", a);
	printf ("len of arr is %d\n", (sizeof(a) / sizeof(a[0])));
}
