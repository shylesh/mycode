#include <iostream>

using namespace std;

void modify(int& a_ref);

int main()
{

	int a = 10;
	int&	a_ref = a;

	modify(a);
	cout << "&a = " << &a << "\n";
	cout << "&a_ref = " << &a_ref <<"\n";
	a_ref++;
	cout <<a_ref<<"<<>>";

	cout << a;

}

void modify(int& a_ref)
{
	cout << "&aref inside fun = " << &a_ref << "\n";
	a_ref++;
}
