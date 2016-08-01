#include <iostream>
#include <stdint.h>

using namespace std;

class Counter {
	public:
		Counter() {cur_val = 1;}
		Counter(int val);
		~Counter() { ;}
		const Counter & operator++ ();
		Counter operator++(int dummy);
		int GetVal() const { return cur_val;}

	private:
		int cur_val;
};

Counter::Counter(int val):
			cur_val(val)
{

}

const Counter &  Counter::operator++ ()
{
	cur_val++;
	return *this;
}

Counter Counter::operator++ (int dummy)
{
	Counter postobj = *this;
	cur_val++;
	return postobj;
}

int main()
{
	Counter i;
	Counter j = ++i;
	Counter k = i++;

	cout <<i.GetVal();
	cout <<j.GetVal();
	cout <<k.GetVal();
}


