//À¿À¯

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

pthread_mutex_t mutex_a;
pthread_mutex_t mutex_b;

void* r1(void* arg) {
	pthread_mutex_lock(&mutex_a);
	sleep(1);
	pthread_mutex_lock(&mutex_b);

	printf("haha  thread 1\n");


	pthread_mutex_unlock(&mutex_b);
	pthread_mutex_unlock(&mutex_a);
}


void* r2(void* arg) {
	pthread_mutex_lock(&mutex_b);
	sleep(1);
	pthread_mutex_lock(&mutex_a);
	printf("haha  thread 2\n");
	pthread_mutex_unlock(&mutex_a);
	pthread_mutex_unlock(&mutex_b);
}

int main(void) {
	pthread_mutex_init(&mutex_a, NULL);
	pthread_mutex_init(&mutex_b, NULL);

	pthread_t t1, t2;

	pthread_create(&t1, NULL, r1, NULL);
	pthread_create(&t2, NULL, r2, NULL);

	pthread_join(t1, NULL);
	pthread_join(t2, NULL);

	pthread_mutex_destroy(&mutex_a);
	pthread_mutex_destroy(&mutex_b);

}
