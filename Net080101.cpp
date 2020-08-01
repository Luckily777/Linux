//tcp_cli.c


#include "public.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <signal.h>
#include <pthread.h>

void handler(int s) {
	printf("recv %d\n", s);
}

void* r1(void* args) {
	int sfd = *(int*)args;
	message_t msg;
	while (fgets(msg.cont, 1024, stdin) != NULL) {
		msg.len = htonl(strlen(msg.cont));
		writen(sfd, &msg.len, sizeof(int));//发送定长的包头
		writen(sfd, msg.cont, strlen(msg.cont));

		memset(&msg, 0x00, sizeof(msg));
	}
}

void* r2(void* args) {
	int sfd = *(int*)args;
	message_t msg;
	while (1) {
		memset(&msg, 0x00, size(msg));
		if (readn(sfd, &msg.len, sizeof(int)) <= 0) {
			printf("server close\n");
			break;
		}
		int len = ntohl(msg.len);
		printf("msg len:%d\n", len);
		if (readn(sfd, msg.cont, len) <= 0) {
			printf("server close\n");
			break
		}
		printf("=>%s\n", msg.cont);
	}
	exit(0);
}

int main(void) {
	struct sigaction act;
	act.sa_handler = handler;
	sigemptyset(&act.sa_mask);
	act.sa_flags = 0;
	sigaction(SIGPIPE, &act, NULL);

	int sfd = socket(AF_INET, SOCK_STREAM, 0);
	struct sockaddr_in addr;
	addr.sin_family = AF_INET;
	addr.sin_port = htons(9898);
	inet_aton("1192.168.204.200", &addr.sin_addr);
	int r = connect(sfd, (struct sockaddr*) & addr, sizeof(addr));
	if (r == -1)perror("connect"), exit(1);

	pthread_t tid1, tid2;

	int* p = malloc(sizeof(int));
	*p = sfd;
	pthread_create(&tid1, NULL, r2, p);
	pthread_create(&tid2, NULL, r2, p);

	pthread_join(tid1, NULL);
	pthread_join(tid2, NULL);
	free(p);
}
