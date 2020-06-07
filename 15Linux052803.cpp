//ÐÅºÅ²Ù×÷

[root@luckily day0b]# kill - l
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
[root@luckily day0b]# ls
a.out  dynamic_test.c  libmymath.so  libmymath.so.1  libmymath.so.2  main.c  program
[root@luckily day0b]# vim signal.c
[root@luckily day0b]# gcc signal.c
signal.c:1 : 19 : ÖÂÃü´íÎó£ºstido.h£ºÃ»ÓÐÄÇ¸öÎÄ¼þ»òÄ¿Â¼
#include <stido.h>
^
±àÒëÖÐ¶Ï¡£
[root@luckily day0b]# vim signal.c
[root@luckily day0b]# gcc signal.c
[root@luckily day0b]# . / a.out
........... ^ C¶Î´íÎó(ÍÂºË)
[root@luckily day0b]#  ^ C
[root@luckily day0b]# vim signal.c
[root@luckily day0b]# gcc signal.c
[root@luckily day0b]# . / a.out
.. ^ C¶Î´íÎó(ÍÂºË)
[root@luckily day0b]# . / a.out
.s.d.fds.. ^ C¶Î´íÎó(ÍÂºË)
[root@luckily day0b]# vim signal.c
[root@luckily day0b]# mv signal.c  03.c
[root@luckily day0b]# gcc 03.c
[root@luckily day0b]# . / a.out
.. ^ C¶Î´íÎó(ÍÂºË)
[root@luckily day0b]# vim signal.c
[root@luckily day0b]# rm signal.c
rm£ºÊÇ·ñÉ¾³ýÆÕÍ¨¿ÕÎÄ¼þ "signal.c"£¿y
[root@luckily day0b]# vim 03.c
[root@luckily day0b]# gcc 03.c
[root@luckily day0b]# . / a.out
sjhkjnfdkjsndsjndsjk ^ C¶Î´íÎó(ÍÂºË)
[root@luckily day0b]#  ^ C
[root@luckily day0b]#  ^ C
[root@luckily day0b]# skncjsk ^ C
[root@luckily day0b]# 
[root@luckily day0b]# 
[root@luckily day0b]# . / a.out

..s
.if (getchar() == '\n') {
    18             break;
    19
}
..^ C
[root@luckily day0b]# 
