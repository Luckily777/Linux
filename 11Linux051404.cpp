//�鿴������
[root@luckily day07]# ls
01.c  02.c  03.c  04.c  a.out  myenv  myenv.c  myshell.c
[root@luckily day07]# cat 01.c
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
[root@luckily day07]# cat 02.c
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

	//�ӽ���һ���߲�������
	int status;
	while (waitpid(pid, &status, WNOHANG) != pid)
		;
	if (WIFEXITED(status)) {//�ӽ��������˳���������
		return WEXITSTATUS(status);//��ȡ�ӽ��̵��˳���
	}
	return -1;
}

int main() {
	printf("before system\n");
	my_system("ls -l");
	printf("after system\n");
}
[root@luckily day07]# cat 03.c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char* argv[], char* envp[]) {
	//int ret = execl("/bin/ls","ls",NULL);
	//if(ret == -1) perror("execl"),exit(1);
	int ret = execle("./myenv", "./myenv", NULL, envp);
	if (ret == -1) perror("execl"), exit(1);

}
[root@luckily day07]# cat 04.c
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
[root@luckily day07]# cat myenv.c
#include <stdio.h>

int main(int argc, char* argv[], char* envp[]) {
	while (*envp != NULL) {
		printf("%s\n", *envp++);
	}
}

[root@luckily day07]# cat myshell.c
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
		printf("��ǰshell���ֹ��ϣ��޷�����\n");
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
