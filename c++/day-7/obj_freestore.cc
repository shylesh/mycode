#include <iostream>
#include <stdint.h>

using namespace std;

class Cat {
	private:
		char name[10];
		uint32_t age;

	public:
		Cat(uint32_t init_age);
		~Cat();
		uint32_t get_age();
		void set_age(uint32_t itsage);
};

Cat::Cat(uint32_t init_age)
{
	age = init_age;
}

Cat::~Cat()
{

}

uint32_t Cat::get_age()
{
	return age;
}

void Cat::set_age(uint32_t itsage)
{
	age = itsage;
}

int main()
{
	Cat *pussy = new Cat(1) ;

	cout << "init age is " << pussy->get_age();
	pussy->set_age(11);
	cout << "new age is " << pussy->get_age();
	cout << "size of Cat is \n" << sizeof(Cat);
}


