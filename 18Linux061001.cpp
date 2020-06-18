//信号程序


//1. 拷贝电视剧 防止信号
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


//2. 暂停
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


//3. 通信过程中屏蔽信号
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
