//静态库和动态库的基本操作

[root@luckily ~]# cd study
[root@luckily study]# ls
day01  day02  day03  day04  day05  day06  day07  day08  day09  day10
[root@luckily study]# mkdir day11
[root@luckily study]# ls
day01  day02  day03  day04  day05  day06  day07  day08  day09  day10  day11
[root@luckily study]# cd day11
[root@luckily day11]# mkdir program
[root@luckily day11]# cd program /
[root@luckily program]# vim add.c
[root@luckily program]# touch global.h
[root@luckily program]# vim add.c
[root@luckily program]# vim sub.c
[root@luckily program]# vim global.h
[root@luckily program]# gcc - c add.c - I.
[root@luckily program]# gcc - c sub.c - I.
[root@luckily program]# file sub.o
sub.o: ELF 64 - bit LSB relocatable, x86 - 64, version 1 (SYSV), not stripped
[root@luckily program]# objdump - dS sub.o

sub.o：     文件格式 elf64 - x86 - 64


Disassembly of section.text:

0000000000000000 < sub > :
    0 : 55                   	push % rbp
    1 : 48 89 e5             	mov % rsp, % rbp
    4 : 89 7d fc             	mov % edi, -0x4(% rbp)
    7 : 89 75 f8             	mov % esi, -0x8(% rbp)
    a : 8b 45 f8             	mov - 0x8(% rbp), % eax
    d : 8b 55 fc             	mov - 0x4(% rbp), % edx
    10 : 29 c2                	sub % eax, % edx
    12 : 89 d0                	mov % edx, % eax
    14 : 5d                   	pop % rbp
    15 : c3                   	retq
    [root@luckily program]# ls - l
    总用量 20
    - rw - r--r--. 1 root root   59 6月   6 20:29 add.c
    - rw - r--r--. 1 root root 1240 6月   6 20 : 32 add.o
    - rw - r--r--. 1 root root  110 6月   6 20 : 31 global.h
    - rw - r--r--. 1 root root   66 6月   6 20 : 29 sub.c
    - rw - r--r--. 1 root root 1240 6月   6 20 : 32 sub.o
    [root@luckily program]# strip sub.o
    [root@luckily program]# file sub.o
    sub.o: ELF 64 - bit LSB relocatable, x86 - 64, version 1 (SYSV), stripped
    [root@luckily program]# ls - l sub.o
    - rw - r--r--. 1 root root 768 6月   6 20:34 sub.o
    [root@luckily program]# objdump - dS sub.o

    sub.o：     文件格式 elf64 - x86 - 64


    Disassembly of section.text:

0000000000000000 < .text > :
    0 : 55                   	push % rbp
    1 : 48 89 e5             	mov % rsp, % rbp
    4 : 89 7d fc             	mov % edi, -0x4(% rbp)
    7 : 89 75 f8             	mov % esi, -0x8(% rbp)
    a : 8b 45 f8             	mov - 0x8(% rbp), % eax
    d : 8b 55 fc             	mov - 0x4(% rbp), % edx
    10 : 29 c2                	sub % eax, % edx
    12 : 89 d0                	mov % edx, % eax
    14 : 5d                   	pop % rbp
    15 : c3                   	retq
    [root@luckily program]# gcc - c sub.c - I. - g
    [root@luckily program]# objdump - dS sub.o

    sub.o：     文件格式 elf64 - x86 - 64


    Disassembly of section.text:

0000000000000000 < sub > :
#include <global.h>

    int sub(int a, int b) {
    0:	55                   	push % rbp
        1 : 48 89 e5             	mov % rsp, % rbp
        4 : 89 7d fc             	mov % edi, -0x4(% rbp)
        7 : 89 75 f8             	mov % esi, -0x8(% rbp)
        return a - b;
a:	8b 45 f8             	mov - 0x8(% rbp), % eax
d : 8b 55 fc             	mov - 0x4(% rbp), % edx
10 : 29 c2                	sub % eax, % edx
12 : 89 d0                	mov % edx, % eax
}
14:	5d                   	pop % rbp
15 : c3                   	retq
[root@luckily program]# gcc - c sub.c - I.
[root@luckily program]# nm sub.o
0000000000000000 T sub
[root@luckily program]# strip sub.o
[root@luckily program]# nm sub.o
nm : sub.o：无符号
[root@luckily program]# objdump - dS sub.o

