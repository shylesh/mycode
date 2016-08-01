#include <iostream>
#include <stdint.h>
#include <list>
#include "list.h"

using namespace std;

int main()
{
	mylist s_list;
	int	ch;
	struct info *ii;

	while (1) {
	cout << " 1. insert " << "\n";
	cout << "2. pop " << "\n";
	cout << "3. display" << "\n";
	cout << "4. exit" << "\n";

	cin >> ch;

	switch(ch)
	{
	case 1: cout << "enter ele to insert\n";
		ii =  new struct info;
		cin >> ii->i >> ii->j;
		s_list.insert_list(ii);
		break;

	case 2: s_list.rem_list();
		break;

	case 3: s_list.walk();
		break;

	case 4: exit(1);
	}
	}
}
