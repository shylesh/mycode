#include <iostream>
#include <string>
#include <stdint.h>

using namespace std;

class Cat {
	private:
		uint32_t 	itsage;
		string 		sound = "Meow";

		void make_sound();

	public:
		Cat(uint32_t init_age);
		~Cat();
		uint32_t get_age();
		void set_age(uint32_t);
};

Cat::Cat(uint32_t init_age)
{
	itsage=init_age;
}

Cat::~Cat()
{
}

uint32_t Cat::get_age()
{
	return itsage;
}

void Cat::set_age(uint32_t age)
{
	itsage = age;
	make_sound();
}

void Cat::make_sound()
{
	cout << sound <<"\n";
}



int main()
{
	Cat pussy(1);

	cout << "init age is " << pussy.get_age();
	pussy.set_age(5);
	cout << "age is " << pussy.get_age();
//	pussy.make_sound();
}

