#include <stdio.h>
#include <ctype.h>

#define MAX_SIZE 20
#define NUMBER '0'
#define OPERATOR '1'

void	push (int a);
int	pop();
int	gettoken(char arr[]);

int	stack[MAX_SIZE];
int	top = -1;
int	i;

int main()
{
	int	c;
	char	arr[20];
	int	val;
	int	val2;

	while ( c = gettoken()) {
		switch(c) {
		case NUMBER:
			push(atoi(arr[i]));
			break;

		case '+':
			val = pop();
			push (pop() + val);
			break;
	
		case '-':
			val = pop();
			push (pop() - val);
			break;
		
		case '*':
			val = pop();
			push (pop() * val);
			break

		case '/':
			val = pop();
			push (pop() / val);
			break;

		case '\n':
			printf ("val is %d\n", pop());
			break;

		case default:
			printf ("Irrelevant input\n");
			exit (1);
		}
	}
			 
}
		
	

int
gettoken (char arr[])
{
	
	
