#include <iostream>
#include <stdint.h>

using namespace std;

class Cat {
	public:
		Cat();
		Cat(const Cat & rhs);
		~Cat();
		int GetAge() const {return *its_age;}
		int GetWeight() const { return *its_weight;}
		void SetAge(int age);

	private:
		int *its_age;
		int *its_weight;
};

Cat::Cat()
{
	its_age = new int;
	its_weight = new int;

	*its_age = 1;
	*its_weight = 1;
}

Cat::Cat(const Cat & rhs)
{
	cout << "Inside copy constructor\n";
	its_age = new int;
	its_weight = new int;

	*its_age = rhs.GetAge();
	*its_weight = rhs.GetWeight();

	*its_age = 1000;

//	this->SetAge(1000);
}

Cat::~Cat()
{
	cout << "inside destructor\n";
	delete its_age;
	its_age = 0;

	delete its_weight;
	its_weight = 0;
}

void Cat::SetAge(int age)
{
	*its_age = age;
}

void func(Cat sibi)
{
	cout << "inside func\n";
	cout << sibi.GetAge() << "\n";
}

int main()
{
	Cat frisky;

	Cat boot(frisky);

	cout << "frisky age = " << frisky.GetAge() << "\n";
	cout << "boots age = " << boot.GetAge() << "\n";

	frisky.SetAge(100);
	boot.SetAge (200);

	func(frisky);
	func(boot);


	cout << "frisky age = " << frisky.GetAge() << "\n";
	cout << "boots age = " << boot.GetAge() << "\n";
}
