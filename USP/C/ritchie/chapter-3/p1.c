#include<stdio.h>
void main()
{

	if(1)
	{	
		printf("inside if");
		goto l1;
	}		
	else 
		l1: printf("inside else");
}
