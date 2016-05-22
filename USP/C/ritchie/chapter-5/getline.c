#include <stdio.h>

#define MAX_LINE 100
#define MAX_SIZE 1024

char allocbuf[MAX_SIZE];
int bufp = 0;

char *alloc(int size);
void getline1(char line[], int nchar);

char *
alloc(int size) {

	char *ptr = NULL;

	if ((bufp + size) > MAX_SIZE) /*No memory to allocate*/
		return NULL;

	else {
		ptr = &allocbuf[0] + bufp;	
		bufp += size;
		return ptr;
	}
}

int 
free(char *ptr) {

	int size;

	if (bufp < 0)
		return -1;
	else {
		size = 
				

int 
main()
{
	char *ret;

	ret = alloc(1000);
	if (ret)
		printf ("alloc success\n");
	else
		printf ("alloc failed\n");
}	

