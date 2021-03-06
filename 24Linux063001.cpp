//消费者模型

#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <pthread.h> 

#define PRO 1 
#define CON 3 

int ready = 0; // 生产的产品编号 

pthread_cond_t cond;
pthread_mutex_t mutex;
pthread_t tids[PRO + CON];

void* pro(void* arg) {
	int id = *(int*)arg;
	free(arg);
	while (1) {
		sleep(1);
		pthread_mutex_lock(&mutex);
		printf("%d生产者线程开始生产产品，产品编号为%d\n", id, ready + 1);
		ready++;
		sleep(rand() % 3);
		printf("%d生产者线程结束生产产品, 产品编号%d\n", id, ready);
		pthread_cond_signal(&cond); // 通知消费者进行消费 
		pthread_mutex_unlock(&mutex);
		sleep(rand() % 3);
	}
}
void* con(void* arg) {
	int id = *(int*)arg;
	free(arg);

	while (1) {
		pthread_mutex_lock(&mutex);
		while (ready <= 0) {
			printf("%d消费者线程等待产品\n", id);
			pthread_cond_wait(&cond, &mutex);
			printf("%d消费者线程等到产品，返回\n", id);
		}
		printf("%d消费者线程开始消费产品,%d\n", id, ready);
		ready--;
		sleep(rand() % 3);
		printf("%d消费者线程消费完毕,%d\n", id, ready + 1);
		pthread_mutex_unlock(&mutex);
		sleep(rand() % 2);
	}
}
int main(void) {
	int i;

	srand(getpid());
	pthread_cond_init(&cond, NULL);
	pthread_mutex_init(&mutex, NULL);
	for (i = 0; i < PRO; i++) {
		int* p = malloc(sizeof(int));
		*p = i;
		pthread_create(&tids[i], NULL, pro, (void*)p);
	}
	for (i = 0; i < CON; i++) {
		int* p = malloc(sizeof(int));
		*p = i;
		pthread_create(&tids[PRO + i], NULL, con, (void*)p);
	}

	for (i = 0; i < PRO + CON; i++) {
		pthread_join(tids[i], NULL);
	}

	pthread_mutex_destroy(&mutex);
	pthread_cond_destroy(&cond);
}
