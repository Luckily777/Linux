//1.

#include <stdio.h>
#include <unistd.h>

//vfork�����ٶ���������� ���Բ���Ҫ�˽�
//int main(void){
//	printf("hehe\n");
//	vfork();
//	printf("hehe2\n");
//}
//
int main(void) {
	signal(SIGCHLD, SIG_IGN);

	printf("hehe\n");
	if (fork() == 0) {
		exit(0);
	}

	for (;;) {
		printf(".");
		fflush(stdout);
		sleep(1);
	}
}
