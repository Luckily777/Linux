//信号量集

1. 创建信号量
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <string.h>

int main(void) {
	int semid = semget(1234, 1, IPC_CREAT | 0644);
	if (semid == -1) perror("semget"), exit(1);

	printf("creat ok\n");
}

int main(void) {
	int semid = semget(1234, 0, 0);
	printf("%d\n", semctl(semid, 0, GETVAL, 0));

}

3.设置信号量
union semun {
	int val;
};

int main(void) {
	int semid = semget(1234, 0, 0);
	union semun su;
	printf("val: ");
	scanf("%d", &su.val);

	semctl(semid, 0, SETVAL, su);

}

4. pv操作
int main(void) {
	int semid = semget(1234, 0, 0);
	struct sembuf sb[1];

	sb[0].sem_num = 0;
	sb[0].sem_op = -1;
	sb[0].sem_flg = 0;
	semop(semid, sb, 1);
}


int main(void) {
	int semid = semget(1234, 0, 0);
	struct sembuf sb[1];

	sb[0].sem_num = 0;
	sb[0].sem_op = 1;
	sb[0].sem_flg = 0;
	semop(semid, sb, 1);

}

5.打印xoxox
void print_char(int semid, char c) {
	int i;
	for (i = 0; i < 10; i++) {
		P(semid);
		printf("%c", c);
		fflush(stdout);
		sleep(rand() % 3);
		printf("%c", c);
		fflush(stdout);
		sleep(rand() % 3);
		V(semid);
	}
}
void handler(int s) {
	wait(NULL);
}

int sem_create(key_t key) {
	return semget(key, 1, IPC_CREAT | 0644);

}

union semnu {
	int val;
};

void sem_setval(int id, int val) {
	union semnu su;
	su.val = val;
	semctl(id, 0, SETVAL, su);
}


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
	struct sigaction act;
	act.sa_handler = handler;
	sigemptyset(&act.sa_mask);
	act.sa_flags = 0;
	sigaction(SIGCHLD, &act, NULL);

	int semid = sem_create(1234);
	sem_setval(semid, 1);
	srand(getpid());

	pid_t pid = fork();

	if (pid == 0) {
		print_char(semid, 'o');
	}
	else {
		print_char(semid, 'x');
	}
}

