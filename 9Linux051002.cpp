第八节课使用程序 代码

1. 虚拟地址和物理地址

#include <stdio.h>
#include <unistd.h>

int g_data = 100;
int main(void) {
	pid_t pid = fork();
	switch (pid) {
	case -1:
		printf("fork error\n");
		break;
	case 0:
		g_data = 200;
		printf("child : %p,&g_data = %p,g_data=%d\n", &main, &g_data, g_data);
		break;
	default:
		sleep(1);
		printf("parent : %p, &g_data = %p,g_data = %d\n", &main, &g_data, g_data);
		break;
	}
	sleep(1);
}


//2. 获取环境变量及命令参数的解读

#include <stdio.h>
#include <stdlib.h>

//argc:命令行参数的个数
//argv:命令行参数
int main(int argc, char* argv[], char* envp[]) {
	int i;

	printf("argc = %d\n", argc);

	/*for(i=0;i<argc;i++){
		printf("argv[%d]= %s\n",i,argv[i]);
	}*/


	/* for(i=0;i<envp[i]!=NULL;i++){
				printf("%d : %s\n",i,envp[i]);
		 }
	*/

	char* shell = getenv("SHELL"); //获取环境变量
	printf("%s\n", shell == NULL ? "NULL" : shell);

	//设置环境变量	
	if (putenv("AAA=abc") == 0) {
		printf("putenv() ok\n");
	}
	else {
		printf("putenv() error\n");
	}

	shell = getenv("AAA"); //获取环境变量
	printf("%s\n", shell == NULL ? "NULL" : shell);


}

//3. 父子进程同名
#include <stdio.h>
#include <unistd.h>

int main(void) {
	pid_t  pid = fork();

	switch (pid) {
	case -1:break;
	case 0:
		printf("dddddddd\n");
		break;
	default:
		printf("xxxxxxxx\n");
		break;
	}
	getchar();
}


//4. 将环境便利和命名行参数搬走
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


//5. 父子进程轮换死亡得状态
#include <stdio.h>
#include <unistd.h>

int main(void) {
	pid_t pid = fork();
	if (pid == 0) {
#if 0
		while (1) {
			printf("+++++++++++++++child,pid=%d,ppid=%d\n", getpid(), getppid());
#endif 
		}
	}
	else {
		while (1) {
			printf("############parent\n");
		}
	}
}



//6. 刷新缓存区和 （结束exit）
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

//7. exit和atexit得实现
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


//8. 收取僵尸
#include <stdio.h>
#include <unistd.h>
//#include <sys/wait.h>
int main(void) {
	pid_t pid;
	/*
		if((pid=fork())==0){
			int i;
			for(i=0;i<10;i++){
				printf(".");
				fflush(stdout);
				sleep(1);
			}
		}
		else{
	*/
	pid_t r = wait(NULL);
	if (r == -1) {
		printf("r==-1\n");
	}
	else {

		printf("wait return\n");
		for (;;) {
			printf("#");
			fflush(stdout);
			sleep(1);
		}
	}
	//	}
}


//9. 处理错误
