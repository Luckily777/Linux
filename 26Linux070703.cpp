//线程类的封装main.cc

#include <unistd.h>
#include "thread.h"

class test_thread :public Thread {
public:
	test_thread() { cout << "thse_thread()" << endl; }
	~test_thread() { cout << "~test_thread()" << endl; }

private:
	void run() {
		int i;
		for (i = 0; i < 5; i++) {
			cout << "i =" << i << endl;
			::sleep(1);
		}
	}
};

int main(void) {
	Thread* t = new test_thread();
	t->Start();
	t->Join();
}
