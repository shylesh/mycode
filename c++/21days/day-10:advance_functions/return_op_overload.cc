#include <iostream>
#include <stdint.h>

using namespace std;

class Counter {
	public:
		Counter() {cur_val = 1;}
		Counter(int val);
		~Counter() { ;}
		Counter operator++ ();
		int GetVal() const { return cur_val;}

	private:
		int cur_val;
};

Counter::Counter(int val):
			cur_val(val)
{

}

Counter Counter::operator++ ()
{
	cur_val++;
	return (Counter(cur_val));
}

int main()
{
	Counter i;
	Counter j = ++i;

	cout <<i.GetVal();
	cout <<j.GetVal();
}


