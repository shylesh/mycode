#include <stdio.h>

//int haha = sglobal;

extern static int sglobal;
extern int global;
extern static int add();

int main()
{
	int oh = sglobal;
	sglobal += 1;
	printf ("%d", sglobal);
	printf ("%d", global);
	add();
	hello();
}
