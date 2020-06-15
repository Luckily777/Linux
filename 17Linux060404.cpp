//����

//1. malloc���жϺ�
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

int i;
void handler(int s) {
	printf("%d", i);
	exit(1);
}

int main(void) {
	//mallocÿ�η�����ٸ��ռ�	
	signal(SIGSEGV, handler);

	int* p = (int*)malloc(sizeof(int));
	int* q = (int*)malloc(sizeof(int));
	//���ڶ��ν������룬����һ��ʼ�Ŀռ���ֱ����
	for (i = 0;; i++) {
		p[i] = i;
	}
	//*(p+1)=100;


	getchar();
}


//2.
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

typedef struct {
	int a;
	int b;
	int c;
}test_t;

test_t gllobal;
//�������뺯��
void handler(int s) {
	printf("%d %d %d\n", global.a, global.b, global.c);
	alarm(1);
}

int main(void) {
	signal(SIGALRM, handler);

	alarm(1);

	test_t zero = { 0,0,0 };
	test_t one = { 1,1,1 };
	for (;;) {
		global = zero;
		global = one;
	}
}


//3.
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

void handler(int s) {
	printf("catch %d\n", s);
}

int main(void) {
	char buf[1024] = "abcdefghijkl";
	int r;
	signal(SIGHINT, handler);
	r = read(0, buf, 1024);
	if (r == -1) {
		perror("read");
	}
	else {
		printf("buf=[%s]\n", buf);
	}
}


///4.
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>


void handler(int s) {
	printf("recv :%d\n", s);
}

void handler_quit(int s) {
	sigset_t set;

	sigemptyset(&set);
	sigaddset(&set, SIGINT);

	sigprocmask(SIG_UNBLOCK, &set, NULL);
}//����ź�����

int main(void) {
	int i;
	sigset_t mask, pend;

	signal(SIGINT, handler);
	signal(SIGQUIT, handler_quit);
	sigemptyset(&mask);
	sigaddset(&mask, SIGINT);

	sigprocmask(SIG_BLOCK, &mask, NULL);

	for (;;) {
		sigemptyset(&pend);
		sigpending(&pend);
		for (i = 1; i < _NSIG; i++) {
			if (sigismember(&pend, i)) {
				printf("1");
			}
			else {
				printf("0");
			}
		}
		printf("\n");
		//fflush(stdout);
		sleep(1);
	}
}
