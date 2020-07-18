//������ģ��

#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <pthread.h> 

#define PRO 1 
#define CON 3 

int ready = 0; // �����Ĳ�Ʒ��� 

pthread_cond_t cond;
pthread_mutex_t mutex;
pthread_t tids[PRO + CON];

void* pro(void* arg) {
	int id = *(int*)arg;
	free(arg);
	while (1) {
		sleep(1);
		pthread_mutex_lock(&mutex);
		printf("%d�������߳̿�ʼ������Ʒ����Ʒ���Ϊ%d\n", id, ready + 1);
		ready++;
		sleep(rand() % 3);
		printf("%d�������߳̽���������Ʒ, ��Ʒ���%d\n", id, ready);
		pthread_cond_signal(&cond); // ֪ͨ�����߽������� 
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
			printf("%d�������̵߳ȴ���Ʒ\n", id);
			pthread_cond_wait(&cond, &mutex);
			printf("%d�������̵߳ȵ���Ʒ������\n", id);
		}
		printf("%d�������߳̿�ʼ���Ѳ�Ʒ,%d\n", id, ready);
		ready--;
		sleep(rand() % 3);
		printf("%d�������߳��������,%d\n", id, ready + 1);
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
