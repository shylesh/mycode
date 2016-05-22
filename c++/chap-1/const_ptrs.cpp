#include <iostream>

using namespace std;


int main()
{

	const char *ptr		= "hello";
	char * const ptr1	= "hi";
	char *	ptr2;

	cout << "modifying const char *" ;
	ptr = "MODIFY";
	ptr = ptr2;

	cout <<"modifying const ptr";
	ptr1 = "HELLO";
	ptr1 = ptr2;


}
