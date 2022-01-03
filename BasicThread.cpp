// To Compile use command - g++ BasicThread.cpp -pthread

#include <iostream>
#include <thread>

using namespace std;

void workerQueue1(int i)
{
	cout<<"workerQueue1 Executed"<<i<<endl;
}

void workerQueue2(int x)
{
	cout<<"workerQueue2 Executed"<<x<<endl;
}

int  main()
{
	cout<<"Main Starts"<<endl;
	
	thread T1(workerQueue1, 1);

this_thread::sleep_for(2000ms);

	thread T2(workerQueue2, 2);

	T1.join();
	T2.join();
	
	cout<<"Main Ends"<<endl;
}

	
