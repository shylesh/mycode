#include <iostream>

using namespace std;

struct test {
	int i;
	int j;
};

int main()
{
	test a;

	a.i = 1;
	a.j = 2;

	cout << a.i << a.j;
}
