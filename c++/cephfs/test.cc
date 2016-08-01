#include <iostream>
#include <condition_variable>
#include <thread>
#include <chrono>
#include <vector>
#include <cstdlib>

using namespace std;

std::condition_variable cv;
std::mutex cv_m; // This mutex is used for three purposes:
                 // 1) to synchronize accesses to i
                 // 2) to synchronize accesses to std::cerr
                 // 3) for the condition variable cv
int i = 0;

void waits()
{
    std::unique_lock<std::mutex> lk(cv_m);
    std::cerr << "Waiting... \n";
    cv.wait(lk, []{return i == 1;});
    std::cerr << "...finished waiting. i == 1\n";
}

void signals()
{


        std::lock_guard<std::mutex> lk(cv_m);
        i = 1;
        std::cerr << "Notifying again...\n";
    	cv.notify_all();
}

int main()
{
    vector<thread> t_arr;
    int i=0;
    int n;

    std::cout << "enter number\n";
    std::cin >> n;
    for (i = 0; i < n; i++)
	t_arr.push_back(std::thread(waits));
    //std::thread t1(waits), t2(waits), t3(waits);
    std::thread t4(signals);
    t_arr[0].join();
    t_arr[1].join();
    t_arr[2].join();
    t4.join();
}
