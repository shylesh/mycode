#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1024

char *array[MAX];
int gi = 0;


void getline1 (char **arr);
int grep (char **array, char *str);

void getline1 (char **arr)
{
	int c;
	int i;
	int n = 0;
	char p[MAX];
	char filter;

	filter = getchar();
	

	
	for (i = 0; (c = getchar()) != '\n'; i++) {
		p[i] = c;
	}	
	p[i] = '\0';
	
	*arr = (char *) malloc(i * sizeof(char));

	strcpy (*arr, p);
}	


int 
main()
{
	int c;
	char ch;
	int j;
	char str[10];
	int ret = 0;

	while (gi < MAX) {
			
		printf ("enter your choice\n\n");
		printf ("D or dfor display\n\n");
		printf ("I or ifor insert a line\n");
		printf ("s or S for search\n\n");
		scanf ("%c", &ch);

		switch(ch) {

		case 'd': case 'D':
			for (j = 0; j < gi; j++)
				printf ("%s\n", array[j]);
			break;

		case 'i': case 'I':
			getline1(&array[gi++]);
			break;

		case 's': case 'S':
			printf ("enter the string");
			scanf ("%s", str);
			ret = grep(array, str);
			if(ret)
				printf("string found at line no %d \n", ret);
			else
				printf ("string not found\n");
			break;

		default:
			continue;
		}
	}
					
}
			
int
grep (char **array, char *str)
{
	int var;
	char *ret;

	for (var = 0; var < gi; var++) {
		ret = strstr(array[var], str);
		if(ret)
			return var + 1;
		else
			continue;
	}
	return 0;
}
				 
			
			

	
	
			  
	
		

