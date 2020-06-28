[root@luckily ~]# man - a
您需要什么手册页？
[root@luckily ~]# man
您需要什么手册页？
[root@luckily ~]# man - k
apropos 什么？
[root@luckily ~]# pwd
/ root
[root@luckily ~]# ls - a
..config                                     passwd        视频
...cshrc.pki          图片
1587552516.log.dbus                                       program       文档
anaconda - ks.cfg.esd_auth                                   study         下载
.bash_history.gitconfig.tcshrc       音乐
.bash_logout.ICEauthority                               test.txt.bak  桌面
.bash_profile.local.viminfo
.bashrc.mozilla                                    公共
.cache           mysql57 - community - release - el7 - 8.noarch.rpm  模板
[root@luckily ~]# ls - a
..config                                     passwd        视频
...cshrc.pki          图片
1587552516.log.dbus                                       program       文档
anaconda - ks.cfg.esd_auth                                   study         下载
.bash_history.gitconfig.tcshrc       音乐
.bash_logout.ICEauthority                               test.txt.bak  桌面
.bash_profile.local.viminfo
.bashrc.mozilla                                    公共
.cache           mysql57 - community - release - el7 - 8.noarch.rpm  模板
[root@luckily ~]# ls - l
总用量 24
- rw - r--r--.  1 root root    0 4月  22 18:48 1587552516.log
- rw------ - .  1 root root 2038 4月  20 18 : 54 anaconda - ks.cfg
- rw - r--r--.  1 root root 9116 4月  11 2016 mysql57 - community - release - el7 - 8.noarch.rpm
- rw - r--r--.  1 root root 2268 4月  20 21 : 44 passwd
drwxr - xr - x.  2 root root    6 4月  22 19 : 33 program
drwxr - xr - x. 19 root root  227 6月  22 22 : 57 study
- rw - r--r--.  1 root root   32 4月  21 19 : 45 test.txt.bak
drwxr - xr - x.  2 root root    6 4月  20 20 : 35 公共
drwxr - xr - x.  2 root root    6 4月  20 20 : 35 模板
drwxr - xr - x.  2 root root    6 4月  20 20 : 35 视频
drwxr - xr - x.  3 root root   39 6月  15 14 : 14 图片
drwxr - xr - x.  2 root root    6 4月  20 20 : 35 文档
drwxr - xr - x.  2 root root    6 4月  20 20 : 35 下载
drwxr - xr - x.  2 root root    6 4月  20 20 : 35 音乐
drwxr - xr - x.  2 root root    6 4月  20 20 : 35 桌面
[root@luckily ~]# ls - r
桌面  文档  模板          study    mysql57 - community - release - el7 - 8.noarch.rpm
音乐  图片  公共          program  anaconda - ks.cfg
下载  视频  test.txt.bak  passwd   1587552516.log
[root@luckily ~]# ls - t
study    1587552516.log  公共  文档  桌面
图片     test.txt.bak    模板  下载  anaconda - ks.cfg
program  passwd          视频  音乐  mysql57 - community - release - el7 - 8.noarch.rpm
[root@luckily ~]# ls - R
.:
1587552516.log                              passwd   test.txt.bak  视频  下载
anaconda - ks.cfg                             program  公共          图片  音乐
mysql57 - community - release - el7 - 8.noarch.rpm  study    模板          文档  桌面

