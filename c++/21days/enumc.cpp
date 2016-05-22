#include <iostream>

using namespace std;
int main()
{
	enum days  {sunday, monday, tuesday, wednesday,thursday,friday,
			saturday};

	days 	day;
	int 	x;

	cout << "enter the day ";
	cin >> x;

	if (days(x) == sunday || days(x) == saturday)
		cout << "weekend";
	else
		cout << "weekday";
}
