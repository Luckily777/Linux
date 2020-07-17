//任意时刻删掉进程

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

pthread_mutex_t mutex;

void fun(void* arg) {
	printf("aaaaaa\n");
	sleep(1);
	pthread_mutex_unlock(&mutex);
}

void* odd(void* arg) {
	int i;
	for (i = 1;; i += 2) {
		pthread_cleanup_push(fun, NULL);
		pthread_mutex_lock(&mutex);
		printf("add:%d\n", i);
		pthread_mutex_unlock(&mutex);
		pthread_cleanup_pop(0);
	}
}

void* even(void* arg) {
	int i;
	for (i = 0;; i += 2) {
		pthread_mutex_lock(&mutex);
		printf("even=======:%d\n", i);
		pthread_mutex_unlock(&mutex);
	}
}

int main(void) {
	pthread_mutex_init(&mutex, NULL);

	pthread_t t1, t2;
	pthread_create(&t1, NULL, odd, NULL);
	pthread_create(&t2, NULL, even, NULL);

	sleep(3);
	pthread_cancel(t1);
	pthread_join(t1, NULL);
	pthread_join(t2, NULL);
	pthread_mutex_destroy(&mutex);
}
