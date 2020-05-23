//1. 
#include <stdio.h>

int g_data = 10;
int main(void) {
	printf("hello g_data = %d\n", g_data);
}

//2.��Ե��
#define _GUN_SOURCE
#include <stdio.h>
#include <sched.h>
#include <unistd.h>
#include <stdlib.h>

int main(void) {
	pid_t pid;

	if ((pid = fork()) == 0) {
		cpu_set_t cpu_affinity;
		CPU_ZERO(&cpu_affinity);
		CPU_SET(0, &cpu_affinity);

		sched_setaffinity(0, sizeof(cpu_set_t), &cpu_affinity);
		while (1) {
			printf("child\n");
		}
	}
	else {
		cpu_set_t cpu_affinity;
		CPU_ZERO(&cpu_affinity);
		CPU_SET(1, &cpu_affinity);

		sched_setaffinity(0, sizeof(cpu_set_t), &cpu_affinity);

		while (1) {
			printf("parent\n");
		}
	}
}

//3.���ܴ�����Ϣ ��˭���õ�ʱ��˭�޸�
#include <stdio.h>
#include <stdlib.h>
#include <setjmp.h>

jmp_buf buf;

void fun(int n) {
	printf("in fun()\n");
	if (n == 1) {
		longjmp(buf, 1);
	}
	if (n == 2) {
		longjmp(buf, 2);
	}

	printf("ok\n");
}


int main(void) {
	int r;
	if ((r = setjmp(buf)) == 0) {
		fun(3);
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


//4.���滻 �����ӡ
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define ERR_EXIT(msg)\
	do{\
	 printf("[%s][%d]%s:%s\n",__FILE__,__LINE__,msg,strerror(errno));\
         exit(EXIT_FAILURE);\
	}while(0)


int main(void) {
	int ret = close(3);
	if (ret == -1) {
		ERR_EXIT("close");
	}
	/*if(ret == -1){
		printf("[%s][%d]close():%s\n",__FILE__,__LINE__,strerror(errno));
		exit(EXIT_FAILURE);//�����˳�
		//EXIT_SUCCESS�ɹ��˳�
	}*/

}

//5. wait���ս�ʬ�ӽ���
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define ERR_EXIT(msg)\
        do{\
         printf("[%s][%d]%s:%s\n",__FILE__,__LINE__,msg,strerror(errno));\
         exit(EXIT_FAILURE);\
        }while(0)


/*
	//���ܣ����ս�ʬ�ӽ���
	pid_t wait(int* status);
	//����ֵ�������յ��ӽ���pid��-1������
	//atatus : ����ӽ��̵�������Ϣ

*/

int main(void) {
	pid_t pid;

	if ((pid = fork()) == -1) ERR_EXIT("fork");

	if (pid == 0) {
		printf("child pid = %d \n", getpid());
		getchar();
		exit(12);
	}
	else {
		pid_t ret;
		int status;
		if ((ret = wait(&status)) == -1) ERR_EXIT("wait");
		if (WIFEXITED(status)) {//�ӽ��������˳���WIFEXITED������
			printf("noraml exit: %d\n", WEXITSTATUS(status));
		}
		else if (WIFSIGNALED(status)) {
			printf("killed by kill cmd\n");
		}
		printf("ret = %d \n", ret);
		while (1) {
			printf(".");
			fflush(stdout);
			sleep(1);
		}
	}
}

//6.
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define ERR_EXIT(msg)\
        do{\
         printf("[%s][%d]%s:%s\n",__FILE__,__LINE__,msg,strerror(errno));\
         exit(EXIT_FAILURE);\
        }while(0)


/*
 * 	//���ܣ����ս�ʬ�ӽ���
 * 		pid_t wait(int* status);
 * 			//����ֵ�������յ��ӽ���pid��-1������
 * 				//atatus : ����ӽ��̵�������Ϣ
 *
 * 					*/

	int main(void) {
	pid_t pid;

	if ((pid = fork()) == -1) ERR_EXIT("fork");

	if (pid == 0) {
		printf("child pid = %d \n", getpid());
		sleep(10);
		exit(12);
	}
	else {
		pid_t ret;
		int status;
		//sleep(1);
		if ((ret = waitpid(pid, &status, WNOHANG)) == -1) ERR_EXIT("waitpid");
		if (WIFEXITED(status)) {//�ӽ��������˳���WIFEXITED������
			printf("noraml exit: %d\n", WEXITSTATUS(status));
		}
		else if (WIFSIGNALED(status)) {
			printf("killed by kill cmd\n");
		}
		printf("ret = %d \n", ret);
		while (1) {
			printf(".");
			fflush(stdout);
			sleep(1);
		}
	}
}

