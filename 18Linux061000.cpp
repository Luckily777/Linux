//������������
[root@luckily study]# cd day0e
[root@luckily day0e]# vim 01.c
[root@luckily day0e]# gcc01.c
bash : gcc01.c : δ�ҵ�����...
[root@luckily day0e]# gcc 01.c
01.c: �ں�����main����:
01.c : 24 : 27 : ���󣺡�OLD_SET��δ����(�ڴ˺����ڵ�һ��ʹ��)
sigprocmask(SIG_SETMASK, &OLD_SET, NULL);//����ź�����
^
01.c:24 : 27 : ��ע��ÿ��δ�����ı�ʶ��������ֵĺ�����ֻ����һ��
[root@luckily day0e]# vim 01.c
[root@luckily day0e]# gcc 01.c
[root@luckily day0e]# . / a.out
��ʼ������1��
��1����������
��ʼ������2��
^ C��2����������
��ʼ������3��
^ C��3����������
��ʼ������4��
��4����������
��ʼ������5��
^ \�˳�(�º�)
[root@luckily day0e]# vim 01.c
[root@luckily day0e]# gcc 01.c
[root@luckily day0e]# . / a.out
��ʼ������1��
^ C��1����������
��ʼ������2��
��2����������
��ʼ������3��
��3����������
��ʼ������4��
��4����������
��ʼ������5��
��5����������
rec 2
main finish!
[root@luckily day0e]# vim 01.c
[root@luckily day0e]# vim 02.c
[root@luckily day0e]# gcc 02.c
[root@luckily day0e]# . / a.out
^ \ ^ Csignal stop
handler exit
�˳�(�º�)
[root@luckily day0e]# vim 01.c
[root@luckily day0e]# gcc 01.c
[root@luckily day0e]# . / a.out
��ʼ������1��
��1����������
��ʼ������2��
^ C��2����������
���ź���Ҫ����
ִ���ⲿ����
��ʼ������3��
��3����������
��ʼ������4��
��4����������
��ʼ������5��
^ C��5����������
���ź���Ҫ����
ִ���ⲿ����
main finish!
[root@luckily day0e]# 


[root@luckily ~]# cd study
[root@luckily study]# cd day0d
[root@luckily day0d]# ls
01.c  02.c  03.c  04.c  05.c  a.out
[root@luckily day0d]# cd ..
[root@luckily study]# ls
day01  day03  day05  day07  day09  day0b  day0d
day02  day04  day06  day08  day0a  day0c  day0e
[root@luckily study]# cd day0e
[root@luckily day0e]# ls
01.c  02.c  a.out
[root@luckily day0e]# vim 01.c
[root@luckily day0e]# vim 03.c
[root@luckily day0e]# cat 01.c
//�������Ӿ� ��ֹ�ź�
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
[root@luckily day0e]# cat 02.c
//��ͣ
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
[root@luckily day0e]# cat 03.c
//ͨ�Ź����������ź�
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
[root@luckily day0e]# 
