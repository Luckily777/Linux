//第十一节课程序

//1.exrclp
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

#define ERR_EXIT(msg)\
	do{\
		printf("[%s][%d] %s:%s\n",__FILE__,__LINE__,msg,strerror(errno));\
		exit(EXIT_FAILURE);\
	}while(0)

int main(void) {

	printf("before execlp\n");

	if (execlp("ls", "ls", "-l", NULL) == -1)
		ERR_EXIT("execlp");

	printf("after execlp\n");
}

//2.实现mysystem
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int my_system(const char* cmd) {
	pid_t pid;
	if ((pid = fork()) == -1)
		exit(127);
	if (pid == 0) {
		if (execlp("/bin/sh", "/bin/sh", "-c", cmd, NULL) == -1) {
			exit(1);
		}
	}

	//子进程一定走不到这里
	int status;
	while (waitpid(pid, &status, WNOHANG) != pid)
		;
	if (WIFEXITED(status)) {//子进程正常退出，返回真
		return WEXITSTATUS(status);//获取子进程的退出码
	}
	return -1;
}

int main() {
	printf("before system\n");
	my_system("ls -l");
	printf("after system\n");
}

//3.实习execle
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char* argv[], char* envp[]) {
	//int ret = execl("/bin/ls","ls",NULL);
	//if(ret == -1) perror("execl"),exit(1);
	int ret = execle("./myenv", "./myenv", NULL, envp);
	if (ret == -1) perror("execl"), exit(1);

}

//4.打开文件并读取文件
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(void) {
	int fd = open("myshell.c", O_RDONLY);
	if (fd == -1) perror("open"), exit(1);

	//printf("open ok\n");
	while (1) {
		char buf[10 + 1];
		memset(buf, 0x00, sizeof(buf));
		int r = read(fd, buf, 10);
		if (r == 0) {
			printf("end of file\n");
			break;
		}
		if (r == -1)perror("read"), exit(1);
		printf("%s", buf);
		sleep(1);
		fflush(stdout);
	}
	if (close(fd) == -1)perror("close"), exit(1);

}

//5.nevp的读取
#include <stdio.h>

int main(int argc, char* argv[], char* envp[]) {
	while (*envp != NULL) {
		printf("%s\n", *envp++);
	}
}


//6.模拟shell
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/wait.h>

#define ERR_EXIT(msg)\
         do{\
               printf("[%s][%d] %s:%sn",__FILE__,__LINE__,msg,strerror(errno));\
                exit(EXIT_FAILURE);\
        }while(0) 


int get_input(char* buf) {
	memset(buf, 0x00, sizeof(buf));
	if (scanf("%[^\n]%*c", buf) != 1) {
		int c;
		do  c = getchar(); while (c != '\n');
	}
	return strlen(buf);
}

void do_action(int argc, char* argv[]) {
	pid_t pid;
	switch (pid = fork()) {
	case -1:
		printf("当前shell出现故障，无法运行\n");
		return;
	case 0: {
		int ret = execvp(argv[0], argv);
		printf("%s:command not found\n", argv[0]);
		exit(1);
	}
		  break;
	default: {
		int status;
		waitpid(pid, &status, 0);
	}
		   break;
	}
}


void do_parse(char* buf) {
	int argc = 0;
	char* argv[10] = {};
#define OUT 0
#define IN 1

	int status = OUT;
	int i;
	for (i = 0; buf[i] != '\0'; i++) {
		if (status == OUT && !isspace(buf[i])) {
			argv[argc++] = buf + i;
			status = IN;
		}
		else if (isspace(buf[i])) {
			status = OUT;
			buf[i] = '\0';
		}
	}
	argv[argc] = NULL;
	do_action(argc, argv);
}

int main(void) {
	char buf[512];
	while (1) {
		printf("[Luckily shell] # ");
		if (get_input(buf) == 0) {
			continue;
		}
		do_parse(buf);
		//printf("= >[%s]\n",buf);
	}
}
