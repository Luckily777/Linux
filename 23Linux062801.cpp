//��exit�ر��̺߳�main�رգ��̻߳��ڼ���
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
