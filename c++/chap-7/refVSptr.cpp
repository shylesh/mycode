#include <iostream>

using namespace std;

void print_truth(int *, int &);

int main()
{
	int 	i = 100;
	int* 	ptr = &i;
	int&	ref = i;

	print_truth(ptr, ref);
	cout <<"address of i = "<<&i;
	cout <<"\n"<<"addrees of actual ptr is "<< &ptr;
}

void print_truth(int* ptr, int& ref)
{
	cout<<"address of ptr = "<<ptr<<"\n";
	cout<<"contents of ptr = "<<*ptr<<"\n";
	cout<<"address of ref = "<<&ref<<"\n";
	cout<<"ref refers to ref = "<<ref<<"\n";
}


