//�̳߳� ������ҵ�����

#ifndef __THREADPOOL_H__ 
#define __THREADPOOL_H__ 

#include <pthread.h> 

// ����ڵ� 
typedef struct task {
	void* (*run)(void* arg); // ����Ļص����� 
	void* arg; // �ص������Ĳ��� 
	struct task* next;
}task_t;

// �̳߳ؽṹ�� 
typedef struct threadpool {
	pthread_cond_t cond;
	pthread_mutex_t mutex;
	task_t* first; // ������ж�ͷ 
	task_t* last; // ������ж�βָ�� 
	int counter; // �̳߳��е�ǰ�ж��ٸ��߳� 
	int idle; // �����̸߳��� 
	int max_thread; // �̳߳����̵߳���ֵ 
	int quit; // �̳߳����ٱ�־��Ĭ����0 
}threadpool_t;

// ��ʼ���̳߳� 
void threadpool_init(threadpool_t* pool, int max_thread);

// ���̳߳���������� 
void threadpool_add_task(threadpool_t* pool, void* (*run)(void*), void* arg);

// �����̳߳� 
void threadpool_destroy(threadpool_t* pool);
#endif //__THREADPOOL_H__ 



#include <stdio.h> 
#include <stdlib.h> 
#include "threadpool.h" 

void threadpool_init(threadpool_t* pool, int max_thread) {
	pthread_cond_init(&pool->cond, NULL);
	pthread_mutex_init(&pool->mutex, NULL);
	pool->first = NULL;
	pool->last = NULL;
	pool->counter = 0;
	pool->idle = 0;
	pool->max_thread = max_thread;
	pool->quit = 0;
}
void* routine(void* arg) {
	threadpool_t* pool = (threadpool_t*)arg;

	while (1) {
		pthread_mutex_lock(&pool->mutex);
		pool->idle++; // �տ�ʼ����һ�������߳� 
		while (pool->first == NULL && pool->quit == 0) {
			pthread_cond_wait(&pool->cond, &pool->mutex);
		}
		pool->idle--; // �õ����񣬾Ͳ���һ�������߳� 

		if (pool->first != NULL) { // ������ִ������ص����� 
			task_t* tmp = pool->first; // ȡ��������ж�ͷ�ڵ� 
			pool->first = tmp->next;
			pthread_mutex_unlock(&pool->mutex);
			tmp->run(tmp->arg);
			free(tmp);
			pthread_mutex_lock(&pool->mutex);
		}

		pthread_mutex_unlock(&pool->mutex);
	}
}

void threadpool_add_task(threadpool_t* pool, void* (*run)(void*), void* arg) {
	task_t* new_task = malloc(sizeof(task_t)); // �����µ�����ڵ� 
	new_task->run = run;
	new_task->arg = arg;

	// ������������������ 
	pthread_mutex_lock(&pool->mutex);
	if (pool->first == NULL) {
		pool->first = new_task;
	}
	else {
		pool->last->next = new_task;
	}
	pool->last = new_task;

	// ����п����̣߳�ֱ�ӻ��ѿ����̣߳�ִ�е�ǰ���� 
	if (pool->idle > 0) {
		pthread_cond_signal(&pool->cond);
	}
	else if (pool->counter < pool->max_thread) {
		// ���û�п����߳̿�������ִ�е�ǰ���񣬲���û�дﵽ���ޣ��������߳� 
		pthread_t tid;
		pthread_create(&tid, NULL, routine, pool);
		pool->counter++;
	}
	pthread_mutex_unlock(&pool->mutex);
}

void threadpool_destroy(threadpool_t* pool) {
}


#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include "threadpool.h" 

void* myfun(void* arg) {
	int id = *(int*)arg;
	free(arg);
	printf("id=%d thread_id=%p ��ʼ����\n", id, pthread_self());
	sleep(5);
	printf("id=%d thread_id=%p �˳�\n", id, pthread_self());
}

int main(void) {
	int i;
	threadpool_t pool;

	threadpool_init(&pool, 3);
	for (i = 0; i < 5; i++) {
		int* p = malloc(sizeof(int));
		*p = i;
		threadpool_add_task(&pool, myfun, p);
	}

	sleep(20);
	threadpool_destroy(&pool);
}

