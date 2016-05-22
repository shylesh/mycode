#include <stdio.h>
#include <stdlib.h>

int find_len (const char *ptr);

struct sdstr {
	long len;
	long free;
	char buf[];
};

int main()
{
	struct sdstr *s1;

	s1 = malloc (sizeof(struct sdstr) + 5 + 1);
	s1->len = 10;
	s1->free = 0;

	find_len (s1->buf);

}

int
find_len (const char *ptr)
{
	struct sdstr *s2;

	s2 = (void *) (ptr - (sizeof(struct sdstr)));

	printf ("%zu\n",  s2->len);

}

