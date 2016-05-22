#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "stack.h"

#define NITEMS 50

int main()
{
	int num;
	STACK *sd = NULL;
	char line[100];
	char *p;

	sd = open_stack (NITEMS, sizeof (num));
	if (sd == S_FAIL) exit (1);

	while (1) {
		printf ("<num> : to push \n p or P to pop \n ");
		if (fgets (line, 100, stdin) == NULL)	exit(2);
		for (p = line; *p == ' ' || *p == '\t'; p++)
			;


		switch(*p) {
			case '0' : case '1' : case '2' : case '3' :
			case '4' : case '5' : case '6' : case '7' :
			case '8' : case '9' : 
				if (STACK_FULL(sd))	continue;
				num = atoi (p);
				push (sd, (char *)&num);
				break;

			case 'p' : case 'P' :
				if (STACK_EMPTY(sd)) continue;
				pop (sd, (char *) &num);
				printf ("Element popped is %d\n", num);
				break;
			
			case 'e' : case 'E':
				while (!STACK_EMPTY(sd)) {
					pop (sd, (char *) &num);
					printf ("Element popped is %d\n", num);
				} exit(0);
		}
	}
}
					
			
					
	
	
