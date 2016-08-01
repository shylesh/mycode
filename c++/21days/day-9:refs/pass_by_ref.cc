#include <iostream>

using namespace std;

class Cat;
const Cat & func_2 (const Cat &);

class Cat {
	public:
		Cat();
		Cat(Cat &);
		~Cat();
		void SetAge(int age) { its_age = age;}
		int GetAge() const { return its_age;}

	private:
		int its_age;
};

Cat::Cat()
{
	its_age = 1;
	cout << "Inside constructor\n";
}

Cat::Cat(Cat& c_ref)
{
	cout << "inside copy constructor\n";
}

Cat::~Cat()
{
	cout << "Inside destructor\n";
}

const Cat& func_2 (const Cat & p_cat)
{
	int i = 1;
	cout << "cat's age is " << p_cat.GetAge();
	return p_cat;
}

int main()
{
	Cat pussy;

	func_2(pussy);
}

