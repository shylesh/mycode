/*
 * scheme: <num> : append
 * 		   c or C: create a new list
 *		   d or D: delete
 *		   n or N: read next
 *		   p or P: read previous
 *		   f or F: read first
 *		   l or L: read last
 *		   e or E: exit
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10

#include "list.h"

int main() 
{
	char 	ch[1024];
	char	ele[1024];
	int 	stack_exists = 0;
	LIST 	*ld = NULL;
	int 	ret = 0;
	char	*p;

	printf ("<num> : append \n	\
  		   c or C: create a new list\n\
 		   d or D: delete\n\
 	   	   n or N: read next\n\
 		   p or P: read previous\n\
	   	   f or F: read first\n\
		   l or L: read last\n\
		   e or E: exit\n");


	while(1) {
		gets(ch);
		for (p = ch ; (*p == ' ' )|| (*p == '\t'); p++ )
			;

		switch(*p) {
		case '0' : case '1' : case '2': case '3':
		case '4' : case '5' : case '6': case '7':
		case '8' : case '9' : 
			if (!stack_exists)
				ld = list_open(sizeof(int));
				if (!ld) exit(1);
			ret = list_append(ld, ch);  
			if (ret) 
				exit(1);
			break;

		case 'd': case 'D':  
			ret = list_del(ld);
			if (ret)	exit(1);
			break;
		
		case 'n' : case 'N':
			ret = read_next(ld, ele);
			if (ret)	exit(1);
			printf ("read next = %d\n", ele);
			break;

		case 'p' : case 'P':
			ret = read_prev(ld, ele);
			if(ret)	exit(1);
			printf ("read prev= %d\n", ele);
			break;

		case 'f' : case 'F':
			ret = read_first(ld, ele);
			if (ret)	exit(1);
			printf ("read first= %d\n", ele);
			break;

		case 'l': case 'L':
			ret = read_last(ld, ele);
			if (ret)	exit(1);
			printf ("read last= %d\n", ele);
			break;

		case 'e' : case 'E':
			ret =  list_close(ld);
			if (ret > 0)	exit(1);
			break;
		}
	}
}
				
		

			
			

	
	
