#include <iostream>

using namespace std;

struct st {
	int a;
	char b;
};

int main()
{
	struct st s1 = {1,'a'};
	struct st s2 = {1, 'a'};

	if (s1.b == s2.b)
		cout <<"equal";
	else
		cout <<"not equal";
}
