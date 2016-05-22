#include <stdio.h>
#include <stdlib.h>

#define offset_of  (TYPE, MEMBER)  ((unsigned int) &((TYPE *)0)->MEMBER)

int main()
{

