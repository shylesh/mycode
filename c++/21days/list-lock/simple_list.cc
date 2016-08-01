#include <iostream>
#include <list>

using namespace std;

struct info {
	int i;
	char c;
};

int main()
{
	struct info a;
	struct info b;
	list <struct info> mylist;


	a.i = 1;
	a.c = 'a';
	b.i = 2;
	b.c = 'b';

	mylist.push_back(a);
	mylist.push_back(b);



}
