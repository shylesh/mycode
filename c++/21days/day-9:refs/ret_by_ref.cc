#include <iostream>

using namespace std;

class CAT
{
	public:
		//CAT(int age) { itsAge = age; }
		CAT(CAT &) { cout << "inside copy ctructor\n";}

	//	~CAT(){}
		int GetAge() const { return itsAge;}
	private:
		int itsAge;
};
CAT & MakeCat(int age);
int main()
{
int age = 7;
CAT Boots;
//cout << "Boots is " << Boots.GetAge() << " years old\n";
Boots = MakeCat(age);
cout << "Boots is " << Boots.GetAge() << " years old\n";
}
CAT & MakeCat(int age)
{
CAT * pCat = new CAT();
return *pCat;
}
