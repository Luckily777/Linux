//线程类的封装pthread.cc


#include <pthread.h>
#include <unistd.h>

#include "thread.h"

void Thread::Start() {
	pthread_create(&thread_id_, NULL, thread_routine, this);
}

void* Thread::thread_routine(void* arg) {
	Thread* thread = static_cast<Thread*>(arg);
	thread->run();
	delete thread;
}

void Thread::Join() {
	::pthread_join(thread_id_, NULL);
}