sub.o：     文件格式 elf64 - x86 - 64


Disassembly of section.text:

0000000000000000 < .text > :
    0 : 55                   	push % rbp
    1 : 48 89 e5             	mov % rsp, % rbp
    4 : 89 7d fc             	mov % edi, -0x4(% rbp)
    7 : 89 75 f8             	mov % esi, -0x8(% rbp)
    a : 8b 45 f8             	mov - 0x8(% rbp), % eax
    d : 8b 55 fc             	mov - 0x4(% rbp), % edx
    10 : 29 c2                	sub % eax, % edx
    12 : 89 d0                	mov % edx, % eax
    14 : 5d                   	pop % rbp
    15 : c3                   	retq
    [root@luckily program]# vim main.c
    [root@luckily program]# gcc sub.c - I. - c
    [root@luckily program]# gcc main.c - I. - c
    main.c:2 : 20 : 致命错误：stdio..h：没有那个文件或目录
#include <stdio..h>
    ^
    编译中断。
    [root@luckily program]# vim main.c
    [root@luckily program]# gcc main.c - I. - c
    [root@luckily program]# 
    [root@luckily ~]# cd study
    [root@luckily study]# ls
    day01  day02  day03  day04  day05  day06  day07  day08  day09  day10  day11
    [root@luckily study]# cd day11
    [root@luckily day11]# cd program /
    [root@luckily program]# ls
    add.c  add.o  global.h  main.c  main.o  sub.c  sub.o
    [root@luckily program]# gcc main.o sub.o add.o - o main
    [root@luckily program]# . / main
    add = 50
    sub = -10
    [root@luckily program]# ar - crs libmymath.a sub.o add.o
    [root@luckily program]# file libmymath.a
    libmymath.a: current ar archive
    [root@luckily program]# nam libmymath.a
    bash : nam: 未找到命令...
    [root@luckily program]# nm libmymath.a

    sub.o:
0000000000000000 T sub

add.o :
    0000000000000000 T add
    [root@luckily program]# ar tv libmymath.a
    rw - r--r-- 0 / 0   1240 Jun  6 20:49 2020 sub.o
    rw - r--r-- 0 / 0   1240 Jun  6 20 : 32 2020 add.o
    [root@luckily program]# rm add.o
    rm：是否删除普通文件 "add.o"？y
    [root@luckily program]# rm sub.o
    rm：是否删除普通文件 "sub.o"？y
    [root@luckily program]# rm main
    rm：是否删除普通文件 "main"？y
    [root@luckily program]# ls
    add.c  global.h  libmymath.a  main.c  main.o  sub.c
    [root@luckily program]# gcc main.o libmymath.a
    [root@luckily program]# . / a.out
    add = 50
    sub = -10
    [root@luckily program]# bojdump - dS libmymath.a
    bash : bojdump: 未找到命令...
    相似命令是： 'objdump'
    [root@luckily program]# gcc main.o - L . - lmymath
    [root@luckily program]# . / a.out
    add = 50
    sub = -10
    [root@luckily program]# gcc - shared - fPIC - o libmymath.so add.o sub.o - I.
    gcc: 错误：add.o：没有那个文件或目录
    gcc : 错误：sub.o：没有那个文件或目录
    gcc : 致命错误：没有输入文件
    编译中断。
    [root@luckily program]# gcc - shared - fPIC - o libmymath.so add.c sub.c - I.
    [root@luckily program]# ls
    add.c  a.out  global.h  libmymath.a  libmymath.so  main.c  main.o  sub.c
    [root@luckily program]# file libmymath.so
    libmymath.so: ELF 64 - bit LSB shared object, x86 - 64, version 1 (SYSV), dynamically linked, BuildID[sha1] = ec9b19e61b6e7262f3eba7b8427f29c983a9dc42, not stripped
    [root@luckily program]# . / libmymath.so
    段错误(吐核)
    [root@luckily program]# readelf - h libmymath.so
    ELF 头：
    Magic：  7f 45 4c 46 02 01 01 00 00 00 00 00 00 00 00 00
    类别:                              ELF64
    数据 : 2 补码，小端序(little endian)
    版本 : 1 (current)
    OS / ABI : UNIX - System V
    ABI 版本 : 0
    类型 : DYN(共享目标文件)
    系统架构 : Advanced Micro Devices X86 - 64
    版本 : 0x1
    入口点地址：              0x590
    程序头起点：              64 (bytes into file)
    Start of section headers : 6208 (bytes into file)
    标志：             0x0
    本头的大小：       64 (字节)
    程序头大小：       56 (字节)
    Number of program headers : 7
    节头大小：         64 (字节)
    节头数量：         27
    字符串表索引节头： 26
    [root@luckily program]# bojdump - dS libmymath.so
    bash : bojdump: 未找到命令...
    相似命令是： 'objdump'
    [root@luckily program]# objdump - dS libmymath.so

    libmymath.so：     文件格式 elf64 - x86 - 64


    Disassembly of section.init:

