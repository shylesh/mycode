#include <iostream>
using namespace std;
template <typename T>
void call (T val)
{
	T a =  val;
	cout << a;
}

int main()
{
	int a;
	float b;

	a=1;
	b=2;

	call(a);
}

