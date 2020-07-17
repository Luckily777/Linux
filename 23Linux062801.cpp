//用exit关闭线程后，main关闭，线程还在继续
#include <stdlib.h>
#include <pthread.h>

void* route(void* arg) {
	while (1) {
		printf(".");
		sleep(2);
	}
}

int main(void) {
	pthread_t tid;
	pthread_create(&tid, NULL, route, NULL);
	pthread_detach(tid);

	pthread_exit(NULL);
}