0000000000000540 < _init > :
    540 : 48 83 ec 08          	sub    $0x8, % rsp
    544:	48 8b 05 95 0a 20 00 	mov    0x200a95(% rip), % rax        # 200fe0 < __gmon_start__>
    54b:	48 85 c0             	test % rax, % rax
    54e : 74 05                	je     555 < _init + 0x15 >
    550 : e8 1b 00 00 00       	callq  570 < __gmon_start__@plt >
    555 : 48 83 c4 08          	add    $0x8, % rsp
    559:	c3                   	retq

    Disassembly of section.plt :

    0000000000000560 < .plt > :
    560 : ff 35 a2 0a 20 00    	pushq  0x200aa2(% rip)        # 201008 < _GLOBAL_OFFSET_TABLE_ + 0x8 >
    566:	ff 25 a4 0a 20 00    	jmpq * 0x200aa4(% rip)        # 201010 < _GLOBAL_OFFSET_TABLE_ + 0x10 >
    56c:	0f 1f 40 00          	nopl   0x0(% rax)

    0000000000000570 < __gmon_start__@plt > :
    570 : ff 25 a2 0a 20 00    	jmpq * 0x200aa2(% rip)        # 201018 < __gmon_start__ >
    576:	68 00 00 00 00       	pushq  $0x0
    57b : e9 e0 ff ff ff       	jmpq   560 < .plt >

    0000000000000580 <__cxa_finalize@plt> :
    580 : ff 25 9a 0a 20 00    	jmpq * 0x200a9a(% rip)        # 201020 < __cxa_finalize@GLIBC_2.2.5 >
    586:	68 01 00 00 00       	pushq  $0x1
    58b : e9 d0 ff ff ff       	jmpq   560 < .plt >

    Disassembly of section.text :

    0000000000000590 <deregister_tm_clones> :
    590 : 48 8d 05 98 0a 20 00 	lea    0x200a98(% rip), % rax        # 20102f < _edata + 0x7>
    597:	48 8d 3d 8a 0a 20 00 	lea    0x200a8a(% rip), % rdi        # 201028 < _edata >
    59e:	55                   	push % rbp
    59f : 48 29 f8             	sub % rdi, % rax
    5a2 : 48 89 e5             	mov % rsp, % rbp
    5a5 : 48 83 f8 0e          	cmp    $0xe, % rax
    5a9 : 77 02                	ja     5ad < deregister_tm_clones + 0x1d>
    5ab : 5d                   	pop % rbp
    5ac : c3                   	retq
    5ad : 48 8b 05 24 0a 20 00 	mov    0x200a24(% rip), % rax        # 200fd8 < _ITM_deregisterTMCloneTable>
    5b4:	48 85 c0             	test % rax, % rax
    5b7 : 74 f2                	je     5ab < deregister_tm_clones + 0x1b>
    5b9 : 5d                   	pop % rbp
    5ba : ff e0                	jmpq * %rax
    5bc : 0f 1f 40 00          	nopl   0x0(% rax)

    00000000000005c0 <register_tm_clones> :
    5c0 : 48 8d 05 61 0a 20 00 	lea    0x200a61(% rip), % rax        # 201028 < _edata >
    5c7:	48 8d 3d 5a 0a 20 00 	lea    0x200a5a(% rip), % rdi        # 201028 < _edata >
    5ce:	55                   	push % rbp
    5cf : 48 29 f8             	sub % rdi, % rax
    5d2 : 48 89 e5             	mov % rsp, % rbp
    5d5 : 48 c1 f8 03          	sar    $0x3, % rax
    5d9 : 48 89 c2             	mov % rax, % rdx
    5dc : 48 c1 ea 3f          	shr    $0x3f, % rdx
    5e0 : 48 01 d0             	add % rdx, % rax
    5e3 : 48 d1 f8             	sar % rax
    5e6 : 75 02                	jne    5ea < register_tm_clones + 0x2a>
    5e8 : 5d                   	pop % rbp
    5e9 : c3                   	retq
    5ea : 48 8b 15 ff 09 20 00 	mov    0x2009ff(% rip), % rdx        # 200ff0 < _ITM_registerTMCloneTable>
    5f1:	48 85 d2             	test % rdx, % rdx
    5f4 : 74 f2                	je     5e8 < register_tm_clones + 0x28 >
    5f6 : 5d                   	pop % rbp
    5f7 : 48 89 c6             	mov % rax, % rsi
    5fa : ff e2                	jmpq * %rdx
    5fc : 0f 1f 40 00          	nopl   0x0(% rax)

    0000000000000600 < __do_global_dtors_aux > :
    600 : 80 3d 21 0a 20 00 00 	cmpb   $0x0, 0x200a21(% rip)        # 201028 < _edata >
    607:	75 27                	jne    630 < __do_global_dtors_aux + 0x30 >
    609 : 48 83 3d e7 09 20 00 	cmpq   $0x0, 0x2009e7(% rip)        # 200ff8 < __cxa_finalize@GLIBC_2.2.5>
    610:	00
    611 : 55                   	push % rbp
    612 : 48 89 e5             	mov % rsp, % rbp
    615 : 74 0c                	je     623 < __do_global_dtors_aux + 0x23 >
    617 : 48 8d 3d f2 07 20 00 	lea    0x2007f2(% rip), % rdi        # 200e10 < __dso_handle >
    61e:	e8 5d ff ff ff       	callq  580 < __cxa_finalize@plt >
    623 : e8 68 ff ff ff       	callq  590 < deregister_tm_clones >
    628 : 5d                   	pop % rbp
    629 : c6 05 f8 09 20 00 01 	movb   $0x1, 0x2009f8(% rip)        # 201028 < _edata >
    630:	f3 c3                	repz retq
    632 : 0f 1f 40 00          	nopl   0x0(% rax)
    636 : 66 2e 0f 1f 84 00 00 	nopw % cs : 0x0(% rax, % rax, 1)
    63d : 00 00 00

    0000000000000640 < frame_dummy > :
    640 : 48 83 3d c0 07 20 00 	cmpq   $0x0, 0x2007c0(% rip)        # 200e08 < __JCR_END__ >
    647:	00
    648 : 74 26                	je     670 < frame_dummy + 0x30 >
    64a : 48 8b 05 97 09 20 00 	mov    0x200997(% rip), % rax        # 200fe8 < _Jv_RegisterClasses>
    651:	48 85 c0             	test % rax, % rax
    654 : 74 1a                	je     670 < frame_dummy + 0x30 >
    656 : 55                   	push % rbp
    657 : 48 8d 3d aa 07 20 00 	lea    0x2007aa(% rip), % rdi        # 200e08 < __JCR_END__ >
    65e:	48 89 e5             	mov % rsp, % rbp
    661 : ff d0                	callq * %rax
    663 : 5d                   	pop % rbp
    664 : e9 57 ff ff ff       	jmpq   5c0 < register_tm_clones>
    669 : 0f 1f 80 00 00 00 00 	nopl   0x0(% rax)
    670 : e9 4b ff ff ff       	jmpq   5c0 <register_tm_clones>

    0000000000000675 < add > :
    675 : 55                   	push % rbp
    676 : 48 89 e5             	mov % rsp, % rbp
    679 : 89 7d fc             	mov % edi, -0x4(% rbp)
    67c : 89 75 f8             	mov % esi, -0x8(% rbp)
    67f : 8b 45 f8             	mov - 0x8(% rbp), % eax
    682 : 8b 55 fc             	mov - 0x4(% rbp), % edx
    685 : 01 d0                	add % edx, % eax
    687 : 5d                   	pop % rbp
    688 : c3                   	retq

    0000000000000689 <sub> :
    689 : 55                   	push % rbp
    68a : 48 89 e5             	mov % rsp, % rbp
    68d : 89 7d fc             	mov % edi, -0x4(% rbp)
    690 : 89 75 f8             	mov % esi, -0x8(% rbp)
    693 : 8b 45 f8             	mov - 0x8(% rbp), % eax
    696 : 8b 55 fc             	mov - 0x4(% rbp), % edx
    699 : 29 c2                	sub % eax, % edx
    69b : 89 d0                	mov % edx, % eax
    69d : 5d                   	pop % rbp
    69e : c3                   	retq

    Disassembly of section.fini :

    00000000000006a0 <_fini> :
    6a0 : 48 83 ec 08          	sub    $0x8, % rsp
    6a4:	48 83 c4 08          	add    $0x8, % rsp
    6a8:	c3                   	retq
    [root@luckily program]# gcc main.c - I. - L. - lmymath
    [root@luckily program]# ls - l
    总用量 44
    - rw - r--r--. 1 root root   59 6月   6 20:29 add.c
    - rwxr - xr - x. 1 root root 8432 6月   7 11 : 27 a.out
    - rw - r--r--. 1 root root  110 6月   6 20 : 31 global.h
    - rw - r--r--. 1 root root 2688 6月   7 10 : 53 libmymath.a
    - rwxr - xr - x. 1 root root 7936 6月   7 11 : 09 libmymath.so
    - rw - r--r--. 1 root root  124 6月   6 20:50 main.c
    - rw - r--r--. 1 root root 1704 6月   6 20 : 50 main.o
    - rw - r--r--. 1 root root   66 6月   6 20 : 29 sub.c
    [root@luckily program]# gcc - c add.c sub.c - I.
    [root@luckily program]# ls
    add.c  add.o  a.out  global.h  libmymath.a  libmymath.so  main.c  main.o  sub.c  sub.o
    [root@luckily program]# ls
    add.c  add.o  a.out  global.h  libmymath.a  libmymath.so  main.c  main.o  sub.c  sub.o
    [root@luckily program]# . / a.out
    . / a.out: error while loading shared libraries : libmymath.so : cannot open shared object file : No such file or directory
    [root@luckily program]# gcc main.c - L . - lmymath - I.
    [root@luckily program]# . / a.out
    . / a.out: error while loading shared libraries : libmymath.so : cannot open shared object file : No such file or directory
    [root@luckily program]# cd / etc / ld.so.conf.d /
    [root@luckily ld.so.conf.d]# ls
    bind - export - x86_64.conf  kernel - 3.10.0 - 1062.el7.x86_64.conf  mysql - x86_64.conf
    dyninst - x86_64.conf      libiscsi - x86_64.conf
    [root@luckily ld.so.conf.d]# cd -
    / root / study / day11 / program
    [root@luckily program]# ls
    add.c  add.o  a.out  global.h  libmymath.a  libmymath.so  main.c  main.o  sub.c  sub.o
    [root@luckily program]# pwd
    / root / study / day11 / program
    [root@luckily program]# echo 'pwd'
    pwd
    [root@luckily program]# echo 'pwd'
    pwd
    [root@luckily program]# pwd
    / root / study / day11 / program
    [root@luckily program]# echo ‘'pwd'
    ‘pwd
    [root@luckily program]# echo 'pwd'
    pwd
    [root@luckily program]# echo '/root/study/day11/program'
    / root / study / day11 / program
    [root@luckily program]# echo pwd
    pwd
    [root@luckily program]# echo 'pwd'
    pwd
    [root@luckily program]# echo '/root/study/day11/program' > / etc / ld.so.conf.d / my.conf
    [root@luckily program]# cat / etc / ld.so.conf.d / my.conf
    / root / study / day11 / program
    [root@luckily program]# . / a.out
    . / a.out: error while loading shared libraries : libmymath.so : cannot open shared object file : No such file or directory
    [root@luckily program]# ldconfig
    [root@luckily program]# . / a.out
    add = 50
    sub = -10
    [root@luckily program]# ldd a.out
    linux - vdso.so.1 = > (0x00007ffe2407d000)
    libmymath.so = > / root / study / day11 / program / libmymath.so(0x00007fe04892d000)
    libc.so.6 = > / lib64 / libc.so.6 (0x00007fe04855f000)
    / lib64 / ld - linux - x86 - 64.so.2 (0x00007fe048b2f000)
    [root@luckily program]# cd ..
    [root@luckily day11]# ls
    program
    [root@luckily day11]# vim dynamic_test.c
    [root@luckily day11]# gcc - shared - fPIC - olibmymath.so dynamic_test.c
    [root@luckily day11]# ls
    dynamic_test.c  libmymath.so  program
    [root@luckily day11]# vim main.c
    [root@luckily day11]# gcc main.c - ldl
    main.c: 在函数‘main’中:
