#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

#define MAX 100

int compare (char *ele, char *data);

int main()
{
	int	ret;
	LIST 	*ld = NULL;
	int	size = sizeof(int);
	char	input[MAX];
	char	*p;
	int	num;
	int	ele;
		

	ld = list_open(size, compare);
	if (!ld) {
		printf ("open failed\n");
		exit(1);
	}

	while (fgets(input, MAX, stdin) != NULL) {
		for (p = input; (*p == ' ') || (*p == '\t'); p++)
			;

		switch(*p) {
		case '0': case '1': case '2': case '3':
			num = atoi(p);
			ret = list_insert (ld, (char *) &num);
			if (ret) 
				printf ("insert failed\n");
			break;
		case 'n' : case 'N':
			ret = read_bigger(ld,(char *) &ele);
			if (ret) {
				printf ("rn failed\n");
				break;
			}
			printf ("ele read is %d", ele);
			break;
		default :
			break;
		}
	}
} 
	
int
compare (char *ele, char *data) 
{

	return *(int *) ele - *(int *) data;
}
 
