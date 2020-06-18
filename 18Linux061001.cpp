//�źų���


//1. �������Ӿ� ��ֹ�ź�
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void handler(int s) {
	printf("ִ���ⲿ����\n", s);
	sleep(2);
}

int main(void) {
	int i;
	//srand(time(NULL));

	sigset_t set, old_set, pend;

	signal(SIGINT, handler);

	sigemptyset(&set);
	sigemptyset(&old_set);

	sigaddset(&set, SIGINT);

	sigprocmask(SIG_BLOCK, &set, &old_set);//�����ź�
	for (i = 0; i < 5; i++) {
		printf("��ʼ������%d��\n", i + 1);
		sleep(3);
		printf("��%d����������\n", i + 1);
		sigemptyset(&pend);//ʹ��֮ǰһ��Ҫ�μ� Ҫ���
		sigpending(&pend);
		if (sigismember(&pend, SIGINT)) {
			printf("���ź���Ҫ����\n");
			sigset_t tmp;
			sigemptyset(&tmp);
			sigsuspend(&tmp);
		}
	}
	sigprocmask(SIG_SETMASK, &old_set, NULL);//����ź�����

	printf("main finish!\n");
}


//2. ��ͣ
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <errno.h>
#include <string.h>

void handler(int s) {
	printf("signal stop\n");
	sleep(3);
	printf("handler exit\n");
}

int main(void) {
	sigset_t set;
	signal(SIGINT, handler);

	for (;;) {
		//pause();
		sigemptyset(&set);
		sigaddset(&set, SIGQUIT);
		sigsuspend(&set);//��ִ��sigsuspend�ڼ���ź�����
		if (errno != EINTR) {
			perror("sigsuspend()");
		}
		printf("abc\n");
	}
}


//3. ͨ�Ź����������ź�
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void handler(int s) {
	printf("recv %d\n", s);
}

//�Լ�ʵ�ֵ�sigaction
__sighandler_t mysignal(int signum, __sighandler_t hand) {
	struct sigaction t, old;

	t.sa_handler = hand;
	t.sa_flags = 0;
	sigemptyset(&t.sa_mask);

	sigaction(signum, &t, &old);

	return old.sa_handler;
}

int main(void) {
	struct sigaction act;
	act.sa_handler = handler;
	act.sa_flags = 0;
	sigemptyset(&act.sa_mask);
	sigaction(SIGINT, &act, NULL);

	for (;;) {
		printf(".");
		fflush(stdout);
		sleep(1);
	}
}
