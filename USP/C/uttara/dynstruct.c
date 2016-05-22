#include <stdio.h>


struct test {
	int a;
	double y;
	char d[1];
};

int main()
{
	struct test *t;


	t = (struct test *) malloc (sizeof(*t) + 100);

	t->d[90] = 'h';
	t->d[91] = 'i';

	printf ("%c%c\n", t->d[90], t->d[91]);
}
	
