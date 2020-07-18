//线程池 （银行业务办理）

#ifndef __THREADPOOL_H__ 
#define __THREADPOOL_H__ 

#include <pthread.h> 

// 任务节点 
typedef struct task {
	void* (*run)(void* arg); // 任务的回调函数 
	void* arg; // 回调函数的参数 
	struct task* next;
}task_t;

// 线程池结构体 
typedef struct threadpool {
	pthread_cond_t cond;
	pthread_mutex_t mutex;
	task_t* first; // 任务队列队头 
	task_t* last; // 任务队列队尾指针 
	int counter; // 线程池中当前有多少个线程 
	int idle; // 空闲线程个数 
	int max_thread; // 线程池中线程的阈值 
	int quit; // 线程池销毁标志，默认是0 
}threadpool_t;

// 初始化线程池 
void threadpool_init(threadpool_t* pool, int max_thread);

// 往线程池中添加任务 
void threadpool_add_task(threadpool_t* pool, void* (*run)(void*), void* arg);

// 销毁线程池 
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
		pool->idle++; // 刚开始，是一个空闲线程 
		while (pool->first == NULL && pool->quit == 0) {
			pthread_cond_wait(&pool->cond, &pool->mutex);
		}
		pool->idle--; // 得到任务，就不是一个空闲线程 

		if (pool->first != NULL) { // 有任务，执行任务回调函数 
			task_t* tmp = pool->first; // 取出任务队列队头节点 
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
	task_t* new_task = malloc(sizeof(task_t)); // 创建新的任务节点 
	new_task->run = run;
	new_task->arg = arg;

	// 往任务队列中添加任务 
	pthread_mutex_lock(&pool->mutex);
	if (pool->first == NULL) {
		pool->first = new_task;
	}
	else {
		pool->last->next = new_task;
	}
	pool->last = new_task;

	// 如果有空闲线程，直接唤醒空闲线程，执行当前任务 
	if (pool->idle > 0) {
		pthread_cond_signal(&pool->cond);
	}
	else if (pool->counter < pool->max_thread) {
		// 如果没有空闲线程可以用来执行当前任务，并且没有达到上限，创建新线程 
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
	printf("id=%d thread_id=%p 开始工作\n", id, pthread_self());
	sleep(5);
	printf("id=%d thread_id=%p 退出\n", id, pthread_self());
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

