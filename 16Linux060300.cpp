[root@luckily ~]# cd study
[root@luckily study]# cd day0c
[root@luckily day0c]# ls
01.1.c  01.c  a.out
[root@luckily day0c]# vim 01.1.c
[root@luckily day0c]# gcc 01.1.c
01.1.c: �ں�����main����:
01.1.c : 29 : 3 : ����expected ��; �� before ��printf��
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
[1] + ��ֹͣ               . / a.out
[root@luckily day0c]# 
[root@luckily day0c]# . / a.out
row = 26, col = 87
row = 26, col = 87
^ Ccatch 2
^ C ^ C ^ C ^ C ^ C ^ C ^ C ^ C ^ C ^ C ^ Chandler end
catch 2
^ C ^ C ^ C ^ C ^ C ^ C ^ C ^ Z
[2] + ��ֹͣ               . / a.out
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
02.c: �ں�����main����:
02.c : 13 : 7 : ���󣺡�ppid��δ����(�ڴ˺����ڵ�һ��ʹ��)
kill(ppid, SIGKILL);
^
02.c:13 : 7 : ��ע��ÿ��δ�����ı�ʶ��������ֵĺ�����ֻ����һ��
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
04.c:39 : 2 : ����expected identifier or ��(�� before ��}�� token
  }
  ^
      04.c:40 : 1 : ����expected identifier or ��(�� before ��}�� token
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
     ������̫���ˣ�V = 9, X = 0[root@luckily day0c]# . / a.out
     8 + 3 = 12
     1 + 7 = 8
     9 + 1 = 10
     2 + 5 = time outV = 2, X = 1[root@luckily day0c]# vim 05.v
     [root@luckily day0c]# vim 04.c
     [root@luckily day0c]# vim 05.v
     [root@luckily day0c]# vim 05.v
     [root@luckily day0c]# gcc 05.c
     gcc : ����05.c��û���Ǹ��ļ���Ŀ¼
     gcc : ��������û�������ļ�
     �����жϡ�
     [root@luckily day0c]# vim 05.c
     [root@luckily day0c]# vim 04.c
     [root@luckily day0c]# ls
     01.1.c  01.2.c  01.c  02.c  03.c  04.c  05.c  05.v  a.out  mykill
     [root@luckily day0c]# vim 05.v
     [root@luckily day0c]# vim 05.c
     [root@luckily day0c]# rm 05.c
     rm���Ƿ�ɾ����ͨ���ļ� "05.c"��y
     [root@luckily day0c]# mv 05.v 05.c
     [root@luckily day0c]# ls
     01.1.c  01.2.c  01.c  02.c  03.c  04.c  05.c  a.out  mykill
     [root@luckily day0c]# gcc 05.c
     05.c: �ں�����main����:
 05.c : 14 : 19 : ����expected identifier or ��(�� before ��if��
     struct itimerval if;
 ^
     05.c:15 : 2 : ���󣺡�it��δ����(�ڴ˺����ڵ�һ��ʹ��)
     it.it_value.tv_sec = 0;
 ^
     05.c:15 : 2 : ��ע��ÿ��δ�����ı�ʶ��������ֵĺ�����ֻ����һ��
     05.c : 20 : 12 : ���󣺡�ITIMER_REAL��δ����(�ڴ˺����ڵ�һ��ʹ��)
     setitimer(ITIMER_REAL, &if, NULL);
 ^
     05.c:20 : 25 : ����expected expression before ��if��
     setitimer(ITIMER_REAL, &if, NULL);
 ^
     [root@luckily day0c]# vim 05.c
     [root@luckily day0c]# gcc 05.c
     05.c: �ں�����main����:
 05.c : 14 : 19 : ���󣺡�it���Ĵ洢��Сδ֪
     struct itimerval it;
 ^
     05.c:20 : 12 : ���󣺡�ITIMER_REAL��δ����(�ڴ˺����ڵ�һ��ʹ��)
     setitimer(ITIMER_REAL, &it, NULL);
 ^
     05.c:20 : 12 : ��ע��ÿ��δ�����ı�ʶ��������ֵĺ�����ֻ����һ��
     [root@luckily day0c]# vim 05.c
     [root@luckily day0c]# gcc 05.c
     05.c: �ں�����main����:
 05.c : 17 : 13 : ���󣺡�struct timeval��û����Ϊ��tv_user���ĳ�Ա
     it.it_value.tv_user = 1;
 ^
     05.c:18 : 16 : ���󣺡�struct timeval��û����Ϊ��tv���ĳ�Ա
     it.it_interval.tv.sec = 2;
 ^
     [root@luckily day0c]# vim 05.c
     [root@luckily day0c]# vim 05.c
     [root@luckily day0c]# gcc 05.c
     [root@luckily day0c]# 
