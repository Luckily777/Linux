//第八节课的基本操作

[root@luckily ~]# cd study
[root@luckily study]# ls
day01  day02  day03  Linux
[root@luckily study]# mkdir day04
[root@luckily study]# ls
day01  day02  day03  day04  Linux
[root@luckily study]# cd day04
[root@luckily day04]# vim test.c
[root@luckily day04]# ls
test.c
[root@luckily day04]# rm test.c
rm：是否删除普通空文件 "test.c"？y
[root@luckily day04]# rm - f day04
[root@luckily day04]# ls
[root@luckily day04]# cd ..
[root@luckily study]# rm - f day04
rm : 无法删除"day04" : 是一个目录
[root@luckily study]# cd day04
[root@luckily day04]# vim test.c
[root@luckily day04]# gcc test.c
test.c: 在函数‘main’中:
test.c : 5 : 12 : 错误：expected identifier or ‘(’ before ‘ = ’ token
    const int = 10;
^
test.c:6 : 16 : 错误：‘a’未声明(在此函数内第一次使用)
int* p = (int*)&a;
^
test.c:6 : 16 : 附注：每个未声明的标识符在其出现的函数内只报告一次
[root@luckily day04]# vim test.c
[root@luckily day04]# gcc test.c
[root@luckily day04]# . / a.out
p = 11, a = 11
[root@luckily day04]# g++ test.c
[root@luckily day04]# . / a.out
p = 11, a = 10
[root@luckily day04]# cd ..
[root@luckily study]# ls
day01  day02  day03  day04  Linux
[root@luckily study]# cd Linux /
[root@luckily Linux]# ls
7Linux042901.cpp  7Linux042903.cpp  7Linux042905.cpp  SetNum.c
7Linux042902.cpp  7Linux042904.cpp  Linux050201.c
[root@luckily Linux]# vim 8Linux050701.cpp
[root@luckily Linux]# cd ..
[root@luckily study]# cd day04
[root@luckily day04]# ls
a.out  test.c
[root@luckily day04]# g++ test.cpp - S
g++: 错误：test.cpp：没有那个文件或目录
g++ : 致命错误：没有输入文件
编译中断。
[root@luckily day04]# gcc - S test.c
[root@luckily day04]# vim test.s
[root@luckily day04]# cd ..
[root@luckily study]# cd Linux /
[root@luckily Linux]# ls
7Linux042901.cpp  7Linux042903.cpp  7Linux042905.cpp  Linux050201.c
7Linux042902.cpp  7Linux042904.cpp  8Linux050701.cpp  SetNum.c
[root@luckily Linux]# vim 8Linux050702.cpp
[root@luckily Linux]# cd ..
[root@luckily study]# cd day04
[root@luckily day04]# vim test.c
[root@luckily day04]# cd ..
[root@luckily study]# cd Linux /
[root@luckily Linux]# vim 8Linux050702.cpp
[root@luckily Linux]# add 8Linux050702.cpp
bash : add: 未找到命令...
[root@luckily Linux]# git add 8Linux050702.cpp
[root@luckily Linux]# git commit.
git：'commit.' 不是一个 git 命令。参见 'git --help'。

您指的是这个么？
commit
[root@luckily Linux]# git commit .
[master 6da23a1] C语言和C++编译后，对于const的修改
1 file changed, 42 insertions(+)
create mode 100644 8Linux050702.cpp
[root@luckily Linux]# git push
fatal : unable to access 'https://github.com/Luckily777/Linux.git/' : Could not resolve host : github.com; Unknown error
[root@luckily Linux]# git push
fatal : unable to access 'https://github.com/Luckily777/Linux.git/' : Could not resolve host : github.com; Unknown error
[root@luckily Linux]# ls
7Linux042901.cpp  7Linux042903.cpp  7Linux042905.cpp  8Linux050702.cpp  SetNum.c
7Linux042902.cpp  7Linux042904.cpp  8Linux050701.cpp  Linux050201.c
[root@luckily Linux]# vim 8Linux050701.cpp
[root@luckily Linux]# rm 8Linux050701.cpp
rm：是否删除普通文件 "8Linux050701.cpp"？y
[root@luckily Linux]# git push
fatal : unable to access 'https://github.com/Luckily777/Linux.git/' : Could not resolve host : github.com; Unknown error
[root@luckily Linux]# git add 8Linux050702.cpp
[root@luckily Linux]# git commit .
# 位于分支 master
# 您的分支领先 'origin/master' 共 1 个提交。
#   （使用 "git push" 来发布您的本地提交）
#
无文件要提交，干净的工作区
[root@luckily Linux]# git push
fatal : unable to access 'https://github.com/Luckily777/Linux.git/' : Could not resolve host : github.com; Unknown error
[root@luckily Linux]# vim 8Linux050702.cpp
[root@luckily Linux]# 
// 程序，是在硬盘中放的一些代码
// 进程，从硬盘拉到内存之中的


进程
[root@luckily ~]# ps - ef

[root@luckily ~]# cd / usr /
bin / games / lib / libexec / sbin / src /
etc / include / lib64 / local / share / tmp /
[root@luckily ~]# cd / usr / src /
[root@luckily src]# ls
debug  kernels
[root@luckily src]# cd kernels /
[root@luckily kernels]# ls
[root@luckily kernels]# 

运行态
[root@luckily ~]# ps aux
USER        PID% CPU% MEM    VSZ   RSS TTY      STAT START   TIME COMMAND

root       3898  0.0  0.1 155372  1872 pts / 0    R + 21:47   0 : 00 ps aux

R表示正在运行态

root       3690  0.0  0.0      0     0 ? S    21 : 30   0 : 00[kworker / 0:0]
root       3741  0.0  0.0      0     0 ? S    21 : 35   0 : 00[kworker / 0:2]
S表示可中断睡眠状态


root       2943  0.1  1.7 850256 32136 ? Dl   20 : 50   0 : 04 / usr / libexec / gnome - te
D表示不可唤醒睡眠状态


renice -n -5 11485  改变进程的优先级


[root@luckily ~]# cd study
[root@luckily study]# cd day04
[root@luckily day04]# vim dem050701.c
[root@luckily day04]# gcc - g dem050701.c
[root@luckily day04]# . / a.out
hehe
a = 0
[root@luckily day04]# . / a.out
123
段错误(吐核)
[root@luckily day04]# vim dem050701.c
[root@luckily day04]# ulimit - a
core file size(blocks, -c) 0
data seg size(kbytes, -d) unlimited
scheduling priority(-e) 0
file size(blocks, -f) unlimited
pending signals(-i) 7140
max locked memory(kbytes, -l) 64
max memory size(kbytes, -m) unlimited
open files(-n) 1024
pipe size(512 bytes, -p) 8
POSIX message queues(bytes, -q) 819200
real - time priority(-r) 0
stack size(kbytes, -s) 8192
cpu time(seconds, -t) unlimited
max user processes(-u) 7140
virtual memory(kbytes, -v) unlimited
file locks(-x) unlimited
[root@luckily day04]# ulimit - c unlimited
[root@luckily day04]# ulimit - a
core file size(blocks, -c) unlimited
data seg size(kbytes, -d) unlimited
scheduling priority(-e) 0
file size(blocks, -f) unlimited
pending signals(-i) 7140
max locked memory(kbytes, -l) 64
max memory size(kbytes, -m) unlimited
open files(-n) 1024
pipe size(512 bytes, -p) 8
POSIX message queues(bytes, -q) 819200
real - time priority(-r) 0
stack size(kbytes, -s) 8192
cpu time(seconds, -t) unlimited
max user processes(-u) 7140
virtual memory(kbytes, -v) unlimited
file locks(-x) unlimited
[root@luckily day04]# . / a.out
123
段错误(吐核)
[root@luckily day04]# ls
a.out  core.4225  dem050701.c  test.c
[root@luckily day04]# file core.4225
core.4225: ELF 64 - bit LSB core file x86 - 64, version 1 (SYSV), SVR4 - style, from './a.out', real uid : 0, effective uid : 0, real gid : 0, effective gid : 0, execfn : './a.out', platform : 'x86_64'
[root@luckily day04]# gdb . / a.out
GNU gdb(GDB) Red Hat Enterprise Linux 7.6.1 - 115.el7
Copyright(C) 2013 Free Software Foundation, Inc.
License GPLv3 + : GNU GPL version 3 or later < http ://gnu.org/licenses/gpl.html>
    This is free software : you are free to changeand redistribute it.
    There is NO WARRANTY, to the extent permitted by law.Type "show copying"
    and "show warranty" for details.
    This GDB was configured as "x86_64-redhat-linux-gnu".
    For bug reporting instructions, please see :
< http ://www.gnu.org/software/gdb/bugs/>...
    Reading symbols from / root / study / day04 / a.out...done.
    (gdb) ^ CQuit
    (gdb) : q
    Undefined command : "".Try "help".
    (gdb) ^ CQuit
    (gdb) ^ CQuit
    (gdb) ^ [
        Undefined command : "".Try "help".
            (gdb)quit
            [root@luckily day04]# gdb . / a.out core.4225
            GNU gdb(GDB) Red Hat Enterprise Linux 7.6.1 - 115.el7
            Copyright(C) 2013 Free Software Foundation, Inc.
            License GPLv3 + : GNU GPL version 3 or later < http ://gnu.org/licenses/gpl.html>
            This is free software : you are free to changeand redistribute it.
            There is NO WARRANTY, to the extent permitted by law.Type "show copying"
            and "show warranty" for details.
            This GDB was configured as "x86_64-redhat-linux-gnu".
            For bug reporting instructions, please see :
        < http ://www.gnu.org/software/gdb/bugs/>...
            Reading symbols from / root / study / day04 / a.out...done.
            [New LWP 4225]
        Core was generated by `. / a.out'.
            Program terminated with signal 11, Segmentation fault.
            #0  0x00007fb4b46cb2b1 in __GI__IO_vfscanf() from / lib64 / libc.so.6
            Missing separate debuginfos, use: debuginfo - install glibc - 2.17 - 292.el7.x86_64
            (gdb) quit
            [root@luckily day04]# gdb . / a.out
            GNU gdb(GDB) Red Hat Enterprise Linux 7.6.1 - 115.el7
            Copyright(C) 2013 Free Software Foundation, Inc.
            License GPLv3 + : GNU GPL version 3 or later < http ://gnu.org/licenses/gpl.html>
            This is free software : you are free to changeand redistribute it.
            There is NO WARRANTY, to the extent permitted by law.Type "show copying"
            and "show warranty" for details.
            This GDB was configured as "x86_64-redhat-linux-gnu".
            For bug reporting instructions, please see :
        < http ://www.gnu.org/software/gdb/bugs/>...
            Reading symbols from / root / study / day04 / a.out...done.
            (gdb)l
            1	#include <stdio.h>
            2	#include <stdlib.h>
            3
            4	int main(void) {
            5		int a;
            6
                7		scanf("%d", a);
            8
                9		printf("a = %d\n", a);
            10
        }
        (gdb)b 7
            Breakpoint 1 at 0x4005a5: file dem050701.c, line 7.
            (gdb)r
            Starting program : / root / study / day04 / . / a.out

            Breakpoint 1, main() at dem050701.c : 7
            7		scanf("%d", a);
        Missing separate debuginfos, use: debuginfo - install glibc - 2.17 - 292.el7.x86_64
        (gdb) r
            The program being debugged has been started already.
            Start it from the beginning ? (y or n) y
            Starting program : / root / study / day04 / . / a.out

            Breakpoint 1, main() at dem050701.c : 7
            7		scanf("%d", a);
        (gdb)10
            Undefined command : "10".Try "help".
            (gdb)n
            10

            Program received signal SIGSEGV, Segmentation fault.
            0x00007ffff7a692b1 in __GI__IO_vfscanf() from / lib64 / libc.so.6
            (gdb)quit
            A debugging session is active.

            Inferior 1[process 4311] will be killed.

            Quit anyway ? (y or n)

查看cpu信息
[root@luckily day04]# cd  
[root@luckily ~]# cd / usr / src /
[root@luckily src]# cat / proc / cpuinfo

//查看最大值
[root@luckily src]# cat / proc / sys / kernel / pid_max
131072
[root@luckily src]# ps - e | wc - l
241


父进程和子进程
[root@luckily ~]# cd study
[root@luckily study]# cd day04
[root@luckily day04]# vim fork.c
[root@luckily day04]# gcc fork.c
[root@luckily day04]# . / a.out
before fork
after fork
after fork
^ C
[root@luckily day04]# vim fork.c
[root@luckily day04]# gcc fork.c
[root@luckily day04]# . / a.out
before fork
parent
child
^ C
