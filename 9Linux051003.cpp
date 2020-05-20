//第二个小时的基础操作

[root@luckily ~]# cd study
[root@luckily study]# cd day05
[root@luckily day05]# vim 02.c
[root@luckily day05]# cat 02.c
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int g_argc = 0;
char* g_argv[10];
int g_env_len;
char* g_env[500];


int main(int argc, char* argv[]) {
	//将环境便利和命名行参数搬走
	char* New_g_argv = (char*)malloc(sizeof(char) * 10);
	for (int i = 0; i < 10; i++) {
		strcpy(New_g_argv[i] = g_argv[i]);
	}
	//memcpy(New_g_argv,g_argv,10); 不能够直接拷贝，因为其空间不是字符串可能存在不连续的情况
	memset(g_argv, 0, 10);
	char* New_g_env = (char*)malloc(sizeof(char) * 500);
	for (int i = 0; i < 10; i++) {
		strcpy(New_g_env[i] = g_env[i]);
	}
	//memcpy(New_g_env,g_env,500);
	memset(g_argv, 0, 500);
	pid_t  pid = fork();

	switch (pid) {
	case -1:break;
	case 0:
		strcpy(argv[0], "worker");
		printf("dddddddd\n");
		break;
	default:
		strcpy(argv[0], "master");
		printf("xxxxxxxx\n");
		break;
	}
	getchar();
}
[root@luckily day05]# vim 03.c
[root@luckily day05]# vim 04.c
[root@luckily day05]# gcc 04.c
[root@luckily day05]# . / a.out
你想创建几个子进程：
2
hehe
hehe
hehe
^ C
[root@luckily day05]# vim 05.c
[root@luckily day05]# gcc 0
gcc: 错误：0：没有那个文件或目录
gcc : 致命错误：没有输入文件
编译中断。
[root@luckily day05]# gcc 05.c
[root@luckily day05]# . / a.out
alibaba
[root@luckily day05]# echo $ ?
0
[root@luckily day05]# vim 05.c
[root@luckily day05]# gcc 05.c
[root@luckily day05]# . / a.out
alibaba

Fun2()
Fun1()
[root@luckily day05]# cat 05.c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void Fun1(void) {
	printf("Fun1()\n");
}

void Fun2(void) {
	printf("Fun2()\n");
}

int main(void) {
	//后注册的先调用
	atexit(Fun1);
	atexit(Fun2);
	//1. 输出两次
	//printf("alibaba");
	//fork();
	//2.输出一次
	printf("alibaba\n");
	// fork();
	while (getchar() != '\n')
		;
	exit(0);//默认

}
[root@luckily day05]# vim 06.c
[root@luckily day05]# gcc 06.c
[root@luckily day05]# . / a.out
alibaba
Fun2()
Fun1()
[root@luckily day05]# cat 06.c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void Fun1(void) {
	printf("Fun1()\n");
}

void Fun2(void) {
	printf("Fun2()\n");
}

typedef struct  Node {
	void(*f)(void);
	struct 	Node* next;
}Node_t;

Node_t* head = NULL;

int my_atexit(void(*f)(void)) {
	Node_t* p = malloc(sizeof(Node_t));
	p->f = f;
	p->next = NULL;

	if (head == NULL) {
		head = p;
	}
	else {
		p->next = head;
		head = p;
	}
}

void my_exit(int s) {
	fflush(stdout);//刷新缓存

	//换行退出处理程序
	while (head != NULL) {
		head->f();
		head = head->next;
	}

	_exit(s);
}

int main(void) {
	//后注册的先调用
	my_atexit(Fun1);
	my_atexit(Fun2);
	//1. 输出两次
	//printf("alibaba");
	//fork();
	//2.输出一次
	printf("alibaba");
	// fork();
	while (getchar() != '\n')
		;
	my_exit(0);
}

[root@luckily day05]# vim 08.c
[root@luckily day05]# gcc 08.c
[root@luckily day05]# . / a.out
in fun()
catch 1 error
exit
[root@luckily day05]# vim 08.c
[root@luckily day05]# gcc 08.c
[root@luckily day05]# . / a.out
in fun()
ok
normal
exit
[root@luckily day05]# tail 08.c
printf("normal\n");
	}
	else if (r == 1) {
	printf("catch 1 error\n");
	}
	else if (r == 2) {
	printf("catch 2 error\n");
		}
		printf("exit\n");
}
