~]# cd study
[root@luckily study]# ls
day01  day03  day05  day07  day09  day0b  day0d  day0f  day11
day02  day04  day06  day08  day0a  day0c  day0e  day10
[root@luckily study]# cd day11
[root@luckily day11]# ls
[root@luckily day11]# vim 01.c
[root@luckily day11]# gcc 01.c
01.c: �ں�����main����:
01.c : 15 : 39 : ���󣺡�O_TAUNC��δ����(�ڴ˺����ڵ�һ��ʹ��)
int fd = open("tmp.txt", O_RDWR | O_CREAT | O_TAUNC, 0644);
^
01.c:15 : 39 : ��ע��ÿ��δ�����ı�ʶ��������ֵĺ�����ֻ����һ��
In file included from / usr / include / sys / mman.h : 41 : 0,
from 01.c : 5 :
	01.c : 18 : 79 : ����expected identifier before numeric constant
	struct stu* p = (struct stu*)mmap(NULL, sizeof(struct stu), PROT_READ | PROT_WRITE.MAP_SHARED, fd, 0);
^
01.c:18 : 79 : �����ṩ��������mmap����ʵ��̫��
In file included from 01.c : 5 : 0 :
	/ usr / include / sys / mman.h : 57 : 14 : ��ע���ڴ�����
	extern void* mmap(void* __addr, size_t __len, int __prot,
		^
		[root@luckily day11]# :wq
		bash : : wq : δ�ҵ�����...
		[root@luckily day11]# vim 01.c
		[root@luckily day11]# gcc 01.c
		[root@luckily day11]# . / a.out
		���ߴ���(�º�)
		[root@luckily day11]# kill - l
		1) SIGHUP	 2) SIGINT	 3) SIGQUIT	 4) SIGILL	 5) SIGTRAP
		6) SIGABRT	 7) SIGBUS	 8) SIGFPE	 9) SIGKILL	10) SIGUSR1
		11) SIGSEGV	12) SIGUSR2	13) SIGPIPE	14) SIGALRM	15) SIGTERM
		16) SIGSTKFLT	17) SIGCHLD	18) SIGCONT	19) SIGSTOP	20) SIGTSTP
		21) SIGTTIN	22) SIGTTOU	23) SIGURG	24) SIGXCPU	25) SIGXFSZ
		26) SIGVTALRM	27) SIGPROF	28) SIGWINCH	29) SIGIO	30) SIGPWR
		31) SIGSYS	34) SIGRTMIN	35) SIGRTMIN + 1	36) SIGRTMIN + 2	37) SIGRTMIN + 3
		38) SIGRTMIN + 4	39) SIGRTMIN + 5	40) SIGRTMIN + 6	41) SIGRTMIN + 7	42) SIGRTMIN + 8
		43) SIGRTMIN + 9	44) SIGRTMIN + 10	45) SIGRTMIN + 11	46) SIGRTMIN + 12	47) SIGRTMIN + 13
		48) SIGRTMIN + 14	49) SIGRTMIN + 15	50) SIGRTMAX - 14	51) SIGRTMAX - 13	52) SIGRTMAX - 12
		53) SIGRTMAX - 11	54) SIGRTMAX - 10	55) SIGRTMAX - 9	56) SIGRTMAX - 8	57) SIGRTMAX - 7
		58) SIGRTMAX - 6	59) SIGRTMAX - 5	60) SIGRTMAX - 4	61) SIGRTMAX - 3	62) SIGRTMAX - 2
		63) SIGRTMAX - 1	64) SIGRTMAX
		[root@luckily day11]# vim 01.v
	[root@luckily day11]# rm - rf 01.v
	[root@luckily day11]# vim 01.c
	[root@luckily day11]# gcc 01.c
	[root@luckily day11]# . / a.out
	[root@luckily day11]# ls - l tmp.txt
	- rw - r--r--. 1 root root 36 6��  29 17:03 tmp.txt
	[root@luckily day11]# od - c tmp.txt
	0000000 001  \0  \0  \0   z   h   a   n   g   s   a   n  \0  \0  \0  \0
	0000020  \0  \0  \0  \0  \0  \0  \0  \0  \0  \0  \0  \0  \0  \0  \0  \0
	0000040  \0  \0  \0  \0
	0000044
	[root@luckily day11]# vim 01.c
	[root@luckily day11]# car 01.c
	bash : car: δ�ҵ�����...
	���������ǣ� 'sar'
	[root@luckily day11]# cat 01.c
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/mman.h>
#include <fcntl.h>

	//�����ڴ�
	struct stu {
	int id;
	char name[32];
};

int main(void) {
	int fd = open("tmp.txt", O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (fd == -1) perror("open"), exit(1);

	struct stu* p = (struct stu*)mmap(NULL, sizeof(struct stu), PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
	ftruncate(fd, sizeof(struct stu));
	p->id = 1;
	strcpy(p->name, "zhangsan");
	munmap(p, sizeof(struct stu));

	close(fd);
}

[root@luckily day11]# vim 02.c
[root@luckily day11]# vim 02.c
[root@luckily day11]# rm 02.c
rm���Ƿ�ɾ����ͨ�ļ� "02.c"��y
[root@luckily day11]# vim 02.c
[root@luckily day11]# gcc 02.c
[root@luckily day11]# . / a.out
p->id = 1, p->name = zhangsan
[root@luckily day11]# vim shmcreate.c
[root@luckily day11]# gcc shmcreate.c - o shmcreate
[root@luckily day11]# . / shmcreate
create shared memory ok
[root@luckily day11]# ipcs - m

------------�����ڴ��--------------
��        shmid      ӵ����  Ȩ��     �ֽ�     nattch     ״̬
0x00000000 294912     root       777        16384      1          Ŀ��
0x00000000 327681     root       777        2129920    2          Ŀ��
0x00000000 557058     root       777        2129920    2          Ŀ��
0x00000000 524291     root       600        524288     2          Ŀ��
0x00000000 655364     root       600        524288     2          Ŀ��
0x00000000 786437     root       600        16777216   2          Ŀ��
0x00000000 819206     root       600        524288     2          Ŀ��
0x00000000 851975     root       777        1916928    2          Ŀ��
0x00000000 884744     root       600        524288     2          Ŀ��
0x000004d2 1015817    root       644        4          0

[root@luckily day11]# 
