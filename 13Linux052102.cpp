[root@luckily ~]# cd study
[root@luckily study]# cls
bash : cls: Œ¥’“µΩ√¸¡Ó...
[root@luckily study]# ls
day01  day02  day03  day04  day05  day06  day07  day08
[root@luckily study]# mkdir day09
[root@luckily study]# cd day09
[root@luckily day09]# vim 01.c
[root@luckily day09]# echo "abcdefghijklmnopqrstuvwxyz" > test.txt
[root@luckily day09]# vim test.txt
[root@luckily day09]# vim 01.c
[root@luckily day09]# gcc 01.c
[root@luckily day09]# . / a.out
buf1 = [abcdefghij]
buf2 = [abcdefghij]
[root@luckily day09]# vim 01.c
[root@luckily day09]# gcc 01.c
[root@luckily day09]# . / a.out
buf1 = [abcdefghij]
buf2 = [abcdefghij]
buf1 = [AAAAAp]
[root@luckily day09]# vim 01.c
[root@luckily day09]# vim 01.c
[root@luckily day09]# 
[root@luckily ~]# cd study
[root@luckily study]# cd day08
[root@luckily day08]# ls
a.out            hehe.c  mycopy.c          review.c  Studest.c  tmp.txt
close_on_exec.c  mycopy  open_for_write.c  stu.dat   test.txt
[root@luckily day08]# cd ..
[root@luckily study]# ls
day01  day02  day03  day04  day05  day06  day07  day08  day09
[root@luckily study]# cd day09
[root@luckily day09]# ls
01.c  a.out  test.txt
[root@luckily day09]# vim 02.c
[root@luckily day09]# gcc 02.c
[root@luckily day09]# . / a.out
buf = [efghi]
[root@luckily day09]# cat test.txt
XXXXefghijAAAAApqrstuvwxyz
[root@luckily day09]# vim 02.c
[root@luckily day09]# gcc 02.c
[root@luckily day09]# . / a.out
buf = [efghi]
^ [^ C
[root@luckily day09]# vim 02.c
[root@luckily day09]# gcc 02.c
[root@luckily day09]# vim 02.c
[root@luckily day09]# gcc 02.c
[root@luckily day09]# . / a.out
buf = [efghi]
^ C
[root@luckily day09]# 
root@luckily day09]# ps - ef | grep a.out
root       4021   2999  0 17:02 pts / 0    00 : 00 : 00 . / a.out
root       4068   4026  0 17 : 02 pts / 1    00 : 00 : 00 grep --color = auto a.out
[root@luckily day09]#  ^ C
[root@luckily day09]# 
[root@luckily day09]# man lsao
√ª”– lsao µƒ ÷≤·“≥Ãıƒø
[root@luckily day09]# man lsof
[root@luckily day09]# ps - ef | grap a.out
bash : grap: Œ¥’“µΩ√¸¡Ó...
[root@luckily day09]# ps - ef | grep a.out
root       4149   2999  0 17:04 pts / 0    00 : 00 : 00 grep --color = auto a.out
[root@luckily day09]# ps - ef | grep a.out
root       4209   4159  0 17:04 pts / 1    00 : 00 : 00 . / a.out
root       4212   2999  0 17 : 05 pts / 0    00 : 00 : 00 grep --color = auto a.out
[root@luckily day09]# lsof - p 4209
COMMAND  PID USER   FD   TYPE DEVICE SIZE / OFF     NODE NAME
a.out   4209 root  cwd    DIR  253, 3       59 10493077 / root / study / day09
a.out   4209 root  rtd    DIR  253, 3      237      128 /
a.out   4209 root  txt    REG  253, 3     8760 10493113 / root / study / day09 / a.out
a.out   4209 root  mem    REG  253, 3  2156160  8399249 / usr / lib64 / libc - 2.17.so
a.out   4209 root  mem    REG  253, 3   163400  8399242 / usr / lib64 / ld - 2.17.so
a.out   4209 root    0u   CHR  136, 1      0t0        4 / dev / pts / 1
a.out   4209 root    1u   CHR  136, 1      0t0        4 / dev / pts / 1
a.out   4209 root    2u   CHR  136, 1      0t0        4 / dev / pts / 1
a.out   4209 root    3u   REG  253, 3       27 10494719 / root / study / day09 / test.txt
[root@luckily day09]# vim 03.c
[root@luckily day09]# man 2 dup
[root@luckily day09]# ls
01.c  02.c  03.c  a.out  test.txt
[root@luckily day09]# vim 04.c
[root@luckily day09]# cat 03.c
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void) {
	int fd = open("test.txt", O_RDWR);
	char buf[5] = {};
	read(fd, buf, 4);
	printf("buf=[%s]\n", buf);
	close(fd);
	getchar();
}
[root@luckily day09]# vim 04.c
[root@luckily day09]# gcc 04.c
[root@luckily day09]# ps - ef
root       6034      1  0 20:01 ? 00 : 00 : 00 / usr / sbin / abrt - dbus - t133
root       6061   6020  0 20 : 02 pts / 1    00 : 00 : 00 . / a.out
root       6069    918  0 20 : 02 ? 00 : 00 : 00 sleep 60
root       6070      2  0 20 : 02 ? 00 : 00 : 00[kworker / 2:3]
root       6071   2999  0 20 : 02 pts / 0    00 : 00 : 00 ps - ef
[root@luckily day09]# lsof - p 6061
COMMAND  PID USER   FD   TYPE DEVICE SIZE / OFF     NODE NAME
a.out   6061 root  cwd    DIR  253, 3       83 10493077 / root / study / day09
a.out   6061 root  rtd    DIR  253, 3      237      128 /
a.out   6061 root  txt    REG  253, 3     8664 10493113 / root / study / day09 / a.out
a.out   6061 root  mem    REG  253, 3  2156160  8399249 / usr / lib64 / libc - 2.17.so
a.out   6061 root  mem    REG  253, 3   163400  8399242 / usr / lib64 / ld - 2.17.so
a.out   6061 root    0u   CHR  136, 1      0t0        4 / dev / pts / 1
a.out   6061 root    1u   CHR  136, 1      0t0        4 / dev / pts / 1
a.out   6061 root    2u   CHR  136, 1      0t0        4 / dev / pts / 1
a.out   6061 root    3u   REG  253, 3       27 10494719 / root / study / day09 / test.txt
a.out   6061 root    4u   REG  253, 3       27 10494719 / root / study / day09 / test.txt
[root@luckily day09]# lsof - p 6061
COMMAND  PID USER   FD   TYPE DEVICE SIZE / OFF     NODE NAME
a.out   6061 root  cwd    DIR  253, 3       83 10493077 / root / study / day09
a.out   6061 root  rtd    DIR  253, 3      237      128 /
a.out   6061 root  txt    REG  253, 3     8664 10493113 / root / study / day09 / a.out
a.out   6061 root  mem    REG  253, 3  2156160  8399249 / usr / lib64 / libc - 2.17.so
a.out   6061 root  mem    REG  253, 3   163400  8399242 / usr / lib64 / ld - 2.17.so
a.out   6061 root    0u   CHR  136, 1      0t0        4 / dev / pts / 1
a.out   6061 root    1u   CHR  136, 1      0t0        4 / dev / pts / 1
a.out   6061 root    2u   CHR  136, 1      0t0        4 / dev / pts / 1
a.out   6061 root    4u   REG  253, 3       27 10494719 / root / study / day09 / test.txt
[root@luckily day09]# cat test.txt
ZZXXefghijAAAAApqrstuvwxyz
[root@luckily day09]# echo "this is maomaochong"
this is maomaochong
[root@luckily day09]# echo "this is maomaochong" > test.txt
[root@luckily day09]# cat 04.c
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/wait.h>


