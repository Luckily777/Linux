// ¹²ÏíÄÚ´æ --ÄÚ´æ

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>


int main(void) {
	int shmid = shmget(1234, sizeof(int), IPC_CREAT | 0644);
	if (shmid == -1) perror("shmget"), exit(1);
	printf("create shared memory ok\n");
}



int main(void) {
	int shmid = shmget(1234, 0, 0);
	int* p = (int*)shmat(shmid, NULL, 0);

	int i = 0;
	while (1) {
		*p = i++;
		printf("write %d\n", i);
		sleep(1);
	}
	shmdt(p);
}


int main(void) {
	int shmid = shmget(1234, 0, 0);

	int* p = (int*)shmat(shmid, NULL, 0);

	printf("*p= %d\n", *p);

	getchar();
	shmdt(p);
}
