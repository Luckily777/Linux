//public

#ifndef __PUBLIC_H__
#define __PUBLIC_H__

#include <unistd.h>

//客户端和服务器之间的消息格式

typedef struct {
	int len;//网络字节序，定长部分
	char cont[1024];//真在要发送的内容，变长的部分
}message_t;

ssize_t readn(int fd, void* buf, size_t count);
ssize_t writen(int fd, const void* buf, size_t count);

#endif


#include <errno.h>
#include <unistd.h>

ssize_t readn(int fd, void* buf, size_t count) {
	int nleft = count;//剩余字节数
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



