#include <iostream>
#include <thread>
#include <vector>
#include <cstdlib>
#include <chrono>
#include <condition_variable>

using namespace std;

std::mutex m;
std::condition_variable cv;
//bool is_ready(false);
int ready=0;
int global=0;
void thread_fun(int i);


int main()
{
	vector<thread> t_arr;
	int 	i=0;
	int 	n=0;

	cout <<"enter the number of threads\n";
	cin >> n;

	for (int i=0; i < n; i++)
		t_arr.push_back(std::thread(thread_fun, i));

	{
	std::lock_guard<std::mutex> lk(m);
	ready = 1;
	}
	cv.notify_all();
	cv.notify_all();


	auto remaining = t_arr.begin();

	while (remaining != t_arr.end()) {
		remaining->join();
		remaining++;
	}


}

void thread_fun(int i)
{

	while(1) {
		cout << "inside thread\n";
		std::unique_lock<std::mutex> lk(m);

		cv.wait(lk,[]{return ready == 1;});

		cout << "id =" << i <<"\n";
		global++;
		cout << "global=" << global << "\n";
		lk.unlock();
		ready = 0;
	}

}

