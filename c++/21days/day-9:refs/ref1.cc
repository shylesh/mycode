#include <iostream>

using namespace std;

int main()
{
	int i = 1;
	int &rint = i;

	cout << "i = " << i << "\n";
	cout << "from &i- i = " << rint <<"\n";

	//change i through ref
	rint = 10;

	cout << "i = " << i <<"\n";
	cout << "from &i- i = " << rint << "\n";
	return 1;
}
