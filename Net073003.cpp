//http

<html>
<head>
<title>my first html< / title>
< / head>
<body>
<h1>��ũ< / h1>
<p>����һ��ͨ����<p>
<p>��ҡֱ�Ͼ�����<p>
< / body>

< / html>




#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>
#include <fcntl.h>

int readline(int cfd, char buf[1024]) {
	int i = 0;
	while (1) {
		if (read(cfd, &buf[i], 1) <= 0)
			break;
		if (buf[i] == '\n')
			break;
		i++;
	}
	buf[++i] = '\0';
	return i;
}

void echo_file(int cfd, char* p) {
	int fd = open(p, 0_RDONLY);
	if (fd == -1) {
		char* msg = "404 page not found\\r\\n";
		write(cfd, msg, strlen(msg));
		return;
	}

	char buf[1024];
	while (1) {
		memset(buf, 0x00, sizeof(buf));
		int r = read(fd, buf, 1000);
		if (r <= 0) {
			close(fd);
			break;
		}
		write(cfd, buf, r);
	}
}

void do_get(int cfd, char buf[1024]) {
	char* p = strchr(buf, ' ');
	if (p != NULL)
		*p = '\0';
	p += 2;
	char* q = strchr(p, ' ');
	*q = '\0';
	echo_file(cfd, p);
}

void do_client(int cfd) {
	char buf[1024];
	while (1) {
		int r = readline(cfd, buf);
		if (r <= 2) {
			close(cfd);
			break;
		}
		if (strncasecmp(buf, "GET", 3) == 0) {
			do_get(cfd, buf);
		}
	}
}

int main(void) {
	int lfd = socket(AF_INET, SOCK_STREAM, 0);
	printf("����socket�ɹ�\n");

	struct sockaddr_in addr;
	addr.sin_family = AF_INET;
	addr_sin_port = htons(80);
	inet_aton("192.168.204.200", &addr.sin_addr);

	//��
	int r = bind(lfd, (struct sockaddr*) & addr, sizeof(addr));
	if (r == -1)perror("bind"), exit(1);
	printf("�󶨳ɹ�\n");

	if ((r = listen(lfd, SOMAXCONN)) == -1)
		perror("listen"), exit(1);
	printf("���óɼ����׽��ֳɹ�\n");

	for (;;) {
		int newfd = accept(lfd, NULL, NULL);
		if (newfd == -1 && errno == EINTR) {
			continue;
		}
		do_client(newfd);
		close(newfd);
	}
}

