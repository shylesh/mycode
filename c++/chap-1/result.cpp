#include <iostream>

int main()
{
	int x = 1;
	int *p = &++x;
//	int *q = &(x++);
	int y = x++;
//	std::cout << x << "&x="<<&x<<'\n'<< "y="<<y;
	printf ("%d", y);
}

