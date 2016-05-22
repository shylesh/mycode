#include <stdio.h>

#define MAX_LENGTH	1024

void reverse (char str[]);
void read_line(char arr[]);

int main()
{
	char	arr[MAX_LENGTH];
	

	read_line(arr);
	printf ("line is %s\n", arr);
	reverse(arr);
	printf ("after reversing line is :\t %s", arr);
}

void
read_line(char arr[]) 
{
	int	i = 0;
	int	c;

	while ((c = getchar()) != EOF) 
		arr[i++] = c;
	arr[i] = '\0';
}

void
reverse(char arr[]) 
{
	char 	temp;
	int	i = 0;
	int	j = 0;

	while (arr[++i] != '\0')
		;
	i--;

	//printf ("end of while\n");
	for (j = 0; j <= i; j++, --i) {
		temp = arr[j];
		arr[j] = arr[i];
		arr[i] = temp;
	//	printf ("%d, %d, %c, %c\n", i, j, arr[i], arr[j]);
	}
}

 	
		
			

	
