#include <stdio.h>
#include <string.h>

struct sdshdr {
    unsigned int len;
    unsigned int free;
    char buf[];
};

void func (char *s);

int main()
{

	struct sdshdr test;

	test.len=10;
	test.free=1;
	strcpy (test.buf, "hello");

	func(test.buf);
}

void
func (char *s)
{

	struct sdshdr *tmp = (struct sdshdr *) (s-sizeof(struct sdshdr));

	printf ("%d\n", tmp->len);
}
