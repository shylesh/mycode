#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "list.h"

#define MAX 50

LIST * 	do_list_open(int size);
int	do_list_append(LIST *ld, char *ele);
int	do_read_first(LIST *ld, char *ele);
int	do_read_last(LIST *ld, char *ele);
int	do_read_next(LIST *ld, char *ele);
int	do_read_prev(LIST *ld, char *ele);
int	do_list_del(LIST *ld);


int main()
{
	char 	input[MAX];
	char 	*p = NULL;
	LIST 	*ld = NULL;
	int 	num;
	int 	ret = 0;

	do_list_open(sizeof(int));

	while (1) {
		if(fgets(input, MAX, stdin) == NULL)	exit(2);
		for (p = input; (*p == ' ') || (*p == '\t'); p++)
			;

		switch(*p) {
			case '1' : case '2': 
				num = atoi(p);
				do_list_append(ld, (char *)&num);

		}
	}	
}


LIST * do_list_open(int size) {

	LIST *ld = NULL;
	ld = list_open(size);
	if (!ld) {
		printf("list open failed\n");
		exit(1);
	}
	return ld;
		
					
}

int do_list_append(LIST *ld, char *ele)
{
	if (list_append(ld, ele) == L_SUCCESS)
		printf ("ok\n");
	else printf ("can't append\n");
}

int do_read_next(LIST *ld, char *ele)
{
	if(list_empty(ld))	printf ("empty list");

	else if (read_next(ld, ele) == L_SUCCESS)
		printf ("read_next success\n");
	else printf ("read_next fail\n");
}


int do_read_prev (LIST *ld, char *ele)
{
	if (list_empty(ld))	printf ("empty list");

	else if (read_prev(ld, ele) == L_SUCCESS)
		printf ("read prev success\n");
	else printf ("read prev fal\n");
}


int do_list_del(LIST *ld)
{
	if (list_empty(ld))	printf ("empty list");
	else if (list_del(ld) == L_SUCCESS)
		printf ("delete succeeded\n");
	else	printf ("del failed\n");
}	
		
		 
		
