#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

struct new {
	int i;
	char *ptr;
};

int main()
{
	struct new *index=NULL;

	index = malloc(sizeof(*index));
	index->i = 100;
	index->ptr = malloc(10);

	strcpy(index->ptr, "hello");
	printf ("%s", index->ptr);
	printf ("%d", index->i);

	free(index);
	printf ("%s", index->ptr);
	printf ("%d", index->i);
}
