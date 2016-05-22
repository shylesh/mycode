#include <stdio.h>
#include <ctype.h>

int substr(char s[], char d[]);
void getline1(char s[]);



int main()
{
	char s[10];
	int index ;
	char pat[] = "el";

	getline1(s);
	
	if ((index = substr(s, pat)) >= 0) 
		printf ("substring starts at index %d\n", index);
	
	else
		printf ("substring not present\n");
}

void
getline1 (char s[])
{
	int	c;
	int	i;
	
	for (i = 0; (c = getchar()) != '\n'; i++)
		s[i] = c;
	s[i] = '\0';
}
			
int
substr(char s[], char dest[])
{
	int	i;
	int	j;
	int	k;

	printf ("string is %s\n", s);
	printf ("substring is %s\n", dest);

	for (i = 0, j = 0; s[i] != '\0'; i++) {
		if (s[i] != dest[j])
			continue;

		for (k = i; (s[k] == dest[j]) && (dest[j] != '\0'); k++, j++);

		if (dest[j] == '\0')
			return i;
		else
		   	j = 0;
	}
	return -1;
}
		  
 

	
