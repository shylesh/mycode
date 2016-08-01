#include <iostream>
#include <stdint.h>

using namespace std;

class Counter {
	public:
		Counter() {}
		Counter(int init) {cur_val = init;}
		~Counter() {}
		int GetVal() const {return cur_val;}
		Counter operator+ (Counter & rhs);
	private:
		int cur_val;
};

Counter Counter::operator+ (Counter & rhs)
{
	return Counter(cur_val + rhs.GetVal());
}

int main()
{
	Counter a, b(1), c(2), d(3);

	a = b+c+d;

	cout << a.GetVal();
}
