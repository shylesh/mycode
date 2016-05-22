#include <stdio.h>
#include <stdlib.h>

struct test {
	int a;
	char b;
	float c;
	double d;
};


int main()
{

	unsigned int offset;
	struct test *t;

	offset = ((unsigned int)&(t->d)) - ((unsigned int) (struct test *)0);

	printf ("%zu", offset);
}

