//操作
oot@luckily ~]# cd study
[root@luckily study]# ls
day01  day03  day05  day07  day09  day0b  day0d
day02  day04  day06  day08  day0a  day0c  day0e
[root@luckily study]# ls - l
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
[root@luckily study]# cd study /
bash: cd: study / : 没有那个文件或目录
[root@luckily study]# cd ..
[root@luckily ~]# cd study
[root@luckily study]# cd ..
[root@luckily ~]# cd study /
[root@luckily study]# ls - l
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
[root@luckily study]# ls - l | wc - l
15
[root@luckily study]#  wc - l
s
s
w
e
f


sss
^ C
[root@luckily study]# ls
day01  day03  day05  day07  day09  day0b  day0d
day02  day04  day06  day08  day0a  day0c  day0e
[root@luckily study]# mkdir day0f
[root@luckily study]# cd day0f
[root@luckily day0f]# vim 01.c
[root@luckily day0f]# gcc 01.c
[root@luckily day0f]# . / a.out
buf = [0@]
[root@luckily day0f]# vim 01.c
[root@luckily day0f]# cat 01.c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(void) {
	int fds[2];
	pipe(fds);
	if (fork() == 0) {
		close(fds[0]);
		sleep(3);
		write(fds[1], "aaa", 3);
		close(fds[1]);
	}
	else {
		close(fds[1]);
		char buf[10];
		read(fds[0], buf, 10);
		printf("buf=[%s]\n", buf);
		close(fds[0]);
	}
}
[root@luckily day0f]# gcc 01.c
[root@luckily day0f]# . / a.out
buf = [aaa]
[root@luckily day0f]# vim 02.c
[root@luckily day0f]# gcc 02.c
[root@luckily day0f]# . / a.out
4
[root@luckily day0f]# ls - l | wc - l
4
[root@luckily day0f]# 
