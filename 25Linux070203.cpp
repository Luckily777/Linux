#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <errno.h>
#include "threadpool.h"

//�̳߳صĳ�ʼ��
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

//���ú���
void* routine(void* arg) {
	threadpool_t* pool = (threadpool_t*)arg;
	int timeout = 0;
	printf("%p thread created\n", pthread_self());
	while (1) {
		timeout = 0;
		pthread_mutex_lock(&pool->mutex);
		pool->idle++; //  �տ�ʼ����һ�������߳�
		while (pool->first == NULL && pool->quit == 0) {
			struct timespec  abstime;
			clock_gettime(CLOCK_REALTIME, &abstime);
			abstime.tv_sec += 5;
			int ret = pthread_cond_timedwait(&pool->cond, &pool->mutex, &abstime);
			if (ret == ETIMEDOUT) {
				timeout = 1;
				printf("%p thread timeout\n", pthread_self());
				break;
			}
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

		if (pool->first == NULL && timeout == 1) {
			pool->counter--;
			pthread_mutex_unlock(&pool->mutex);
			break;
		}

		if (pool->first == NULL && pool->quit == 1) {
			pool->counter--;
			if (pool->counter == 0) { //  ���һ���˳����̣߳�֪ͨthreadpool_destroy�е�pthread_cond_wait
				pthread_cond_signal(&pool->cond);
			}
			pthread_mutex_unlock(&pool->mutex);
			break;
		}

		pthread_mutex_unlock(&pool->mutex);
	}

	printf("%p thread exit\n", pthread_self());
}

//�߳����Ӻ���
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

//�߳����ٺ���
void threadpool_destroy(threadpool_t* pool) {
	if (pool->quit == 1)
		return;

	pthread_mutex_lock(&pool->mutex);
	pool->quit = 1;
	printf("��Ҫɱ���̳߳�\n");
	if (pool->counter > 0) {
		//  ���̳߳��п����̸߳�������0ʱ��
		//  pthread_cond_broadcast��������������pthread_cond_timedwait�ϵ��߳�
		if (pool->idle > 0)
			pthread_cond_broadcast(&pool->cond);
		// ��������̳߳�ʱ���̳߳��е��߳�����ִ������
		// �����յ�broadcast��֪ͨ
		while (pool->counter > 0)
			pthread_cond_wait(&pool->cond, &pool->mutex);
	}
	pthread_mutex_unlock(&pool->mutex);

	pthread_cond_destroy(&pool->cond);
	pthread_mutex_destroy(&pool->mutex);
}