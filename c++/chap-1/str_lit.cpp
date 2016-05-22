#include <iostream>

using namespace std;

string strin_ret();

int main()
{
	string ret;

	ret = strin_ret();
	cout<<ret<<'\n'<<&ret;
}

string strin_ret()
{
	return "Hello";
}
