tudy: 未找到命令...
[root@luckily ~]# cd stuyd
bash : cd: stuyd: 没有那个文件或目录
[root@luckily ~]# cd  study
[root@luckily study]# ls
day01  day03  day05  day07  day09  day0b  day0d  day0f
day02  day04  day06  day08  day0a  day0c  day0e
[root@luckily study]# time ls - l
总用量 0
drwxr - xr - x. 2 root root  67 4月  25 10:26 day01
drwxr - xr - x. 3 root root  83 4月  28 17 : 40 day02
drwxr - xr - x. 2 root root  74 5月   3 17 : 03 day03
drwxr - xr - x. 2 root root  83 5月  13 23 : 19 day04
drwxr - xr - x. 2 root root 138 5月  22 20 : 02 day05
drwxr - xr - x. 2 root root 118 5月  22 23 : 11 day06
drwxr - xr - x. 2 root root 126 5月  23 23 : 06 day07
drwxr - xr - x. 2 root root 189 5月  28 13 : 50 day08
drwxr - xr - x. 2 root root 143 5月  31 23 : 16 day09
drwxr - xr - x. 7 root root 149 6月   5 14 : 31 day0a
drwxr - xr - x. 3 root root 146 6月   7 17 : 32 day0b
drwxr - xr - x. 2 root root 204 6月  15 14 : 34 day0c
drwxr - xr - x. 2 root root  79 6月  15 23 : 27 day0d
drwxr - xr - x. 2 root root  55 6月  18 13 : 07 day0e
drwxr - xr - x. 2 root root  43 6月  19 18 : 21 day0f

real	0m0.009s
user	0m0.001s
sys	0m0.007s
[root@luckily study]# man time
[root@luckily study]# mkdir day10
[root@luckily study]# cd day10
[root@luckily day10]# ls
[root@luckily day10]# vim 01.c
[root@luckily day10]# gcc 01.c
[root@luckily day10]# . / a.out
hehe
hehe2
hehe2
段错误(吐核)
[root@luckily day10]# vim 01.c
[root@luckily day10]# vim 01.c
[root@luckily day10]# vim msgcreate.c
[root@luckily day10]# gcc msgcreate.c
[root@luckily day10]# . / a.out
creat ok
[root@luckily day10]# ipcs - q

-------- - 消息队列---------- -
键        msqid      拥有者  权限     已用字节数 消息
0x000004d2 0          root       644        0            0

[root@luckily day10]# ipcrm - Q 1234
[root@luckily day10]# . / a.out
creat ok
[root@luckily day10]# vim msgsnd.c
[root@luckily day10]# cat msgcreate.c
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/msg.h>

