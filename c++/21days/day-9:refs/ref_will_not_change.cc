#include <iostream>

using namespace std;

int main()
{
	int i = 1;
	int &rint = i;

	cout << "i = " << i << "\n";
	cout << "from &i- i = " << rint <<"\n";

	int j = 2;
	rint = j;
	j = 3;

	//change i through ref

	cout << "i = " << i <<"\n";
	cout << "from &i- i = " << rint << "\n";
	return 1;
}
