#include <iostream>
#include <stdint.h>

using namespace std;

void swap (int &refa, int &refb);

int main()
{
	int a = 10;
	int b = 20;

	cout << "before swap a = " << a << "b = " << b << "\n";
	swap(a, b);
	cout << "after swap a = " << a << "b = " << b << "\n";
}

void swap(int &refa, int &refb)
{
	int c;
	c = refa;
	refa = refb;
	refb = c;
}