main.c : 7 : 2 : 错误：程序中有游离的‘\357’
void* p = dlopen("./libmymath.so", RTLD_LAZY)；
^
main.c:7 : 2 : 错误：程序中有游离的‘\274’
main.c:7 : 2 : 错误：程序中有游离的‘\233’
main.c:9 : 2 : 错误：expected ‘, ’ or ‘; ’ before ‘void’
void (*pf)(void) = dlsym(p, "func");
^
[root@luckily day11]# vim main.c
[root@luckily day11]# gcc main.c - ldl
[root@luckily day11]# ldd a.out
linux - vdso.so.1 = > (0x00007ffee19fe000)
libdl.so.2 = > / lib64 / libdl.so.2 (0x00007f724108c000)
libc.so.6 = > / lib64 / libc.so.6 (0x00007f7240cbe000)
/ lib64 / ld - linux - x86 - 64.so.2 (0x00007f7241290000)
[root@luckily day11]# ls
a.out  dynamic_test.c  libmymath.so  main.c  program
[root@luckily day11]# . / a.out
hello
[root@luckily day11]# mv libmymath.so libmymath.so.1
[root@luckily day11]# ls
a.out  dynamic_test.c  libmymath.so.1  main.c  program
[root@luckily day11]# cd ..
[root@luckily study]# ls
day01  day02  day03  day04  day05  day06  day07  day08  day09  day10  day11
[root@luckily study]# mv day10 day0a
[root@luckily study]# ls
day01  day02  day03  day04  day05  day06  day07  day08  day09  day0a  day11
[root@luckily study]# mv day11 day0b
[root@luckily study]# cd day0b
[root@luckily day0b]# ls
a.out  dynamic_test.c  libmymath.so.1  main.c  program
[root@luckily day0b]# ln - s libmymath.so.1  libmymath.so
[root@luckily day0b]# ls - l
总用量 28
- rwxr - xr - x. 1 root root 8464 6月   7 16:02 a.out
- rw - r--r--. 1 root root   59 6月   7 15 : 55 dynamic_test.c
lrwxrwxrwx. 1 root root   14 6月   7 16 : 05 libmymath.so->libmymath.so.1
- rwxr - xr - x. 1 root root 8040 6月   7 15 : 56 libmymath.so.1
- rw - r--r--. 1 root root  204 6月   7 16 : 02 main.c
drwxr - xr - x. 2 root root  154 6月   7 11 : 31 program
[root@luckily day0b]# . / a.out
hello
[root@luckily day0b]# vim dynamic_test.c
[root@luckily day0b]# gcc - shared - fPIC - olibmymath.so.2 dynamic_test.c
[root@luckily day0b]# ls
a.out  dynamic_test.c  libmymath.so  libmymath.so.1  libmymath.so.2  main.c  program
[root@luckily day0b]# . / a.out
hello
[root@luckily day0b]# rm libmymath.so
rm：是否删除符号链接 "libmymath.so"？y
[root@luckily day0b]# ln - s libmymath.so.2  libmymath.so
[root@luckily day0b]# . / a.out
hello world
[root@luckily day0b]# 
