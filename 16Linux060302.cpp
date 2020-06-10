//�źŵĳ���

//1. �źŶ�ʧ ���ȶ��ź�
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>


//�źŶ�ʧ
void handler(int s) {
	printf("catch %d\n", s);
	sleep(5);
	printf("handler end\n");
}

int main(void) {

	signal(SIGINT, handler);

	for (;;) {
		printf(".");
		fflush(stdout);
		sleep(1);
	}

}


//1.1 ���ڸĶ��ź� ��ȡ���ڴ�С
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>
#include <sys/ioctl.h>
#include <termios.h>


//25�� �ı��С����ֵ���ʾ
void handler(int s) {
	if (s == SIGINT) {
		printf("catch %d\n", s);
		sleep(5);
		printf("handler end\n");
	}
	else if (s == SIGWINCH) {
		printf("%s\n", strsignal(s));
	}
}

int main(void) {

	signal(SIGINT, handler);
	signal(SIGWINCH, handler);

	for (;;) {
		struct winsize w;
		ioctl(0, TIOCGWINSZ, &w);//��ȡ���ڴ�С
		printf("row=%d,col=%d\n", w.ws_row, w.ws_col);
		fflush(stdout);
		sleep(1);
	}
}



//1.2  �ɿ��ź�
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>
#include <sys/ioctl.h>
#include <termios.h>


//34�� �ɿ��ź�
void handler(int s) {
	if (s == SIGRIMIN) {
		printf("catch %d\n", s);
		sleep(5);
		printf("handler end\n");
	}
	else if (s == SIGWINCH) {
		printf("%s\n", strsignal(s));
	}
}
int main(void) {
	signal(SIGRIMIN, handler);
	signal(SIGWINCH, handler);
	for (;;) {
		struct winsize w;
		ioctl(0, TIOCGWINSZ, &w);//��ȡ���ڴ�С
		//printf("row=%d,col=%d\n",w.ws_row,w.ws_col)��
		printf(".");
		fflush(stdout);
		sleep(1);
	}
}


//2.kill��ʵ��
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char* argv[]) {
	if (argc != 2) {
		printf("usage :%s pid\n", argv[0]);
		exit(1);
	}
	int pid = atoi(argv[1]);

	kill(pid, SIGKILL);
}



//3. ���������ӽ���֮��Ĺ�ϵ
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

void handler(int s) {
	while (waitpid(-1, NULL, WNOHANG) > 0)
		;
}

int main(void) {
	int num, i;

	signal(SIGCHLD, handler);

	printf("num:");
	scanf("%dd", &num);

	pid_t pid = getpid();

	for (i = 0; i < num; i++) {
		if (fork() == 0)
			break;
	}

	if (getpid() == pid) {
		for (;;) {
			printf("$");
			fflush(stdout);
			sleep(1);
		}
	}
	else for (i = 0; i < 10; i++) {
		printf(".");
		fflush(stdout);
		sleep(1);
	}
}


//4. ����ʱ ʱ��
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

int V = 0;
int X = 0;

void handler(int s) {
	printf("time out");
	printf("V=%d,X=%d", V, X);
	exit(0);
}

//14�� ʱ��

int main(void) {
	signal(SIGALRM, handler);

	alarm(20);
	srand(time(NULL));
	int i;

	for (i = 1; i < 10; i++) {
		int left = rand() % 10;
		int right = rand() % 10;
		int ret;
		printf("%d+%d=", left, right);
		scanf("%d", &ret);

		if (ret == (left + right)) {
			V++;
		}
		else {
			X++;
		}
	}
	printf("������̫���ˣ�V=%d,X=%d", V, X);
}


//5. ��ʱ��
#include <stdio.h> 
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>

//��ʱ��
void handler(int s) {
	printf("ʱ�䵽��\n");
}

int main(void) {
	signal(SIGALRM, handler);

	struct itimerval it;
	it.it_value.tv_sec = 0;
	it.it_value.tv_usec = 1;
	it.it_interval.tv_sec = 2;
	it.it_interval.tv_usec = 0;

	setitimer(ITIMER_REAL, &it, NULL);

	for (;;) {
		printf(".");
		fflush(stdout);
		sleep(1);
	}
}

