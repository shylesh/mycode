#include <stdio.h>

void hi();
void hello();
void call(void (*fun) (void));


int
main() 
{
	int val = 0;

	call((void (*) (void)) (val ? hi : hello));
}

void
hi() {
	printf ("HI");
}

void
hello()
{
	printf ("hello");
}

void
call(void (*fun)(void))
{
	(*fun)();
}
