#include <stdio.h>

#define MAX_LINE 20
#define MAX_LENGTH 100
#define MAX(a, b) ((a > b) ? a:b)

int get_line(char a[]);
void copy_longest(char arr[], char longest_arr[], int length);

int main()
{
	int	c, i;
	int	length = 0;
	int	longest = 0;
	char	arr[MAX_LENGTH] = {0, };
	char 	longest_arr[MAX_LENGTH] = {0, };


	while ((length = get_line(arr)) != 0) {
		if (length > longest) {
			copy_longest(arr, longest_arr, length);		
			longest = length;
		}
	}

	printf ("longest line is \n");
	for (i = 0; i < longest; i++)
		printf ("%c", longest_arr[i]);
}

int get_line (char a[])
{
	int	i;
	int	length = 0;

	while ((i = getchar()) != EOF) {
		if (i == '\n')
			return length;
		else
			if (i == ' ' || i == '\t')	continue;
		else {
			a[length] = i;
			length++;
		}
	}
	return length;
}


void copy_longest(char *a, char *longest_arr, int length)
{
	int	i;

	for (i = 0; i < length; i++)
		longest_arr[i] = a[i];
}	
