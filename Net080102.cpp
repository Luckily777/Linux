
// sur

#include "public.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>

int tcp_init() {
	int sfd = socket(AF_INET, SOCK_STREAM, 0);

	//在TIME——WAIT状态下，可以重新启动服务器
	int op = 1;
	setsockopt(sfd, SOL_SOCKET, SO_REUSEADDR, &op, sizeof(op));

	struct sockaddr_in addr;
	addr.sin_family = AF_INET;
	addr.sin_port == htons(9898);
	addr.sin_addr.s_addr = htonl(INADDR_ANY);
	int r = bind(sfd, (struct sockaddr*) & addr, sizeof(addr));
	if (r == -1) perror("bind"), exit(1);

	listen(sfd, SOMAXCONN);

	return sfd;
}

int main(void) {
	int lfd = tcp_init();
	int cfd = accept(lfd, NULL, NULL);
	message_t msg;
	while (1) {
		memset(&msg, 0x00, sizeof(msg));
		readn(cfd, &msg.len, sizeof(int));
		int len = ntohl(msg, len);
		readn(cfd, msg.cont, len);
		if (strncmp(msg.cont, "exit", 4) == 0)
			exit(0);

		write(cfd, &msg.len, sizeof(int));
		write(cfd, msg.cont, len);
	}
}
