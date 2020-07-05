//互斥量 线程的同步与互斥

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

//线程的同步与互斥 


int a;
int b;
pthread_mutex_t mutex;

void* r1(void* arg) {
	while (1) {
		pthread_mutex_lock(&mutex);
		a++;
		b++;

		if (a != b) {
			printf("%d!=%d\n", a, b);
			a = 0;
			b = 0;
		}
		pthread_mutex_unlock(&mutex);
	}
}

void* r2(void) {
	while (1) {
		pthread_mutex_lock(&mutex);
		a++;
		b++;

		if (a != b) {
			printf("%d!=%d\n", a, b);
			a = 0;
			b = 0;
		}
		pthread_mutex_unlock(&mutex);
	}
}

int main(void) {
	pthread_t t1, t2;

	pthread_mutex_init(&mutex, NULL);
	pthread_create(&t1, NULL, r1, NULL);
	pthread_create(&t2, NULL, r2, NULL);

	pthread_join(t1, NULL);
	pthread_join(t2, NULL);
}


