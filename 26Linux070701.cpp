//线程类的封装pthread.h

#ifndef __THREAD_H__
#define __THREAD_H__

#include <iostream>
using namespace std;

#include <pthread.h>

class Thread {
public:
	Thread() { cout << "Thread()" << endl; }
	virtual ~Thread() { cout << "~Thread()" << endl; }
	void Start();
	void Join();

private:
	static void* thread_routine(void* arg);
	virtual void run() = 0;
	pthread_t thread_id_;
};

#endif
