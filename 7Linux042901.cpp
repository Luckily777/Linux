���߽ڿε���Ŀ����

1. 
int main(void) {
	int num;
	do {
		printf("�����룺");
		if (scanf("%d", &num) != 1) {
			printf("����Ƿ�\n");
			scanf("%d[^\n]%*c");
			continue;
		}
		break;
	} while (1);
	printf("���ֵ%d\n", num);
}


2. ����Scanf
int main() {
	int num;
	do {
		printf("�����룺");
		if (scanf("%d", &num) != 1) {
			printf("����Ƿ�\n");
			scanf("%d*[^\n]%*c");
			continue;
		}
		break;
	} while (1);
	printf("���ֵ�˶���%d\n",num);
}

3. ��ӡ�û������
ude <unistd.h>
#include <stdlib.h>

int main(void) {
	char* p = malloc(sizeof(char) * 10);
	setvbuf(stdout, p, _IONBF, 10);
	printf("this is maomaochong");
	//fflush(stdout);
	sleep(3);
}

4. ��ӡ������**
#include <stdio.h>
#include <stdlib.h>


int main(void) {
	char buf[100] = { '#' };
	char* p = "|/-\\";
	int i;
	for (i = 0; i < 100; i++) {
		buf[i] = '#';
		printf("[% -100s][%d%%][%c]\r", buf, i + 1, p[i % 4]);
		fflush(stdout);
		usleep(500000);
	}
}

