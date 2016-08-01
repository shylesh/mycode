#include <iostream>
#include <stdint.h>

using namespace std;

class Sample {
	public:
		Sample();
		Sample(uint32_t var);
		~Sample() {};

	private:
		uint32_t my_val;
};

Sample::Sample():
		my_val(0xEEFF)
{
	cout << "inside constructor'n";
	cout << my_val;
}

Sample::Sample(uint32_t var):
		my_val(var)
{
	cout << "inside param constructor\n";
	cout << my_val;
}

int main()
{
	Sample sam1;

	Sample sam2(0XABCD);
}
