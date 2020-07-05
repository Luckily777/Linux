//��ѧ�ҾͲͶ��߳�����������

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
	//���ҿ���ͬʱ����ſ���
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
		printf("%d��ѧ�ң���ʼ˼��\n", no);
		sleep(rand() % 5);
		printf("%d��ѧ�Ҷ��ˣ�׼���Է�\n", no);
		get2fork(no);
		printf("%d��ѧ�ҿ�ʼ�Ͳ�\n", no);
		//sleep(rand()%3);
		printf("%d��ѧ�ҾͲͽ���\n", no);
		put2fork(no);
	}

}


int main(void) {
	//�����ź�����
	id = semget(1234, 5, IPC_CREAT | 0666);
	int i;

	//�����ź������ĳ�ֵΪ1
	union semun su;
	su.val = 1;
	for (i = 0; i < 5; i++) {
		semctl(id, i, SETVAL, su);
	}

	//�ܹ�5������
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
