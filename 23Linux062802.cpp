//ÂôÆ±

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

int g_ticket = 100;
pthread_mutex_t mutex;

void* route(void* arg) {
	char* thread = (char*)arg;
	while (1) {
		pthread_mutex_lock(&mutex);
		if (g_ticket > 0) {
			printf("%sÂô%d\n", thread, g_ticket);
			g_ticket--;
		}
		else {
			pthread_mutex_unlock(&mutex);
			break;
		}
		pthread_mutex_unlock(&mutex);
		usleep(10000);
	}
}

int main(void) {
	pthread_t t1, t2, t3, t4;
	pthread_mutex_init(&mutex, NULL);
	pthread_create(&t1, NULL, route, "thread1");
	pthread_create(&t2, NULL, route, "thread2");
	pthread_create(&t2, NULL, route, "thread3");
	pthread_create(&t2, NULL, route, "thread4");

	pthread_join(t1, NULL);
	pthread_join(t2, NULL);
	pthread_join(t3, NULL);
	pthread_join(t4, NULL);
}
