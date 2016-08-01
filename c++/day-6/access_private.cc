#include <iostream>
#include <string>
#include <stdint.h>

using namespace std;

class Cat {
	private:
		uint32_t 	itsage;
		string 		sound = "Meow";

	public:
		uint32_t get_age();
		void set_age(uint32_t);
		void make_sound();
};

uint32_t Cat::get_age()
{
	return itsage;
}

void Cat::set_age(uint32_t age)
{
	itsage = age;
}

void Cat::make_sound()
{
	cout << sound <<"\n";
}



int main()
{
	Cat pussy;

	pussy.set_age(5);
	cout << "age is " << pussy.get_age();
	pussy.make_sound();
}

