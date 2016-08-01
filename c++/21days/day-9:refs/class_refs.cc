#include <iostream>
#include <stdint.h>

using namespace std;

class Cat {
	public:
		Cat();
		~Cat();
		void SetItsAge(int age);
		int  GetItsAge();

	private:
		int its_age;
};

Cat::Cat()
{
	its_age = 1;
}

Cat::~Cat()
{
}

void Cat::SetItsAge(int age)
{
	its_age = age;
}

int Cat::GetItsAge()
{
	return its_age;
}

int main()
{
	Cat sibi;
	Cat &rsibi = sibi;

	cout << "age =" << rsibi.GetItsAge() << "\n";
	rsibi.SetItsAge(10);
	cout << "New age=" << rsibi.GetItsAge() << "\n";

}


