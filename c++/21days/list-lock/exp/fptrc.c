#include <stdio.h>

int add(int, int);
int sub(int, int);
typedef int (*fn)(int, int);

struct emb {
	int i;
	int j;
	fn f_ptr;
};

void call(struct emb);

int main()
{
	struct emb e1;
	fn add_ptr;
	fn sub_ptr;
	add_ptr = add;
	sub_ptr = sub;

	int ch;

	printf ("Enter choice 1 or 2\n");
	scanf("%d", &ch);
	switch(ch)
	{
	case 1: e1.i = 5;
		e1.j = 2;
		e1.f_ptr = add_ptr;
		call(e1);
		break;

	case 2: e1.i = 5;
		e1.j = 2;
		e1.f_ptr = sub_ptr;
		call(e1);
		break;
	}
}

void call(struct emb e)
{

	(*e.f_ptr)(e.i,e.j);
}

int sub(int i, int j)
{
	int diff = i-j;
	printf ("diff = %d\n", diff);
	return diff;
}

int add(int i, int j)
{
	int sum = i+j;

	printf ("sum = %d", sum);
	return sum;
}
