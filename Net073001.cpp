//服务端


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <signal.h>
#include <sys/wait.h>
#include <errno.h>

void hander(int s) {
	while (waitpid(-1, NULL, WNOHANG) != -1)
		;
}

void parse(char* buf) {
	int i, len;
	len = strlen(buf);
	for (i = 0; i < len; i++) {
		if (buf[i] >= 'a' && buf[i] <= 'z') {
			buf[i] = buf[i] - 32;
		}
	}
}


int main() {
	struct sigaction act;
	act.sa_handler = hander;
	act.sa_flags = 0;
	sigemptyset(&act.sa_mask);
	sigaction(SIGCHLD, &act, NULL);

	//创建监听套接字
	int lfd = socket(AF_INET, SOCK_STREAM, 0);
	printf("创建socket成功\n");

	struct sockaddr_in addr;
	add.sin_family = AF_INET;
	addr.sin_port = htons(9999);
	inet_aton("192.168.204.200", &addr.sin_addr);

	//绑定
	int r = bind(lfd, (struct sockaddr*) & addr, sizeof(addr));
	if (r == -1)perror("bind"), exit(1);
	printf("绑定成功\n");


	//设置成被动套接字
	if ((r = listen(lfd, SOMAXCONN)) == -1)
		perror("listen"), exit(1);
	printf("设置成监听套接字成功\n")；

		for (;;) {
			//等待客户端的链接
			int newfd = accept(lfd, NULL, NULL);
			if (newfd == -1 && errno == EINTR) {
				continue;
			}
			printf("有客户端链接上来\n");
			pif_t pid = fork();
			if (pid == 0) {
				close(lfd);
				while (1) {
					char buf[1024] = {};
					r = read(newfd, buf, 1024);
					if (r == -1) {
						perror("read");
						exit(1);
					}
					if (r == 0)break;

					printf("===> %s\n", buf);
					parse(buf);
					write(newfd, buf, r);
				}
				close(newfd);
				exit(0);
			}
			else {
				close(newfd);
			}
		}
	close(lfd);
}
