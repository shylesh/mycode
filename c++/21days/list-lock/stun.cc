#include <iostream>

using namespace std;
struct Op
{
	string op;
	string path;
	union myint {
		int a;
		char b;
		float c;
	}allints;
};

int main()
{
	Op myops;

	myops.op = "read";
	myops.path = "/dev/read";
	myops.allints.a = 1;

	cout << myops.op << myops.path << myops.allints.a;
}

