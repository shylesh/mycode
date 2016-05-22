#include <iostream>

using namespace std;

class cat{

	int	height;
	int 	weight;

public:
	void 	print();
};

void cat::print()
{
	cout << "hello";
	height = 1;
	cout << height;
}

int main()
{
	cat c1;

	c1.print();
}

