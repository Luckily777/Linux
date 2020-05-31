1.验证文件表和描述文件表是几份
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main(void) {
	int fd1 = open("test.txt", O_RDONLY);
	int fd2 = open("test.txt", O_RDWR);

	char buf1[10 + 1] = {};
	char buf2[10 + 1] = {};

	//验证文件表是两份
	read(fd1, buf1, 10);
	read(fd2, buf2, 10);
	printf("buf2=[%s]\n", buf1);
	printf("buf2=[%s]\n", buf2);

	//证明inode只有一份
	memset(buf1, 0x00, sizeof(buf1));
	write(fd3, "AAAAA", 5);
	read(fd1, buf1, 6);
	printf("buf1=[%s]\n", buf1);
	close(fd1);
	close(fd2);
}


2.子进程和父进程使用的是否是同一个文件描述符表
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void) {
	int fd = open("test.txt", O_RDWR);
	pid_t pid = fork();
	if (pid == 0) {
		write(fd, "XXXX", 4);
		close(fd);
	}
	else {
		char buf[10] = {};
		sleep(1);
		read(fd, buf, 5);
		printf("buf=[%s]\n", buf);
		wait(NULL);
		getchar();
		close(fd);

	}
}


3. 读写标志位的偏移
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void) {
	int fd = open("test.txt", O_RDWR);
	char buf[5] = {};
	read(fd, buf, 4);
	printf("buf=[%s]\n", buf);
	close(fd);
	getchar();
}


4. 