int main(void) {
    int id = msgget(1234, IPC_CREAT | 0644);
    if (id == -1) {
        perror("msgget"), exit(1);
    }
    printf("creat ok\n");
}
[root@luckily day10]# vim msgsnd.c
[root@luckily day10]# gcc msgsnd.c - osnd
msgsnd.c:13 : 1 : 错误：expected ‘; ’, identifier or ‘(’ before ‘int’
    int main(void) {
    ^
        msgsnd.c:31 : 1 : 错误：expected identifier or ‘(’ before ‘
}’ token
 }
 ^
     [root@luckily day10]# vim msgsnd.c
     [root@luckily day10]# gcc msgsnd.c - osnd
     msgsnd.c:13 : 1 : 错误：expected ‘; ’, identifier or ‘(’ before ‘int’
         int main(void) {
     ^
         [root@luckily day10]# vim msgsnd.c
         [root@luckily day10]# gcc msgsnd.c - osnd
         [root@luckily day10]# . / snd
         channel : ^ C
         [root@luckily day10]# vim msgsnd.c
         [root@luckily day10]# gcc msgsnd.c - osnd
         [root@luckily day10]# . / snd
         channel : 5
         msg : this is
         [root@luckily day10]# ipcs - q

         -------- - 消息队列---------- -
         键        msqid      拥有者  权限     已用字节数 消息
         0x000004d2 32768      root       644        8            1

         [root@luckily day10]# vim msgrcv.c
         [root@luckily day10]# vim msgrcv.c
         [root@luckily day10]# gcc msgrcv.c - o rcv
         [root@luckily day10]# . / rcv
         channel : 3
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/msg.h>

         int main(void) {
         int id = msgget(1234, IPC_CREAT | 0644);
         if (id == -1) {
             perror("msgget"), exit(1);
         }
         printf("creat ok\n");
     }
     ^ C
         [root@luckily day10]# . / rcv
         channel : 5
         [this is
         ]
     [root@luckily day10]# ipcs - q

         -------- - 消息队列---------- -
         键        msqid      拥有者  权限     已用字节数 消息
         0x000004d2 32768      root       644        0            0

         [root@luckily day10]# ls - l / proc / sys / kernel / msg *
         -rw - r--r--. 1 root root 0 6月  20 22:49 / proc / sys / kernel / msgmax
         - rw - r--r--. 1 root root 0 6月  20 22 : 49 / proc / sys / kernel / msgmnb
         - rw - r--r--. 1 root root 0 6月  20 22 : 49 / proc / sys / kernel / msgmni
         - rw - r--r--. 1 root root 0 6月  20 22 : 49 / proc / sys / kernel / msg_next_id
         [root@luckily day10]# cat / proc / sys / kernel / msgmax
         8192
         [root@luckily day10]# cat / proc / sys / kernel / msgmnb
         16384
         [root@luckily day10]# cat / proc / sys / kernel / msgmni
         3633
         [root@luckily day10]# vim msgrcv.c
         [root@luckily day10]# vim msgsnd.c
         [root@luckily day10]# vim client.c
         [root@luckily day10]# vim client.c
         [root@luckily day10]# gcc client.c - ocli
         client.c: 在函数‘main’中:
     client.c : 17 : 12 : 警告：初始化将指针赋给整数，未作类型转换[默认启用]
         pid_t pid = getpid;
     ^
         client.c:25 : 35 : 错误：‘text’未声明(在此函数内第一次使用)
         msgsnd(id, &sndbuf, strlen(sndbuf, text + sizeof(pid_t)) + sizeof(pis_t), 0);
     ^
         client.c:25 : 35 : 附注：每个未声明的标识符在其出现的函数内只报告一次
         client.c : 25 : 3 : 错误：‘strlen’的第 1 个实参类型不兼容
         msgsnd(id, &sndbuf, strlen(sndbuf, text + sizeof(pid_t)) + sizeof(pis_t), 0);
     ^
         In file included from client.c:3 : 0 :
         / usr / include / string.h : 395 : 15 : 附注：需要类型‘const char* ’，但实参的类型为‘struct msgbuf’
         extern size_t strlen(const char* __s)
         ^
         client.c : 25 : 3 : 错误：提供给函数‘strlen’的实参太多
         msgsnd(id, &sndbuf, strlen(sndbuf, text + sizeof(pid_t)) + sizeof(pis_t), 0);
     ^
         client.c:25 : 62 : 错误：‘pis_t’未声明(在此函数内第一次使用)
         msgsnd(id, &sndbuf, strlen(sndbuf, text + sizeof(pid_t)) + sizeof(pis_t), 0);
     ^
         [root@luckily day10]# vim client.c
         [root@luckily day10]# gcc client.c - ocli
         client.c: 在函数‘main’中:
     client.c : 25 : 35 : 错误：‘text’未声明(在此函数内第一次使用)
         msgsnd(id, &sndbuf, strlen(sndbuf, text + sizeof(pid_t)) + sizeof(pid_t), 0);
     ^
         client.c:25 : 35 : 附注：每个未声明的标识符在其出现的函数内只报告一次
         client.c : 25 : 3 : 错误：‘strlen’的第 1 个实参类型不兼容
         msgsnd(id, &sndbuf, strlen(sndbuf, text + sizeof(pid_t)) + sizeof(pid_t), 0);
     ^
         In file included from client.c:3 : 0 :
         / usr / include / string.h : 395 : 15 : 附注：需要类型‘const char* ’，但实参的类型为‘struct msgbuf’
         extern size_t strlen(const char* __s)
         ^
         client.c : 25 : 3 : 错误：提供给函数‘strlen’的实参太多
         msgsnd(id, &sndbuf, strlen(sndbuf, text + sizeof(pid_t)) + sizeof(pid_t), 0);
     ^
         [root@luckily day10]# vim client.c
         [root@luckily day10]# gcc client.c - ocli
         [root@luckily day10]# vim server.c
         [root@luckily day10]# gcc server.c - oser
         [root@luckily day10]# ipcs - Q 1234
         ipcs：无效选项 -- Q

         用法：
         ipcs[resource ...][output - format]
         ipcs[resource] - i <id>

         选项：
         - i, --id <id>  打印由 id 标识的资源的详细信息
         - h, --help     显示此帮助并退出
         - V, --version  输出版本信息并退出

         资源选项：
         - m, --shmems      共享内存段
         - q, --queues      消息队列
         - s, --semaphores  信号量
         - a, --all         全部(默认)

         输出格式：
         - t, --time        显示附加、脱离和更改时间
         - p, --pid         显示 PID 的创建者和最后操作
         - c, --creator     显示创建者和拥有者
         - l, --limits      显示资源限制
         - u, --summary     显示状态摘要
         --human       以易读格式显示大小
         - b, --bytes       以字节数显示大小

         更多信息请参阅 ipcs(1)。
         [root@luckily day10]# ipcrm - Q 1234
         [root@luckily day10]# vim rmipc.c
         [root@luckily day10]# gcc rmipc.c - o rmipc
         [root@luckily day10]# ls
         01.c   cli       msgcreate.c  msgsnd.c  rmipc    ser       snd
         a.out  client.c  msgrcv.c     rcv       rmipc.c  server.c
         [root@luckily day10]# . / a.out
         creat ok
         [root@luckily day10]# ipcs - q

         -------- - 消息队列---------- -
         键        msqid      拥有者  权限     已用字节数 消息
         0x000004d2 65536      root       644        0            0

         [root@luckily day10]# . / rmipc
         [root@luckily day10]# ipcs - q

         -------- - 消息队列---------- -
         键        msqid      拥有者  权限     已用字节数 消息

         [root@luckily day10]# cat cli

[root@luckily day10]# cat client.c
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/msg.h>

struct msgbuf {
	long type;
	char text[100];
};

int main(void) {
	int id = msgget(1234, 0);
	struct msgbuf sndbuf;
	struct msgbuf rcvbuf;
	pid_t pid = getpid();

	while (1) {
		memset(&sndbuf, 0x00, sizeof(sndbuf));
		memset(&rcvbuf, 0x00, sizeof(rcvbuf));
		sndbuf.type = 1;
		*(pid_t*)(sndbuf.text) = pid;
		fgets(sndbuf.text + sizeof(pid_t), 100 - sizeof(pid_t), stdin);
		msgsnd(id, &sndbuf, strlen(sndbuf.text + sizeof(pid_t)) + sizeof(pid_t), 0);

		msgrcv(id, &rcvbuf, 100, pid, 0);
		printf("==> %s\n", rcvbuf.text + sizeof(pid_t));
	}
}

[root@luckily day10]# ls
01.c   cli       msgcreate.c  msgsnd.c  rmipc    ser       snd
a.out  client.c  msgrcv.c     rcv       rmipc.c  server.c
[root@luckily day10]# vim server.c
[root@luckily day10]# gcc server.c - oser
[root@luckily day10]# vim server.c
[root@luckily day10]# gcc server.c - oser
[root@luckily day10]# . / ser
^ C[root@luckily day10]# ipcs - q

-------- - 消息队列---------- -
键        msqid      拥有者  权限     已用字节数 消息
0x000004d2 98304      root       644        0            0

[root@luckily day10]# . / ser
s
^ C[root@luckily day10]# ipcs - q

-------- - 消息队列---------- -
键        msqid      拥有者  权限     已用字节数 消息
0x000004d2 98304      root       644        0            0

[root@luckily day10]# vim server.c
[root@luckily day10]# gcc server.c - oser
[root@luckily day10]# . / ser
^ C[root@luckily day10]# ipcs - q

-------- - 消息队列---------- -
键        msqid      拥有者  权限     已用字节数 消息
0x000004d2 98304      root       644        0            0

[root@luckily day10]# . / rmipc
[root@luckily day10]# ipcs - q

-------- - 消息队列---------- -
键        msqid      拥有者  权限     已用字节数 消息

[root@luckily day10]# vim server.c
[root@luckily day10]# vim rmipc.c
[root@luckily day10]# vim server.c
[root@luckily day10]# . / ser
^ C[root@luckily day10]# ipcs - q

-------- - 消息队列---------- -
键        msqid      拥有者  权限     已用字节数 消息
0x000004d2 131072     root       644        0            0

[root@luckily day10]# 
