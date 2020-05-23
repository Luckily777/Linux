//文件
[root@luckily day07]# man 2 open
[root@luckily day07]# 
[root@luckily day07]# ulimit - a
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
[root@luckily day07]# cat / proc / sys / fs /
aio - max - nr            inode - state           overflowuid
aio - nr                inotify / pipe - max - size
binfmt_misc / lease - break - time      pipe - user - pages - hard
dentry - state          leases - enable         pipe - user - pages - soft
dir - notify - enable     may_detach_mounts     protected_hardlinks
epoll / mount - max             protected_symlinks
file - max              mqueue / quota /
file - nr               nr_open               suid_dumpable
inode - nr              overflowgid           xfs /
[root@luckily day07]# cat / proc / sys / fs / file - max
179761
[root@luckily day07]# ulimit - n 2048
[root@luckily day07]# ulimit - a
core file size(blocks, -c) 0
data seg size(kbytes, -d) unlimited
scheduling priority(-e) 0
file size(blocks, -f) unlimited
pending signals(-i) 7140
max locked memory(kbytes, -l) 64
max memory size(kbytes, -m) unlimited
open files(-n) 2048
pipe size(512 bytes, -p) 8
POSIX message queues(bytes, -q) 819200
real - time priority(-r) 0
stack size(kbytes, -s) 8192
cpu time(seconds, -t) unlimited
max user processes(-u) 7140
virtual memory(kbytes, -v) unlimited
file locks(-x) unlimited
[root@luckily day07]# ulimit - n 1024
[root@luckily day07]# ulimit - a
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
[root@luckily day07]# vim 04.c
[root@luckily day07]# gcc 04.c
04.c: 在函数‘main’中:
04.c : 7 : 26 : 错误：整数常量的“_RDONLY”后缀无效
int fd = open("myshell.c", 0_RDONLY);
^
[root@luckily day07]# :wq
bash : : wq : 未找到命令...
[root@luckily day07]# vim 04.c
[root@luckily day07]# gcc 04.c
[root@luckily day07]# . / a.out
open ok
[root@luckily day07]# vim 04.c
[root@luckily day07]# gcc 04.c
04.c: 在函数‘main’中:
04.c : 21 : 21 : 错误：expected expression before ‘ < ’ token
	printf("buf=[%s]", <F6>buf);
^
[root@luckily day07]# vim 04.c
[root@luckily day07]# gcc 04.c
[root@luckily day07]# . / a.out
[#include <][stdio.h>
#][include <s][tdlib.h>
#][include <s][tring.h>
#][include <e][rrno.h>
#i][nclude < un][istd.h >
#i][nclude < sy][s / wait.h >
][
#define E][RR_EXIT(ms][g)\
      ][   do{\
  ][          ][   printf(]["[%s][%d] ][%s:%sn",__][FILE__,__L][INE__,msg,][strerror(e][rrno));\
 ][          ][     exit(][EXIT_FAILU][RE);\
    ][    }while][(0) 


	int][get_input][(char* buf][) {
	][memset(bu][f, 0x00, siz][eof(buf)); ][
		i][f(scanf("%][[^\n]%*c", ][buf) != 1) {
		][i][nt c;
		][do  c = get][char(); whi][le(c != '\n'][);
		}
		ret][urn strlen][(buf);
	}

		][void do_ac][tion(int a][rgc, char*][argv[]) {
		][pid_t pid; ][
			switch (p][id = fork())][{
				case -][1:
			prin][tf("当前][shell出��][�故障，][无法运�][��\n");
			][return;
			][case 0: {
					][int ret][=execvp(a][rgv[0], arg][v);
					pri][ntf("%s:co][mmand not ][found\n", a][rgv[0]);
					][exit(1); ][
			}
					][][break;
					][default:][{
						int s][tatus;
						][waitpid(pi][d, &status, ][0);
						][][}
							 break][;
			}
		}


		v][oid do_par][se(char* b][uf) {
			int][argc = 0;
		c][har * argv[][10] = {};
#][define OUT][ 0
		#defin][e IN 1

			i][nt status][=OUT;
		int][i;
		for (i][=0; buf[i]!][='\0'; i++)][{
			if (sta][tus == OUT][&& !isspac][e(buf[i]))][{
				argv[][argc++] = bu][f + i;
			st][atus = IN;
			][}
			else][if (isspac][e(buf[i]))][{
				statu][s = OUT;
				][buf[i] = '\0][';
			}
		}
				][argv[argc][] = NULL;
				d][o_action(a][rgc, argv); ][
		}

		int ma][in(void) {
		][char buf[][512];
		whi][le(1) {
			p][rintf("[Lu][ckily shel][l] # ");
			][if (get_in][put(buf) == ][0) {
				con][tinue;
				][
			}
			do_pa][rse(buf);
			][		//printf][("= >[%s]\][n",buf);
			][
		}
		}
			]end of file
				[root@luckily day07]# vim 04.c
				[root@luckily day07]# gcc 04.c
				[root@luckily day07]# . / a.out
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/wait.h>

#define ERR_EXIT(msg)\
         do{\
               printf("[%s][%d] %s:%sn",__FILE__,__LINE__,msg,strerror(errno));\
                exit(EXIT_FAILURE);\
        }while(0) 


				int get_input(char* buf) {
				memset(buf, 0x00, sizeof(buf));
				if (scanf("%[^\n]%*c", buf) != 1) {
					int c;
					do  c = getchar(); while (c != '\n');
				}
				return strlen(buf);
			}

			void do_action(int argc, char* argv[]) {
				pid_t pid;
				switch (pid = fork()) {
				case -1:
					printf("当前shell出现故障，无法运行\n");
					return;
				case 0: {
					int ret = execvp(argv[0], argv);
					printf("%s:command not found\n", argv[0]);
					exit(1);
				}
					  break;
				default: {
					int status;
					waitpid(pid, &status, 0);
				}
					   break;
				}
			}


			void do_parse(char* buf) {
				int argc = 0;
				char* argv[10] = {};
#define OUT 0
#define IN 1

				int status = OUT;
				int i;
				for (i = 0; buf[i] != '\0'; i++) {
					if (status == OUT && !isspace(buf[i])) {
						argv[argc++] = buf + i;
						status = IN;
					}
					else if (isspace(buf[i])) {
						status = OUT;
						buf[i] = '\0';
					}
				}
				argv[argc] = NULL;
				do_action(argc, argv);
			}

			int main(void) {
				char buf[512];
				while (1) {
					printf("[Luckily shell] # ");
					if (get_input(buf) == 0) {
						continue;
					}
					do_parse(buf);
					//printf("= >[%s]\n",buf);
				}
			}
			end of file
				[root@luckily day07]# vim 04.c
				[root@luckily day07]# 
