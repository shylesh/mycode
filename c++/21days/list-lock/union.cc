#include <iostream>

using namespace std;

union myunion {
	int a;
	char b;
	int c;
};

int main()
{
	union myunion un;

	un.a=1;
	un.b='c';
	un.c=2;

	cout << un.a ;
	cout << un.b << un.c;
}

