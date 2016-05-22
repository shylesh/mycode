#include <stdio.h>

static char (*ptr)[10] = {
	 "a" ,
	 "b" 
};


int main()
{
	int i;

	for (i = 0; i < 3; i++)
		printf ("%s", *(ptr + i));	
}
