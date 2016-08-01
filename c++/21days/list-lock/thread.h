#include <iostream>
#include <thread>
#include <cstdlib>
#include <chrono>
#include <condition_variable>

using namespace std;

class mythread {
	private:
		std::mutex m;
		vector<thread> t_arr;

	public:
		std::condition_variable cv;

		mythread(std::list<struct info *>& list_ref, int n);
		~mythread();
		std::unique_lock<std::mutex> get_lock();
		int release_lock();
		//workers need the list to be acted upon
		void workers(std::list<struct info *>& list_ref);
};

/* spawn the threads with the list ref as arfs */
void mythread::mythread(std::list<struct info *>& list_ref,int n)
{
	for (int i=0; i < n; i++)
		t_arr.push_back(std::thread(workers,
				std::list<struct info *>& list_ref));

}

void mythread::~mythread()
{
}

std::unique_lock<std::mutex> mythread::get_lock()
{
	std::unique_lock<std::mutex> lk(m);
	return lk;
}

int mythread::release_lock(std::unique_lock<std::mutex>)
{
	lk.unlock();
	return ;
}

void workers(std::list<struct info *>& list_ref)
{
	struct info *st_ptr=NULL;

	while(1) {
		cout << "inside thread\n";
		std::unique_lock<std::mutex> lk(get_lock());

		cv.wait(lk, []{return ready==1;});
		st_ptr = list_ref.rem_list();
		lk.unlock();
		/* do something with st_ptr */

	}
}

// TODO: accessing the element through reference of the list ; pointer to member function //

