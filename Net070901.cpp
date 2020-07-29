//�����

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(void) {
	// ���������׽���
	int lfd = socket(AF_INET, SOCK_STREAM, 0);
	printf("����socket�ɹ�\n");

	struct sockaddr_in addr;
	addr.sin_family = AF_INET;
	addr.sin_port = htons(9999);
	inet_aton("192.168.142.100", &addr.sin_addr);

	//��
	int r = bind(lfd, (struct sockaddr*) & addr, sizeof(addr));
	if (r == -1) perror("bind"), exit(1);
	printf("�󶨳ɹ�\n");

	//���óɱ����׽���
	if ((r = listen(lfd, SOMAXCONN)) == -1) {
		perror("listen"), exit(1);
	}
	printf("���óɼ����׽��ֳɹ�\n");

	//�ȴ��ͻ��˵�����
	int newfd = accept(lfd, NULL, NULL);
	printf("�пͻ�����������\n");

	while (1) {
		char buf[1024] = {};
		r = read(newfd, buf, 1024);
		printf("%s", r);
		if (r == 0) {
			break;
		}
		write(newfd, buf, r);
	}

	close(newfd);
	close(lfd);
}
