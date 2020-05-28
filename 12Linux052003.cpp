//所有程序

1.
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <errno.h>

int main(void) {
	int fd = open("test.txt", O_RDWR);
	if (fd >= 0) {
	}
	else if (fd == -1) {
		if (errno == ENOENT) {
			sleep(10);
			fd = open("test.txt", O_RDWR | O_CREAT | O_EXCL, 0644);
			if (fd == -1) {
				perror("open"), exit(1);
			}
			printf("teset.txt created by %p \n", getpid());
		}
		else {
			perror("open"), exit(1);
		}
	}
}


2.
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>

//usage : ./mycpy src dst

int main(int argc, char* argv[]) {
	if (argc != 3) {
		fprintf(stderr, "usage: %s src_file dst_file\n", argv[0]);
		exit(EXIT_FAILURE);

	}
	//以只读的形式打开源文件
	int fd_src = open(argv[1], O_RDONLY);
	if (fd_src == -1) {
		fprintf(stderr, "open(%s):%s\n", argv[1], strerror(errno));
		exit(EXIT_FAILURE);
	}

	//以写的方式打开目标文件，并且创建
	//O_TRUNC :如果文件存在，就将内容删除
	int fd_dst = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd_dst == -1) {
		close(fd_src);//释放资源
		fprintf(stderr, "open(%s):%s\n", argv[2], strerror(errno));
		exit(EXIT_FAILURE);
	}

	char buf[1024];
	while (1) {
		memset(buf, 0x00, sizeof(buf));
		int ret = read(fd_src, buf, 1024);
		if (ret == -1) {
			fprintf(stderr, "read(%s):%s\n", argv[1], strerror(errno));
			break;
		}
		else if (ret == 0) {//读完文件，返回为0
			break;
		}
		if (write(fd_dst, buf, ret) == -1) {
			fprintf(stderr, "write(%s):%s\n", argv[2], strerror(errno));
			break;
		}
	}
	close(fd_src);
	close(fd_dst);
	//关闭文件
}


3.
#include <stdio.h>

int main(void) {
	char buf[1024] = {};

	FILE* fp = fopen("aaa", "w");
	fprintf(fp, "{id:%d name=\'%s\' , sal=%.2f}", 3, "zhangsan", 10.2);
	//fprintf(stdout,"{id:%d name=\'%s\' , sal=%.2f}",3,"zhangsan",10.2);
	//snprintf(buf,1024,"{id:%d name=\'%s\' , sal=%.2f}",3,"zhangsan",10.2);
	//printf("%s\n",buf);
	fclose(fp);
}

4.
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

typedef struct {
	int id;
	char name[32];
}stu_t;

//输入学生信息
void input(int n) {
	int fd = open("stu.dat", O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)perror("open"), exit(1);

	int i = 1;
	do {
		stu_t s;
		s.id = i++;
		printf("name:");
		scanf("%s", s.name);
		if (write(fd, &s, sizeof(stu_t)) != sizeof(stu_t)) perror("write"), exit(1);
	} while (n--);
	close(fd);
}

//显示学生信息
void output(int n) {
	int fd = open("stu.dat", O_RDNOLY);
	if (fd == -1) perror("open"), exit(1);

	stu_t buf;
	int r = lseek(fd, (n - 1) * sizeof(stu_t), SEEK_SET);
	printf("r=%d\n", r);
	if (read(fd, &buf, sizeof(buf)) == -1)perror("read"), exit(1);
	printf("id =%d ,name =%s \n", buf.if, buf.name);

	close(fd);
}


int main() {
	int n;
	printf("要输入的几个学生信息？");
	scanf("%d", &n);
	input(n);

	while (1) {
		printf("要显示几号学生信息（-1 exit）");
		int n;
		scanf("%d", &n);
		if (n == -1)break;
		output(n);
	}
}
