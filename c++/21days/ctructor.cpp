#include <iostream>

using namespace std;

class cat
{
	public:
		cat(int intial_age); //constructor//
		~cat();		     //destructor//
		int getage() const;
		void setage(int age) ;
		void meow();

	private:
		int cat_age;
};

/* define constructor */
cat::cat (int init_age)
{
	cat_age = init_age;
}


cat::~cat()
{
}

void cat::meow()
{
	cout << "meow" << "\n";
}

int cat::getage() const
{
	return cat_age;
}

void cat::setage(int age)
{
	cat_age = age;

}

int main()
{
	cat pussy(5);

	pussy.meow();
	cout <<"current age is : " << pussy.getage() <<"\n";
	pussy.setage(6);
	cout<<"new age is :" << pussy.getage() << "\n";
}
