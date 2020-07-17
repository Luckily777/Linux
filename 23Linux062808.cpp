//同步，条件
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

pthread_cond_t cond;
pthread_mutex_t mutex;

void* r1(void* arg) {
	while (1) {
		pthread_cond_wait(&cond, &mutex);
		printf("嗨起来\n");
	}
}

void* r2(void* arg) {
	while (1) {
		sleep(1);
		pthread_cond_signal(&cond);
	}
}

int main(void) {
	pthread_t t1, t2;
	pthread_cond_init(&cond, NULL);
	pthread_mutex_init(&mutex, NULL);

	pthread_create(&t1, NULL, r1, NULL);
	pthread_create(&t2, NULL, r2, NULL);

	pthread_join(t1, NULL);
	pthread_join(t2, NULL);

	pthread_cond_destroy(&cond);
	pthread_mutex_destroy(&mutex);
}
