#include <stdio.h>

#define MAX 1000

void dcl(void);
void ddcl(int c);
int gettoken(void);

char name[MAX];
char dtype[MAX];
char out[MAX];

enum tokens = {PARANS, BRACES, NAME, PTR}


int main()
{

	int i;
	int c;

	/* getting the data type */
	for (i = 0; (c = getchar()) != ' '; i++)
		dtype[i] = c;
	
	dcl();

	printf ("%s is ", name);
	printf ("%s", dtype);

}

void dcl(void)
{

	int c;
	int ptr = 0;

	while ((c = gettoken()) != '\n') {
		if (c == PTR)
			ptr++;

		else
			ddcl(c);
	}
	
	
}

void ddcl()
{
	if ( c == PARANS) {
		if ((c = getchar()) == ')')
			printf ("function returning");
		dcl();
	}

	else
		if ( c == BRACES) {
			if ((c == getchar()) == ']')
				printf ("arr %c of", c);
			dcl();
		}

			 
}
	
		
	

		
	
