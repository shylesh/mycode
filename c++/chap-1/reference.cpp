#include <iostream>

using namespace std;

int main()
{
	int	a = 10;
	int&	a_ref = a;
	int*	a_ptr = &a;
	//int&*	a_ref_ptr = &a_ref; // not allowed// you can't have pointer to a reference//

	cout << "&a = " <<&a<< "&a_ref = " <<&a_ref;
	cout << "contents of a =" <<a << "\n";
	cout << "contents of a_ref = "<<a_ref << "\n";
	cout << "address of a_ptr = " << &a_ptr <<"\n";
	cout << "contents of a_ptr = " << a_ptr <<"\n";
	cout << "data pointed to by a_ptr = " << *a_ptr <<"\n";

	


}
