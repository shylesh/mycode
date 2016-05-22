#include <stdio.h>

unsigned int setbits (int num, int pos, int num_bits, int num2);
unsigned int getbits (int num, int pos, int num_bits);

int main()
{
	int	num = 15;
	int	num2 = 2;
	int	pos = 1;
	int	num_bits = 2;
	int	ret;
	int	mask = 0;

	ret = getbits (num, pos, num_bits);
	num2 = (num2 | (~(~mask << num_bits))); 


	ret = setbits (ret, pos, num_bits, num2);
	ret = ret << (pos + 1 - num_bits);
	printf ("%d\n", ret);
}

unsigned int
setbits (int num, int pos, int num_bits, int num2)
{
	
	
	return (num | num2);

}

unsigned int
getbits (int num, int pos, int num_bits) 
{
	int	mask = 0;

	return ( (num >> (pos + 1 - num_bits)) & ~(~mask << num_bits));
}
	

 
