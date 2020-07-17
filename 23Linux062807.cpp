//¶ÁÐ´Ëø

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

pthread_rwlock_t lock;

int g_data = 1;

void* read_routine(void* arg) {
	while (1) {
		pthread_rwlock_rdlock(&lock);
		printf("threadid = % x,g_data =%d\n", pthread_self(), g_data);
		pthread_rwlock_unlock(&lock);
		sleep(1);
	}
}

void* write_routine(void* r4arg) {
	while (1) {
		pthread_rwlock_wrlock(&lock);
		g_data++;
		pthread_rwlock_unlock(&lock);
	}
}

int main(void) {
	pthread_rwlock_init(&lock, NULL);

	pthread_t r1, r2, w1;
	pthread_create(&r1, NULL, read_routine, NULL);
	pthread_create(&r2, NULL, read_routine, NULL);
	pthread_create(&w1, NULL, write_routine, NULL);

	pthread_join(r1, NULL);
	pthread_join(r2, NULL);
	pthread_join(w1, NULL);
	pthread_rwlock_destroy(&lock);
}
