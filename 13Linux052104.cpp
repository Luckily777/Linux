4. dup复制文件描述符
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/wait.h>


int main(void) {
	int fd = open("test.txt", O_RDWR);
	printf("fd=%d\n", fd);
	int newfd = dup(fd);
	printf("before close(fd)\n");
	getchar();
	close(fd);
	printf("after close(fd)\n");
	getchar();
	printf("newfd=%d\n", newfd);

	write(newfd, "ZZ", 2);
}


5.输出重定向的
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void) {
	int fd = open("test.txt", O_RDWR);
	close(1);//关闭标准输出
	dup(fd);
	printf("this is maomaochong");
}


6.fcntl的FD_CLOEXEC 关闭输入重定向
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main(void) {
	//fcntl(1,F_SETFD,FD_CLOEXEC);
	char* msg = "hehe\n";
	write(1, msg, strlen(msg));

	execlp("./ttt", "./ttt", NULL);
}



7.修改读写标志
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>


int main(void) {
	char buf[1024] = {};
	int flags = fcntl(0, F_GETFL);
	fcntl(2, F_SETFL, flags | O_NONBLOCK);
	int r = read(0, buf, 1024);
	if (r == -1) perror("read"), exit(1);
	printf("buf=[%s]\n", buf);
}


*
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main(void) {
	char* msg = "hello world!\n";
	write(1, msg, strlen(msg));
	getchar();
	getchar();
}
