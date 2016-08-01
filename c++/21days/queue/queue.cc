#include "queue.h"
using namespace std;

/*class myqueue {

	private:
		deque<int>	myq;

	public:
		uint32_t	q_push();
		int32_t		q_pop();
		int		q_display();
};

uint32_t myqueue::q_push()
{
	uint32_t	input;

	cout << "Enter the  element to insert:-";
	cin >> input;
	myq.push_back (input);

	return 0;
}

int32_t myqueue::q_pop()
{
	int32_t ret;
	int32_t& ele = ret;

	if (myq.empty())
		return Q_EMPTY;
	ele = myq.front();
	myq.pop_front();
	return ret;
}

int	myqueue::q_display()
{
	if (myq.empty())
		return Q_EMPTY;

	for (deque<int>::iterator it=myq.begin(); it != myq.end(); it++)
		cout << *it << "\n";
	return 0;
}*/


int main()
{
	myqueue		myq;
	uint32_t	ch;
	uint32_t	ret;
	int32_t		ret_ref;


	while (1) {
		cout << "1. Insert" << "\n" << "2.Delete" << "\n"<<"3.display";
		cout << "\n" << "4. Exit" << "\n";
		cout << "Enter your choice:-";
		cin >> ch;

		switch(ch) {
		case 1:		ret = myq.q_push();
				if (ret) {
					cout << "Push failed\n";
					exit(1);
				}
				break;

		case 2:		ret = myq.q_pop();
				if (ret == Q_EMPTY)
					cout << "Pop failed- No ele \n";
				cout << ret;
				break;

		case 3:		ret = myq.q_display();
				if (ret == Q_EMPTY)
					cout <<"Display failed- No ele\n";
				break;

		case 4:		exit(0);
		}
	}
}

