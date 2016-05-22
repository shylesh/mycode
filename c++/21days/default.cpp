#include <iostream>

using namespace std;

int sum(int a, int b = 10, int c=0);

int main()
{
	int 	ret;

	ret = sum(1, 1);
	cout << "sum = "<<ret;
}

int sum(int a, int b, int c)
{
	int sum = a+b+c;
	return sum;
}
