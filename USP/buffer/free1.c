#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct s0 {
	int *a;
};

int main()
{
	struct s0* s = malloc(sizeof(struct s0));
	if (!s)
		return -1;

	s->a = malloc (sizeof(int));
	*(s->a) = 777;

	free(s);

	int k;
	memcpy(&k, s->a, sizeof(int));
}
