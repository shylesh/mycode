#include <stdio.h>

unsigned int hweight32(unsigned int w);


int main()
{

	unsigned int w = 0xFFFFFFF;
	int num;

	num = hweight32(w);

	printf ("number of 1's is %d\n", num);
}

	
	
unsigned int hweight32(unsigned int w)
{
        unsigned int res = w - ((w >> 1) & 0x55555555);
        res = (res & 0x33333333) + ((res >> 2) & 0x33333333);
        res = (res + (res >> 4)) & 0x0F0F0F0F;
        res = res + (res >> 8);
        return (res + (res >> 16)) & 0x000000FF;
}

