// Concurrency1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <thread>
#include <vector>
#include <mutex>
#include <condition_variable>

using namespace std;

int getal = 0;

vector<thread> threadlist;
mutex threadlocker;
condition_variable condition;
bool ready = false;


void print(int printnummer) {
	unique_lock<mutex> locker(threadlocker);
	cout << "Het te printen nummer is: " << printnummer << endl;
	condition.wait(locker, [] {return ready; });

	condition.notify_all();
}

void threadtest(int nummer) {
	
	getal = nummer;
	//cout << "Processing" << nummer << endl;
	print(getal);
}



int main()
{
	for (unsigned i = 0; i < 10; i++) {
		thread test(threadtest, i);
		threadlist.push_back(move(test));
	}

	for (thread & thread : threadlist) {
		thread.join();
	}

}




