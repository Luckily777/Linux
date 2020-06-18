//基本操作代码
[root@luckily study]# cd day0e
[root@luckily day0e]# vim 01.c
[root@luckily day0e]# gcc01.c
bash : gcc01.c : 未找到命令...
[root@luckily day0e]# gcc 01.c
01.c: 在函数‘main’中:
01.c : 24 : 27 : 错误：‘OLD_SET’未声明(在此函数内第一次使用)
sigprocmask(SIG_SETMASK, &OLD_SET, NULL);//解除信号屏蔽
^
01.c:24 : 27 : 附注：每个未声明的标识符在其出现的函数内只报告一次
[root@luckily day0e]# vim 01.c
[root@luckily day0e]# gcc 01.c
[root@luckily day0e]# . / a.out
开始拷贝第1集
第1集拷贝结束
开始拷贝第2集
^ C第2集拷贝结束
开始拷贝第3集
^ C第3集拷贝结束
开始拷贝第4集
第4集拷贝结束
开始拷贝第5集
^ \退出(吐核)
[root@luckily day0e]# vim 01.c
[root@luckily day0e]# gcc 01.c
[root@luckily day0e]# . / a.out
开始拷贝第1集
^ C第1集拷贝结束
开始拷贝第2集
第2集拷贝结束
开始拷贝第3集
第3集拷贝结束
开始拷贝第4集
第4集拷贝结束
开始拷贝第5集
第5集拷贝结束
rec 2
main finish!
[root@luckily day0e]# vim 01.c
[root@luckily day0e]# vim 02.c
[root@luckily day0e]# gcc 02.c
[root@luckily day0e]# . / a.out
^ \ ^ Csignal stop
handler exit
退出(吐核)
[root@luckily day0e]# vim 01.c
[root@luckily day0e]# gcc 01.c
[root@luckily day0e]# . / a.out
开始拷贝第1集
第1集拷贝结束
开始拷贝第2集
^ C第2集拷贝结束
有信号需要处理
执行外部动作
开始拷贝第3集
第3集拷贝结束
开始拷贝第4集
第4集拷贝结束
开始拷贝第5集
^ C第5集拷贝结束
有信号需要处理
执行外部动作
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
//拷贝电视剧 防止信号
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void handler(int s) {
	printf("执行外部动作\n", s);
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

	sigprocmask(SIG_BLOCK, &set, &old_set);//屏蔽信号
	for (i = 0; i < 5; i++) {
		printf("开始拷贝第%d集\n", i + 1);
		sleep(3);
		printf("第%d集拷贝结束\n", i + 1);
		sigemptyset(&pend);//使用之前一定要牢记 要清空
		sigpending(&pend);
		if (sigismember(&pend, SIGINT)) {
			printf("有信号需要处理\n");
			sigset_t tmp;
			sigemptyset(&tmp);
			sigsuspend(&tmp);
		}
	}
	sigprocmask(SIG_SETMASK, &old_set, NULL);//解除信号屏蔽

	printf("main finish!\n");
}
[root@luckily day0e]# cat 02.c
//暂停
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
		sigsuspend(&set);//在执行sigsuspend期间的信号屏蔽
		if (errno != EINTR) {
			perror("sigsuspend()");
		}
		printf("abc\n");
	}
}
[root@luckily day0e]# cat 03.c
//通信过程中屏蔽信号
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void handler(int s) {
	printf("recv %d\n", s);
}

//自己实现的sigaction
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
