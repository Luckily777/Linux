//�ź���������������ģ��

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/shm.h>


//���������ڴ�
int create_shm(key_t key, size_t size) {
	return shmget(key, size, IPC_CREAT | 0644);
}


//�����ź���
int create_sem(key_t key) {
	return semget(key, 1, IPC_CREAT | 0644);
}

//�����ź���
union semun { int val; };

void sem_setval(int id, int val) {
	union semun su;
	su.val = val;
	semctl(id, 0, SETVAL, su);
}

//PV����
void P(int id) {
	struct sembuf sb[1];
	sb[0].sem_num = 0;
	sb[0].sem_op = -1;
	sb[0].sem_flg = 0;
	semop(id, sb, 1);
}

void V(int id) {
	struct sembuf sb[1];
	sb[0].sem_num = 0;
	sb[0].sem_op = 1;
	sb[0].sem_flg = 0;
	semop(id, sb, 1);
}

int main(void) {
	int shmid = create_shm(1234, sizeof(int));
	int sem_write = create_sem(1234);
	int sem_read = create_sem(1235);
	sem_setval(sem_write, 1);
	sem_setval(sem_read, 0);

	int* p = shmat(shmid, NULL, 0);

	srand(getpid());
	int i = 0;
	while (1) {
		P(sem_write);
		printf("��ʼ����....%d\n", i);
		sleep(rand() % 5);
		*p = i++;
		printf("��������....%d\n", i - 1);
		V(sem_read);
	}
}




//���������ڴ�
int open_shm(key_t key) {
	return shmget(key, 0, 0);
}


//�����ź���
int open_sem(key_t key) {
	return semget(key, 0, 0);
}

//�����ź���
union semun { int val; };

void sem_setval(int id, int val) {
	union semun su;
	su.val = val;
	semctl(id, 0, SETVAL, su);
}

//PV����
void P(int id) {
	struct sembuf sb[1];
	sb[0].sem_num = 0;
	sb[0].sem_op = -1;
	sb[0].sem_flg = 0;
	semop(id, sb, 1);
}

void V(int id) {
	struct sembuf sb[1];
	sb[0].sem_num = 0;
	sb[0].sem_op = 1;
	sb[0].sem_flg = 0;
	semop(id, sb, 1);
}

int main(void) {
	int shmid = open_shm(1234);
	int sem_write = open_sem(1234);
	int sem_read = open_sem(1235);

	int* p = shmat(shmid, NULL, 0);
	srand(getpid());
	while (1) {
		P(sem_read);
		printf("��ʼ����....%d\n", *p);
		sleep(rand() % 3);
		printf("��������...%d\n", *p);
		V(sem_write);
	}
}
