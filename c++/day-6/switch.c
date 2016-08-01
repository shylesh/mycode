#include <iostream>
#include <stdint.h>

using namespace std;

int main()
{
	uint32_t 	num;

	cout << "enter a number";
	cin >> num;

	switch(num > 1)
	{
		case 0: cout << 1;
			break;

		case 1: cout << 2;
			break;

		default: cout << "m not interested in this number ";
	}
}
