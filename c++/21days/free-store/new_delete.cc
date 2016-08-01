#include <iostream>
#include <stdint.h>

using namespace std;

class SimpleCat
{
	private:
		char	name[10];
		uint32_t age;

	public:
		SimpleCat();
		~SimpleCat();
		uint32_t	get_age();
};

SimpleCat::SimpleCat()
{
	age = 1;
}

SimpleCat::~SimpleCat()
{
}

uint32_t SimpleCat::get_age()
{
	return age;
}

int main()
{
	SimpleCat *pussy = new SimpleCat;
	{
		SimpleCat boots;
		cout << "boots age = " << boots.get_age();

		cout << "again boots age = " << boots.get_age();
	}

	cout << pussy->get_age();
	delete pussy;
}
