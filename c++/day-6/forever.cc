#include <iostream>
#include <stdint.h>

using namespace std;

#define EVER ;;

enum BOOL {FALSE, TRUE};

uint32_t menu();

int main()
{
	uint32_t	choice = 0;
	BOOL		exit = FALSE;

	for (EVER) {
		cout << "inside for";
		choice = menu();
		cout << "choice = " <<choice;

		switch(choice)
		{
			case 1: cout << "hi this is " << "1" << "\n";
				  break;

			case 2: cout << " this is "<< "2" << "\n";
				  break;

			case 3:  exit = TRUE;
				   cout << "exiting";
				   break;
		}

		if (exit) break;
	}
}

uint32_t menu()
{
	uint32_t	choice = 0;

	cout << " MENU :-" << "\n";
	cout <<" for 1 enter 1" << "\n";
	cout << "for 2 enter 2" << "\n";
	cout << "enter 3 for exit" <<"\n";


	cin >> choice;
	return choice;
}


