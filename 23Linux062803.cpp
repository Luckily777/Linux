//�ۼ�400000

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

int g_ticket = 0;
pthread_mutex_t mutex;

void* route(void* arg) {
	int i;

	for (i = 0; i < 100000; i++) {
		pthread_mutex_lock(&mutex);
		g_ticket++;
		pthread_mutex_unlock(&mutex);
	}
}

int main(void) {
	pthread_t t1, t2, t3, t4;

	pthread_mutex_init(&mutex, NULL);
	pthread_create(&t1, NULL, route, "thread1");
	pthread_create(&t2, NULL, route, "thread2");
	pthread_create(&t3, NULL, route, "thread3");
	pthread_create(&t4, NULL, route, "thread4");

	pthread_join(t1, NULL);
	pthread_join(t2, NULL);
	pthread_join(t3, NULL);
	pthread_join(t4, NULL);
	printf("ticker=%d\n", g_ticket);
	pthread_mutex_destroy(&mutex);
}
