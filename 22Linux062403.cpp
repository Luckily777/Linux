//线程

//1.创建线程
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/syscall.h>


void* route(void* arg) {
	printf("my first thread %X       %d\n", pthread_self(), syscall(SYS_gettid));
}

int main(void) {
	pthread_t tid;

	pthread_create(&tid, NULL, route, NULL);
	printf("main return %X        %d\n", pthread_self(), syscall(SYS_gettid));
	pthread_join(tid, NULL);
}



//2. 线程结束和进程结束 及线程分离
//线程结束和进程结束
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void* r1(void* rag) {
	int i;
	for (i = 0;; i++) {
		printf("线程1\n");
		sleep(1);
		/*	if(i==3){
				//exit(0);
				pthread_exit(NULL);
			}*/
	}
}


void* r2(void* rag) {
	int i;
	pthread_t t1 = *(pthread_t*)rag;
	for (i = 0;; i++) {
		printf("线程2\n");
		sleep(1);
		if (i == 5) {
			pthread_cancel(t1);
		}
	}
}


int main() {
	pthread_t t1;
	pthread_t t2;

	pthread_create(&t1, NULL, r1, NULL);
	pthread_detach(t1);//线程分离
	pthread_create(&t2, NULL, r2, (void*)&t1);
	pthread_detach(t2);//线程分离

/*	int ret=pthread_join(t1,NULL);
	if(ret!=0){
		printf("pthread_join:%s\n",strerror(ret));
	}
	pthread_join(t2,NULL);
*/

	for (;;) {
		pause();
	}
}
