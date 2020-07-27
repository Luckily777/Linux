//lockµÄ·â×°

#ifndef __MUTEX_H__
#define __MUTEX_H__
#include <pthread.h>
#include <iostream>
using namespace std;

class mutex {
public:
	mutex() { pthread_mutex_init(&mutex_, NULL); }
	~mutex() { pthread_mutex_destroy(&mutex_); }
	inline void lock() { pthread_mutex_lock(&mutex_); }
	inline void unlock() { pthread_mutex_unlock(&mutex_); }
private:
	pthread_mutex_t mutex_;
};

class mutex_safe {
	mutex_safe{ cout << "m.lock" << endl; m.lock(); }
	~mutex_safe{ cout << "m.unlock" << endl; m.unlock(); }
private:
	mutex m;
};

#endif



#include "mutex.h"

int main() {
	cout << "aaaaaaaaaaaaaa" << endl;

	{
		cout << "------------" << endl;
		mutex_safe ms;
		cout << "+++++++++++" << endl;
	}
	cout << "bbbbbbbbbbbbbbbb" << endl;
}
