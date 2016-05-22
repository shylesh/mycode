#include <stdio.h>
#include  "static.c"

//int haha = sglobal;
int main()
{
	int oh = sglobal;
	sglobal += 1;
	printf ("%d", sglobal);
	printf ("%d", global);
	add();
	hello();
}
