所有程序的查看
[root@luckily day09]# vim 07.c
[root@luckily day09]# ls
01.c  02.c  03.c  04.c  05.c  06.c  07.c  a.out  test.txt  ttt  ttt.c
[root@luckily day09]# cat 01.c
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
[root@luckily day09]# cat 02.c
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
[root@luckily day09]# cat 03.c
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
[root@luckily day09]# cat 04.c
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
[root@luckily day09]# cat 05.c
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
[root@luckily day09]# cat 06.c
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main(void) {
	//fcntl(1,F_SETFD,FD_CLOEXEC);
	char* msg = "hehe\n";
	write(1, msg, strlen(msg));

	execlp("./ttt", "./ttt", NULL);
}
[root@luckily day09]# cat 07.c
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
[root@luckily day09]# ls
01.c  02.c  03.c  04.c  05.c  06.c  07.c  a.out  test.txt  ttt  ttt.c
[root@luckily day09]# cat ttt.c
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main(void) {
	char* msg = "hello world!\n";
	write(1, msg, strlen(msg));
	getchar();
	getchar();
}
