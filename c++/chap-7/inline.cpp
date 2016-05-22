#include <iostream>

using namespace std;

inline void hello_world_inline();

int main()
{
	hello_world_inline();
	return 1;
}

inline void hello_world_inline()
{
	cout << "Helllo world";
}
