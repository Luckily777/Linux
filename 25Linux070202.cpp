#ifndef __THREADPOOL_H__
#define __THREADPOOL_H__

#include <pthread.h>

// ����ڵ�
typedef struct task {
	void* (*run)(void* arg); // ����Ļص�����
	void* arg;  // �ص������Ĳ���
	struct task* next;
}task_t;

// �̳߳ؽṹ��
typedef struct threadpool {
	pthread_cond_t cond;
	pthread_mutex_t mutex;
	task_t* first;  // ������ж�ͷ
	task_t* last;   // ������ж�βָ��
	int counter;    // �̳߳��е�ǰ�ж��ٸ��߳�
	int idle;       // �����̸߳���
	int max_thread; // �̳߳����̵߳�����
	int quit;       // �̳߳����ٱ�־��Ĭ����0
}threadpool_t;

// ��ʼ���̳߳�
void threadpool_init(threadpool_t* pool, int max_thread);

// ���̳߳����������
void threadpool_add_task(threadpool_t* pool, void* (*run)(void*), void* arg);

// �����̳߳�
void threadpool_destroy(threadpool_t* pool);

#endif //__THREADPOOL_H__

