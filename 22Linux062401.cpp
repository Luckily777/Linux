//哲学家就餐多线程问题程序代码

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/sem.h>

union semun {
	int val;
};

int id;

void P(int no) {
	struct sembuf sb[1];
	sb[0].sem_num = no;
	sb[0].sem_op = -1;
	sb[0].sem_flg = 0;
	semop(id, sb, 1);
}

void V(int no) {
	struct sembuf sb[1];
	sb[0].sem_num = no;
	sb[0].sem_op = 1;
	sb[0].sem_flg = 0;
	semop(id, sb, 1);
}

void get2fork(int no) {
	int left = no;
	int right = (no + 1) % 5;
	//P(left);
	//P(right);
	//左右筷子同时拿起才可以
	struct sembuf sb[2];
	sb[0].sem_num = left;
	sb[0].sem_op = -1;
	sb[0].sem_flg = 0;
	sb[1].sem_num = right;
	sb[1].sem_op = -1;
	sb[1].sem_flg = 0;
	semop(id, sb, 2);

}

void put2fork(int no) {
	int left = no;
	int right = (no + 1) % 5;
	V(left);
	V(right);
}


void zhexuejia(int no) {
	for (;;) {
		printf("%d哲学家，开始思考\n", no);
		sleep(rand() % 5);
		printf("%d哲学家饿了，准备吃饭\n", no);
		get2fork(no);
		printf("%d哲学家开始就餐\n", no);
		//sleep(rand()%3);
		printf("%d哲学家就餐结束\n", no);
		put2fork(no);
	}

}


int main(void) {
	//创建信号量集
	id = semget(1234, 5, IPC_CREAT | 0666);
	int i;

	//设置信号量集的初值为1
	union semun su;
	su.val = 1;
	for (i = 0; i < 5; i++) {
		semctl(id, i, SETVAL, su);
	}

	//总共5个进程
	int no = 0;
	for (i = 1; i < 5; i++) {
		pid_t pid = fork();
		if (pid == 0) {
			no = i;
			break;
		}
	}
	srand(getpid());
	zhexuejia(no);
}
