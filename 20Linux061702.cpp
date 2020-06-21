//客户端和服务器之间

//服务器
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/msg.h>

struct msgbuf {
	long type;
	char text[100];
};

int main(void) {
	int id = msgget(1234, 0);
	struct msgbuf sndbuf;
	struct msgbuf rcvbuf;
	pid_t pid = getpid();

	while (1) {
		memset(&sndbuf, 0x00, sizeof(sndbuf));
		memset(&rcvbuf, 0x00, sizeof(rcvbuf));
		sndbuf.type = 1;
		*(pid_t*)(sndbuf.text) = pid;
		fgets(sndbuf.text + sizeof(pid_t), 100 - sizeof(pid_t), stdin);
		msgsnd(id, &sndbuf, strlen(sndbuf.text + sizeof(pid_t)) + sizeof(pid_t), 0);

		msgrcv(id, &rcvbuf, 100, pid, 0);
		printf("==> %s\n", rcvbuf.text + sizeof(pid_t));
	}
}



//客户
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <signal.h>


struct msgbuf {
	long type;
	char text[100];
};
int id;

void handler(int s) {
	msgctl(id, IPC_RMID, 0);
	exit(0);
}

int main(void) {
	struct sigaction act;
	act.sa_handler = handler;
	sigemptyset(&act.sa_mask);
	act.sa_flags = 0;
	sigaction(SIGINT, &act, NULL);

	id = msgget(1234, IPC_CREAT | 0644);
	if (id == -1)perror("creat error"), exit(1);

	struct msgbuf rcvbuf;

	while (1) {
		memset(&rcvbuf, 0x00, sizeof(rcvbuf));
		msgrcv(id, &rcvbuf, 100, 1, 0);


		rcvbuf.type = *(pid_t*)(rcvbuf.text);
		msgsnd(id, &rcvbuf, strlen(rcvbuf.text + sizeof(pid_t)) + sizeof(pid_t), 0);
	}
}
