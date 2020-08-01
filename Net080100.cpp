//public

#ifndef __PUBLIC_H__
#define __PUBLIC_H__

#include <unistd.h>

//�ͻ��˺ͷ�����֮�����Ϣ��ʽ

typedef struct {
	int len;//�����ֽ��򣬶�������
	char cont[1024];//����Ҫ���͵����ݣ��䳤�Ĳ���
}message_t;

ssize_t readn(int fd, void* buf, size_t count);
ssize_t writen(int fd, const void* buf, size_t count);

#endif


#include <errno.h>
#include <unistd.h>

ssize_t readn(int fd, void* buf, size_t count) {
	int nleft = count;//ʣ���ֽ���
	char* p = buf;

	while (nleft > 0) {
		int r = read(fd, p, nleft);
		if (r == 0) {
			return count - nleft;
		}
		if (r == -1) {
			if (errno == EINTR)
				continue;
			return -1;
		}
		nleft -= r;
		p += r;
	}
	return count;
}

ssize_t writen(int fd, const void* buf, size_t count) {
	int nleft = count;
	const char* p = buf;

	while (nleft > 0) {
		int r = write(fd, p, nleft);
		if (r == -1) {
			if (errno == EINTR) continue;
			return -1;
		}

		nleft -= r;
		p += r;
	}
	return count;
}



