#include <iostream>
#include <chrono>
#include <thread>
#include<ctime>
using namespace std;
int main()
{

	typedef chrono::high_resolution_clock clock_;
	chrono::time_point<clock_> now, currentTime;
	now = clock_::now();
	time_t timeNow = clock_::to_time_t(now);
	cout << "Current Time and Date is: "<<ctime(& timeNow)<< "\n";
	this_thread::sleep_for (std::chrono::seconds(65));
	currentTime = clock_::now();
	double elapsed_sec = chrono::duration_cast<chrono::seconds>(currentTime - now).count();
	double elapsed_min = chrono::duration_cast<chrono::minutes>(currentTime - now).count();
	cout << "... has slept for "<< elapsed_sec <<" Seconds \n";
	cout << "... has slept for "<< elapsed_min <<" Minutes \n";
	this_thread::sleep_for (std::chrono::seconds(5));
	return 0;
}