int main(void) {
	int fd = open("test.txt", O_RDWR);
	printf("fd=%d\n", fd);
	int newfd = dup(fd);
	printf("before close(fd)\n");
	getchar();
	close(fd);
	printf("after close(fd)\n");
	getchar();
	printf("newfd=%d\n", newfd);

	write(newfd, "ZZ", 2);
}
[root@luckily day09]# 

[root@luckily ~]# cd study
[root@luckily study]# cd day09
[root@luckily day09]# vim 05.c
[root@luckily day09]# ls
01.c  02.c  03.c  04.c  05.c  a.out  test.txt
[root@luckily day09]# vim ttt.c
[root@luckily day09]# vim ttt.c
[root@luckily day09]# vim ttt.c
[root@luckily day09]# vim 06.c
[root@luckily day09]# vim t
test.txt  ttt.c
[root@luckily day09]# vim t
test.txt  ttt.c
[root@luckily day09]# vim ttt.c
[root@luckily day09]# gcc ttt.c
[root@luckily day09]# gcc ttt.c - ottt
[root@luckily day09]# . / ttt
hello world!


[root@luckily day09]# vim 06.c
[root@luckily day09]# gcc 06.c
06.c:12 : 1 : ¥ÌŒÛ£∫expected identifier or °Æ(°Ø before °Æ~°Ø token
	~
	^
	[root@luckily day09]# :wq
	bash : : wq : Œ¥’“µΩ√¸¡Ó...
	[root@luckily day09]# vim 06.c
	[root@luckily day09]# gcc 06.c
	[root@luckily day09]# . / a.out
	hehe
	hello world!


	[root@luckily day09]# vim 06.c
	[root@luckily day09]# vim 07.c
	[root@luckily day09]# vim 06.c
	[root@luckily day09]# vim 07.c
	[root@luckily day09]# gcc 07.c
	[root@luckily day09]# . / a.out
	123
	buf = [123
	]
	[root@luckily day09]# vim 07.c
	[root@luckily day09]# gcc 07.c
	[root@luckily day09]# . / a.out
	read : Resource temporarily unavailable
	[root@luckily day09]# vim 07.c
	[root@luckily day09]# . / a.out < test.txt
	buf = [this is maomaochong
	]
	[root@luckily day09]# vim 07.c
	[root@luckily day09]# 

