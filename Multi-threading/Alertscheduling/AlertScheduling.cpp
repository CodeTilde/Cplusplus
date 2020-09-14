#include <iostream>
#include <thread>
#include <string>
#include<windows.h>
using namespace std;

void task1(int timeToSleep, string taskMessage)
{
	typedef chrono::high_resolution_clock clock_;
	chrono::time_point<clock_> now, currentTime;
	now = clock_::now();
		
	while (1)
	{
		this_thread::sleep_for (std::chrono::seconds(timeToSleep));
		cout<<taskMessage<<"\n";
		PlaySound( TEXT("jnglbell.wav"), NULL, SND_FILENAME );
		currentTime=  clock_::now();
		double elapsed_sec = chrono::duration_cast<chrono::seconds>(currentTime - now).count();
		cout <<"Alert For Task 1 Runs Every "<<elapsed_sec <<" Seconds"<<"\n";
		now =  clock_::now();
	}
	
		 
}
void task2(int timeToSleep, string taskMessage)
{
	typedef chrono::high_resolution_clock clock_;
	chrono::time_point<clock_> now, currentTime;
	now = clock_::now();
	while (1)
	{
		this_thread::sleep_for (std::chrono::seconds(timeToSleep));
		cout<<taskMessage<<"\n";
		PlaySound( TEXT("piano.wav"), NULL, SND_FILENAME );
		currentTime = clock_::now();
		double elapsed_sec = chrono::duration_cast<chrono::seconds>(currentTime - now).count();
		cout <<"Alert For Task 2 Runs Every  "<<elapsed_sec <<" Seconds"<<"\n";
		now = clock_::now();
	}
	
	
		 
}
	

int main()
{
	int time1ToSleep,time2ToSleep; 
	string task1Message, task2Message;
	cout<<"Enter Alert Message for Task 1 \n";
	getline(cin,task1Message);
	cout<<"ENTER Alert Timing in Seconds for Task 1 \n";
	cin>> time1ToSleep;
	cin.clear();
	cin.sync();

	
	//****************************************************************
	
	cout<<"Enter Alert Message for Task 2 \n";
	getline(cin,task2Message);
	cout<<"ENTER Alert Timing in Seconds for Task 2 \n";
	cin>> time2ToSleep;
	
	thread t1 (task1, time1ToSleep, task1Message);
	thread t2 (task2, time2ToSleep, task2Message);
	t1.join();
	t2.join();
	return 0;
}