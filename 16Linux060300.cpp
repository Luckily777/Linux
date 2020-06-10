[root@luckily ~]# cd study
[root@luckily study]# cd day0c
[root@luckily day0c]# ls
01.1.c  01.c  a.out
[root@luckily day0c]# vim 01.1.c
[root@luckily day0c]# gcc 01.1.c
01.1.c: 在函数‘main’中:
01.1.c : 29 : 3 : 错误：expected ‘; ’ before ‘printf’
printf("row=%d,col=%d\n", w.ws_row, w.ws_col);
^
[root@luckily day0c]# vim 01.1.c
[root@luckily day0c]# gcc 01.1.c
[root@luckily day0c]# . / a.out
row = 26, col = 87
row = 26, col = 87
row = 26, col = 87
row = 26, col = 87
Window changed
row = 46, col = 189
Window changed
row = 44, col = 189
row = 44, col = 189
row = 44, col = 189
row = 44, col = 189
Window changed
row = 28, col = 87
Window changed
row = 26, col = 87
row = 26, col = 87
row = 26, col = 87
row = 26, col = 87
^ Ccatch 2
handler end
row = 26, col = 87
row = 26, col = 87
eixrow = 26, col = 87
t
row = 26, col = 87
row = 26, col = 87
row = 26, col = 87
row = 26, col = 87
row = 26, col = 87
^ Z
[1] + 已停止               . / a.out
[root@luckily day0c]# 
[root@luckily day0c]# . / a.out
row = 26, col = 87
row = 26, col = 87
^ Ccatch 2
^ C ^ C ^ C ^ C ^ C ^ C ^ C ^ C ^ C ^ C ^ Chandler end
catch 2
^ C ^ C ^ C ^ C ^ C ^ C ^ C ^ Z
[2] + 已停止               . / a.out
[root@luckily day0c]#  ^ C
[root@luckily day0c]# 
[root@luckily ~]# cd study
[root@luckily study]# ls
day01  day02  day03  day04  day05  day06  day07  day08  day09  day0a  day0b  day0c
[root@luckily study]# cd day03
[root@luckily day03]# cd ..
[root@luckily study]# cd day0c
[root@luckily day0c]# ls
01.1.c  01.c  a.out
[root@luckily day0c]# vim 01.1.c
[root@luckily day0c]# vim 01.2.c
[root@luckily day0c]# vim 01.1.c
[root@luckily day0c]# vim 01.2.c
[root@luckily day0c]# vim 01.2.c
[root@luckily day0c]# vim 02.c
[root@luckily day0c]# gcc 02.c - o mykill
02.c: 在函数‘main’中:
02.c : 13 : 7 : 错误：‘ppid’未声明(在此函数内第一次使用)
kill(ppid, SIGKILL);
^
02.c:13 : 7 : 附注：每个未声明的标识符在其出现的函数内只报告一次
[root@luckily day0c]# vim 02.c
[root@luckily day0c]# gcc 02.c - o mykill
[root@luckily day0c]# cat 02.c
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
[root@luckily day0c]# vim 03.c

[root@luckily day0c]# . / a.out
num : 1
$.$.$.$.$.$.$.$.$.$.$$$$$$$$$$$$$$$$$$$$$$$$$$$$$ ^ C
[root@luckily day0c]# 



[root@luckily day0c]# ps - ef
root       3635   3583  0 17:18 pts / 1    00 : 00 : 00 . / a.out
root       3641   3004  0 17 : 19 pts / 0    00 : 00 : 00 ps - ef
[root@luckily day0c]# ps - ef | grep a.out | grep - v grep
root       3635   3583  0 17:18 pts / 1    00 : 00 : 00 . / a.out
[root@luckily day0c]# 
ot@luckily day0c]# gcc 04.c
04.c:39 : 2 : 错误：expected identifier or ‘(’ before ‘}’ token
  }
  ^
      04.c:40 : 1 : 错误：expected identifier or ‘(’ before ‘}’ token
 }
 ^
     [root@luckily day0c]# vim 04.c
     [root@luckily day0c]# gcc 04.c
     [root@luckily day0c]# . / a.out
     0 + 6 = 6
     8 + 8 = 16
     3 + 7 = 10
     0 + 1 = 1
     6 + 4 = 10
     2 + 6 = 8
     7 + 9 = 16
     4 + 9 = 13
     2 + 9 = 11
     你作的太快了，V = 9, X = 0[root@luckily day0c]# . / a.out
     8 + 3 = 12
     1 + 7 = 8
     9 + 1 = 10
     2 + 5 = time outV = 2, X = 1[root@luckily day0c]# vim 05.v
     [root@luckily day0c]# vim 04.c
     [root@luckily day0c]# vim 05.v
     [root@luckily day0c]# vim 05.v
     [root@luckily day0c]# gcc 05.c
     gcc : 错误：05.c：没有那个文件或目录
     gcc : 致命错误：没有输入文件
     编译中断。
     [root@luckily day0c]# vim 05.c
     [root@luckily day0c]# vim 04.c
     [root@luckily day0c]# ls
     01.1.c  01.2.c  01.c  02.c  03.c  04.c  05.c  05.v  a.out  mykill
     [root@luckily day0c]# vim 05.v
     [root@luckily day0c]# vim 05.c
     [root@luckily day0c]# rm 05.c
     rm：是否删除普通空文件 "05.c"？y
     [root@luckily day0c]# mv 05.v 05.c
     [root@luckily day0c]# ls
     01.1.c  01.2.c  01.c  02.c  03.c  04.c  05.c  a.out  mykill
     [root@luckily day0c]# gcc 05.c
     05.c: 在函数‘main’中:
 05.c : 14 : 19 : 错误：expected identifier or ‘(’ before ‘if’
     struct itimerval if;
 ^
     05.c:15 : 2 : 错误：‘it’未声明(在此函数内第一次使用)
     it.it_value.tv_sec = 0;
 ^
     05.c:15 : 2 : 附注：每个未声明的标识符在其出现的函数内只报告一次
     05.c : 20 : 12 : 错误：‘ITIMER_REAL’未声明(在此函数内第一次使用)
     setitimer(ITIMER_REAL, &if, NULL);
 ^
     05.c:20 : 25 : 错误：expected expression before ‘if’
     setitimer(ITIMER_REAL, &if, NULL);
 ^
     [root@luckily day0c]# vim 05.c
     [root@luckily day0c]# gcc 05.c
     05.c: 在函数‘main’中:
 05.c : 14 : 19 : 错误：‘it’的存储大小未知
     struct itimerval it;
 ^
     05.c:20 : 12 : 错误：‘ITIMER_REAL’未声明(在此函数内第一次使用)
     setitimer(ITIMER_REAL, &it, NULL);
 ^
     05.c:20 : 12 : 附注：每个未声明的标识符在其出现的函数内只报告一次
     [root@luckily day0c]# vim 05.c
     [root@luckily day0c]# gcc 05.c
     05.c: 在函数‘main’中:
 05.c : 17 : 13 : 错误：‘struct timeval’没有名为‘tv_user’的成员
     it.it_value.tv_user = 1;
 ^
     05.c:18 : 16 : 错误：‘struct timeval’没有名为‘tv’的成员
     it.it_interval.tv.sec = 2;
 ^
     [root@luckily day0c]# vim 05.c
     [root@luckily day0c]# vim 05.c
     [root@luckily day0c]# gcc 05.c
     [root@luckily day0c]# 