. / program :

    . / study :
    day01  day03  day05  day07  day09  day0b  day0d  day0f  day11
    day02  day04  day06  day08  day0a  day0c  day0e  day10

    . / study / day01 :
    042401.c  042501.c  042502.c  a.out

    . / study / day02 :
    042801.c  042802.c  042803.c  a.out  progress

    . / study / day02 / progress :
    add.c  a.out  main.c    mul.c  obj      parse.h  sub.h
    add.h  main   Makefile  mul.h  parse.c  sub.c

    . / study / day02 / progress / obj :
    add.o  main.o  mul.o  parse.o  sub.o

    . / study / day03 :
    Jindutiao  Jindutiao.c  process  process.c

    . / study / day04 :
    a.out  core.4225  dem050701.c  fork.c  test.c

    . / study / day05 :
    02.c  03.c  04.c  05.c  06.c  07.c  08.c  8Linux051001.c  a.out  env.c

    . / study / day06 :
    01.c  02  02.c  03.c  04.c  05.c  06.c  a.out  core.6428

    . / study / day07 :
    01.c  02.c  03.c  04.c  a.out  myenv  myenv.c  myshell.c

    . / study / day08 :
    a.out            hehe.c  mycopy.c          review.c  Studest.c  tmp.txt
    close_on_exec.c  mycopy  open_for_write.c  stu.dat   test.txt

    . / study / day09 :
    01.c  02.c  03.c  04.c  05.c  06.c  07.c  a.out  test.txt  ttt  ttt.c

    . / study / day0a :
    01_lock.c  03_stat.c  aaa  AAA  a.out  ccc  dir.c  fff  FFF  Hehe  test.txt

    . / study / day0a / aaa :

    . / study / day0a / AAA :

    . / study / day0a / ccc :

    . / study / day0a / fff :

    . / study / day0a / FFF :

    . / study / day0b :
    03.c   dynamic_test.c  libmymath.so.1  main.c
    a.out  libmymath.so    libmymath.so.2  program

    . / study / day0b / program :
    add.c  add.o  a.out  global.h  libmymath.a  libmymath.so  main.c  main.o  sub.c  sub.o

    . / study / day0c :
    01.1.c  01.c  03.c  05.c  a.out       keyboard.h      mykill
    01.2.c  02.c  04.c  1     keyboard.c  libkeyboard.so  tetris.c

    . / study / day0d :
    01.c  02.c  03.c  04.c  05.c  a.out

    . / study / day0e :
    01.c  02.c  03.c  a.out

    . / study / day0f :
    01.c  02.c  a.out

    . / study / day10 :
    01.c   cli       msgcreate.c  msgsnd.c  rmipc    ser       snd
    a.out  client.c  msgrcv.c     rcv       rmipc.c  server.c

    . / study / day11 :

    . / 公共 :

    . / 模板 :

    . / 视频 :

    . / 图片 :
    Wallpapers  枭.png

    . / 图片 / Wallpapers :
    枭.png

    . / 文档 :

    . / 下载 :

    . / 音乐 :

    . / 桌面 :
    [root@luckily ~] # ls - d
    .
    [root@luckily ~]# ls - 1
    1587552516.log
    anaconda - ks.cfg
    mysql57 - community - release - el7 - 8.noarch.rpm
    passwd
    program
    study
    test.txt.bak
    公共
    模板
    视频
    图片
    文档
    下载
    音乐
    桌面
    [root@luckily ~]# ls pass *
    passwd
    [root@luckily ~]# ls pass ?
    ls : 无法访问pass ? : 没有那个文件或目录
    [root@luckily ~]# ls - l pass ?
    ls : 无法访问pass ? : 没有那个文件或目录
    [root@luckily ~]# ls - l passw ?
    -rw - r--r--. 1 root root 2268 4月  20 21 : 44 passwd
    [root@luckily ~]# mkdir 0626
    [root@luckily ~]# ls
    0626                                        passwd        公共  文档
    1587552516.log                              program       模板  下载
    anaconda - ks.cfg                             study         视频  音乐
    mysql57 - community - release - el7 - 8.noarch.rpm  test.txt.bak  图片  桌面
    [root@luckily ~]# rm - rf 0626
    [root@luckily ~]# ls
    1587552516.log                              passwd   test.txt.bak  视频  下载
    anaconda - ks.cfg                             program  公共          图片  音乐
    mysql57 - community - release - el7 - 8.noarch.rpm  study    模板          文档  桌面
    [root@luckily ~]# tail / etc / passwd | wc - 1
    wc：无效选项-- 1
    Try 'wc --help' for more information.
    [root@luckily ~]# tail / etc / passwd | wc - l
    10
    [root@luckily ~]# vim 0626.c
    [root@luckily ~]# rm - rf 0626.c
    [root@luckily ~]# su luckily
    [luckily@luckily root]$ exit
    exit
    [root@luckily ~]# top

    top - 14:29 : 11 up 39 min, 2 users, load average : 0.08, 0.03, 0.05
    Tasks : 239 total, 1 running, 238 sleeping, 0 stopped, 0 zombie
    % Cpu(s) : 1.1 us, 0.9 sy, 0.0 ni, 98.0 id, 0.0 wa, 0.0 hi, 0.0 si, 0.0 st
    KiB Mem : 1863104 total, 78796 free, 961256 used, 823052 buff / cache
    KiB Swap : 2093052 total, 2093052 free, 0 used.   702748 avail Mem

    PID USER      PR  NI    VIRT    RES    SHR S % CPU % MEM     TIME + COMMAND
    2603 root      20   0 3801252 170168  70320 S   5.3  9.1   0 : 30.77 gnome - shell
    1920 root      20   0  354168  48552  26784 S   3.6  2.6   0 : 10.73 X
    3043 root      20   0  850452  32624  19244 S   2.3  1.8   0 : 05.11 gnome - terminal -
    353 root - 51   0       0      0      0 S   0.3  0.0   0 : 00.18 irq / 16 - vmwgfx
    2572 root      20   0  233120   3920   3160 S   0.3  0.2   0 : 00.17 at - spi2 - registr
    2901 root      20   0  640756  25920  19108 S   0.3  1.4   0 : 04.07 vmtoolsd
    1 root      20   0  193772   6936   4204 S   0.0  0.4   0 : 02.83 systemd
    2 root      20   0       0      0      0 S   0.0  0.0   0 : 00.02 kthreadd
    4 root       0 - 20       0      0      0 S   0.0  0.0   0 : 00.00 kworker / 0 : 0H
    5 root      20   0       0      0      0 S   0.0  0.0   0 : 01.46 kworker / u256 : 0
    6 root      20   0       0      0      0 S   0.0  0.0   0 : 00.03 ksoftirqd / 0
    7 root      rt   0       0      0      0 S   0.0  0.0   0 : 00.21 migration / 0
    8 root      20   0       0      0      0 S   0.0  0.0   0 : 00.00 rcu_bh
    9 root      20   0       0      0      0 S   0.0  0.0   0 : 00.93 rcu_sched
    10 root       0 - 20       0      0      0 S   0.0  0.0   0 : 00.00 lru - add - drain
    11 root      rt   0       0      0      0 S   0.0  0.0   0 : 00.01 watchdog / 0
    12 root      rt   0       0      0      0 S   0.0  0.0   0 : 00.01 watchdog / 1
    13 root      rt   0       0      0      0 S   0.0  0.0   0 : 00.15 migration / 1
    14 root      20   0       0      0      0 S   0.0  0.0   0 : 00.03 ksoftirqd / 1
    16 root       0 - 20       0      0      0 S   0.0  0.0   0 : 00.00 kworker / 1 : 0H
    17 root      rt   0       0      0      0 S   0.0  0.0   0 : 00.01 watchdog / 2
    18 root      rt   0       0      0      0 S   0.0  0.0   0 : 00.18 migration / 2
    19 root      20   0       0      0      0 S   0.0  0.0   0 : 00.04 ksoftirqd / 2
    21 root       0 - 20       0      0      0 S   0.0  0.0   0 : 00.00 kworker / 2 : 0H
    22 root      rt   0       0      0      0 S   0.0  0.0   0 : 00.02 watchdog / 3
    23 root      rt   0       0      0      0 S   0.0  0.0   0 : 00.13 migration / 3
    24 root      20   0       0      0      0 S   0.0  0.0   0 : 00.14 ksoftirqd / 3
    26 root       0 - 20       0      0      0 S   0.0  0.0   0 : 00.00 kworker / 3 : 0H
    28 root      20   0       0      0      0 S   0.0  0.0   0 : 00.01 kdevtmpfs
    29 root       0 - 20       0      0      0 S   0.0  0.0   0 : 00.00 netns
    30 root      20   0       0      0      0 S   0.0  0.0   0 : 00.00 khungtaskd
    31 root       0 - 20       0      0      0 S   0.0  0.0   0 : 00.00 writeback
    32 root       0 - 20       0      0      0 S   0.0  0.0   0 : 00.00 kintegrityd
    33 root       0 - 20       0      0      0 S   0.0  0.0   0 : 00.00 bioset
    34 root       0 - 20       0      0      0 S   0.0  0.0   0 : 00.00 bioset
    35 root       0 - 20       0      0      0 S   0.0  0.0   0 : 00.00 bioset
    [root@luckily ~]# free
    total        used        free      shared  buff / cache   available
    Mem : 1863104      960144       79896       25356      823064      703856
    Swap : 2093052           0     2093052
    [root@luckily ~]# fdisk - l

    磁盘 / dev / sda：21.5 GB, 21474836480 字节，41943040 个扇区
    Units = 扇区 of 1 * 512 = 512 bytes
    扇区大小(逻辑 / 物理)：512 字节 / 512 字节
    I / O 大小(最小 / 最佳)：512 字节 / 512 字节
    磁盘标签类型：dos
    磁盘标识符：0x000bea2b

    设备 Boot      Start         End      Blocks   Id  System
    / dev / sda1 * 2048      411647      204800   83  Linux
    / dev / sda2          411648    31903743    15746048   8e  Linux LVM

    磁盘 / dev / mapper / centos - root：10.7 GB, 10737418240 字节，20971520 个扇区
    Units = 扇区 of 1 * 512 = 512 bytes
    扇区大小(逻辑 / 物理)：512 字节 / 512 字节
    I / O 大小(最小 / 最佳)：65536 字节 / 65536 字节


    磁盘 / dev / mapper / centos - swap：2143 MB, 2143289344 字节，4186112 个扇区
    Units = 扇区 of 1 * 512 = 512 bytes
    扇区大小(逻辑 / 物理)：512 字节 / 512 字节
    I / O 大小(最小 / 最佳)：512 字节 / 512 字节

    [root@luckily ~]# cal
    六月 2020
    日 一 二 三 四 五 六
    1  2  3  4  5  6
    7  8  9 10 11 12 13
    14 15 16 17 18 19 20
    21 22 23 24 25 26 27
    28 29 30

    [root@luckily ~]# date - d@1587552516
    2020年 04月 22日 星期三 18:48 : 36 CST
    [root@luckily ~]# find / usr / include / -name "*.h"
    / usr / include / python2.7 / pyconfig - 64.h
