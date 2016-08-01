#include <iostream>

using namespace std;

class Counter {
	public:
		Counter() {its_val = 1;}
		~Counter() {};
		void operator++ () {its_val++;}
		friend ostream & operator<< (ostream & out, Counter i) {out<<i.its_val; return out;}

	private:
		int its_val;
};


int main()
{
	Counter i;

	++i;
	cout << i;
	++i;
	cout << i;
}

