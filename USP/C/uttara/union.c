#include <stdio.h>
#include <string.h>

#define SHORT	0
#define LONG	1
#define DOUBLE	2

struct short_t {
	int type;
	short val;
};

struct long_t {
	int type;
	long val;
};

struct double_t {
	int type;
	double val;
};

union mix {
	int type;
	struct short_t shrt;
	struct long_t lng;
	struct double_t dbl;
};


void 
print_fn (union mix a);

int main()
{
	union mix a, b, c ;

	a.type = SHORT;
	a.shrt.val = 30;

	b.type = LONG;
	b.lng.val = 123123123;

	c.type = DOUBLE;
	c.dbl.val = 3.14;

	print_fn(a);
	print_fn(b);
	print_fn(c);

	return 0;
}

void
print_fn (union mix var)
{
	if (var.type == SHORT)
		printf ("type = SHORT , val= %d\n", var.shrt.val);
	else
		if (var.type == LONG)
			printf ("type = LONG, val= %ld\n", var.lng.val);
	else
		if (var.type == DOUBLE)
			printf ("type = DOUBLE, val =%lf\n", var.dbl.val);
}
					
	
