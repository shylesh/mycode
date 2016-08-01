#include <iostream>

using namespace std;

int main()
{
	int  *ptr;

	ptr = new int;
	*ptr = 100;

	cout << ptr<<"\n";
	cout << *ptr;
	delete ptr;
	cout << ptr;
	ptr=0;
	delete ptr;
}
