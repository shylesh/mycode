#include <iostream>
#include <stdint.h>
#include <string.h>

using namespace std;

class SimpleCat
{
	private:
		char	*name;
		uint32_t *ptr_age;

	public:
		SimpleCat();
		~SimpleCat();
		uint32_t	get_age();
		char * 	get_name();
};

SimpleCat::SimpleCat()
{
	name = new char[10];
	ptr_age =  new uint32_t;

	strncpy(name, "pussy",10);
	*ptr_age = 10;

}

SimpleCat::~SimpleCat()
{
	delete[] name;
	delete ptr_age;
}

char * SimpleCat:: get_name()
{
	return name;
}

uint32_t SimpleCat::get_age()
{
	return *ptr_age;
}

int main()
{
	SimpleCat *pussy = new SimpleCat;
	{
		SimpleCat boots;
		cout << "boots age = " << boots.get_age();
		cout << "boots name = " << boots.get_name();

		cout << "again boots age = " << boots.get_age();
	}

	cout << pussy->get_age();
	cout << "pussy another name" << pussy->get_name();
	delete pussy;
}
