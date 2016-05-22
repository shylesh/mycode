#include <stdio.h>

struct point makepoint (int x, int y);

struct point {
	int x;	
	int y;
	};

struct rect {
	struct point a;
	struct point b;
	}

int main()
{

	struct point a;
	int x=10;
	int y=20;

	a = makepoint (x, y);
	printf ("%d, %d", a.x, a.y);
	
		
}

struct point
makepoint (int x, int y)
{
	struct point b;

	b.x = x;
	b.y = y;

	return b;
}


