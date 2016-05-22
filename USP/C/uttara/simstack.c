#include <stdio.h>
#include <stdlib.h>

#define MAX 10
#define SIZE 10

int stack[MAX];
int sp;

int main()
{
	char *input = (char *) malloc (SIZE);
	int i;
	

	while (1) {

		printf ("< num > push \n: p or P for pop\n: e or E for exit\n");
		
		if(!fgets (input,SIZE, stdin))
			exit(1);
		for ( ; *input == ' ' || *input == '\t'; input++)
			;		

		switch(*input) {
		
		case '\n': continue;
		default: continue;
		case '0': case'1': case '2': case '3': case '4': 
		case '5':
		case '6': case '7': case '8': case '9':	 i = atoi(input);
							 if (sp == MAX) {
								printf ("full\n");
								continue;
							 } else stack[sp++] = i;
							 continue;
		case 'p': case 'P': if (!sp) {
					printf ("empty");
					continue;
				    }
				    else {
					printf ("%d popped\n", stack[--sp]);
					continue;
				    }

		case 'e': case 'E': if (sp) 
					while (sp--)
						printf ("%d\n", stack[sp]);
							 
				    exit(1);
		}
	}
}
							 
		
		
		
		
