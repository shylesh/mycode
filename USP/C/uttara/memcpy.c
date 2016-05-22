#include <stdio.h>
#include <string.h>
#include <time.h>

#define MAX 10000

int main()
{
	char arr[MAX] ;
	char arr1[MAX];
	char arr2[MAX];
	time_t tim ;
	time_t tim1;
	int i;

	for (i = 0; i < MAX-1; i++)
		arr[i] = i;

	tim = time(NULL);
	printf ("%zu is tim\n", tim);
	memcpy(arr1, arr, MAX-1);
	tim1 = time(NULL);
	printf ("%zu is tim1\n", tim1);
	printf ("memcpy took %zu seconds\n", (tim1 - tim));

	tim = time(NULL);
	printf ("%zu is tim\n", tim);
	for (i = 0; i < MAX - 1; i++)
		arr2[i] = arr[i];
	tim1 = time(NULL);
	printf ("%zu is tim1\n", tim1);
	printf ("arr copy took %zu s\n", (tim1 - tim));


}
