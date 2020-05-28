root@luckily ~]# cd study
[root@luckily study]# cd day08
[root@luckily day08]# ls
hehe.c  mycopy  mycopy.c  review.c  tmp.txt
[root@luckily day08]# cat tmp.txt
AAAA
[root@luckily day08]# cat hehe.c
#include <stdio.h>

int main(void) {
    char buf[1024] = {};

    FILE* fp = fopen("aaa", "w");
    fprintf(fp, "{id:%d name=\'%s\' , sal=%.2f}", 3, "zhangsan", 10.2);
    //fprintf(stdout,"{id:%d name=\'%s\' , sal=%.2f}",3,"zhangsan",10.2);
    //snprintf(buf,1024,"{id:%d name=\'%s\' , sal=%.2f}",3,"zhangsan",10.2);
    //printf("%s\n",buf);
    fclose(fp);
}
[root@luckily day08]# . / mycopy tmp.txt hehe.c
[root@luckily day08]# cat hehe.c
AAAA
ude <stdio.h>

int main(void) {
    char buf[1024] = {};

    FILE* fp = fopen("aaa", "w");
    fprintf(fp, "{id:%d name=\'%s\' , sal=%.2f}", 3, "zhangsan", 10.2);
    //fprintf(stdout,"{id:%d name=\'%s\' , sal=%.2f}",3,"zhangsan",10.2);
    //snprintf(buf,1024,"{id:%d name=\'%s\' , sal=%.2f}",3,"zhangsan",10.2);
    //printf("%s\n",buf);
    fclose(fp);
}
[root@luckily day08]# od - c tmp.txt
0000000   A   A   A   A  \n
0000005
[root@luckily day08]# vim mycopy.c
[root@luckily day08]# gcc mycopy.c - omycopy
[root@luckily day08]# . / mycopy tmp.txt hehe.c
[root@luckily day08]# ls
hehe.c  mycopy  mycopy.c  review.c  tmp.txt
[root@luckily day08]# cat hehe.c
AAAA
[root@luckily day08]# vim open_for_write.c
[root@luckily day08]# gcc open_for_write.c
open_for_write.c: 在函数‘main’中:
open_for_write.c : 13 : 38 : 错误：‘_OEXCL’未声明(在此函数内第一次使用)
fd = open("test.txt", O_RDWR | O_CREAT | _OEXCL, 0644);
^
open_for_write.c:13 : 38 : 附注：每个未声明的标识符在其出现的函数内只报告一次
[root@luckily day08]# vim open_for_write.c
[root@luckily day08]# gcc open_for_write.c
[root@luckily day08]# . / a.out
teset.txt created by 0xeb6
[root@luckily day08]# cd / usr / src /
debug / kernels /
[root@luckily day08]# cd / usr / src / kernels /
[root@luckily kernels]# ls
[root@luckily kernels]# cd ..
[root@luckily src]# cd ..
[root@luckily usr]# cd ..
[root@luckily / ]# cd
[root@luckily ~]# cd study
[root@luckily study]# cd day08
[root@luckily day08]# ls
a.out  hehe.c  mycopy  mycopy.c  open_for_write.c  review.c  test.txt  tmp.txt
[root@luckily day08]#  vim close_on_exit.c
[root@luckily day08]#  vim close_on_exec.c
[root@luckily day08]# rm - f close_on_exit.c
[root@luckily day08]#  vim close_on_exec.c
[root@luckily day08]# ls
a.out            hehe.c  mycopy.c          review.c  tmp.txt
close_on_exec.c  mycopy  open_for_write.c  test.txt
[root@luckily day08]# cat close_on_exec.c
[root@luckily day08]# cat open_for_write.c
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <errno.h>

int main(void) {
    int fd = open("test.txt", O_RDWR);
    if (fd >= 0) {
    }
    else if (fd == -1) {
        if (errno == ENOENT) {
            sleep(10);
            fd = open("test.txt", O_RDWR | O_CREAT | O_EXCL, 0644);
            if (fd == -1) {
                perror("open"), exit(1);
            }
            printf("teset.txt created by %p \n", getpid());
        }
        else {
            perror("open"), exit(1);
        }
    }
}
[root@luckily day08]# cat mycopy.c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>

//usage : ./mycpy src dst

int main(int argc, char* argv[]) {
    if (argc != 3) {
        fprintf(stderr, "usage: %s src_file dst_file\n", argv[0]);
        exit(EXIT_FAILURE);

    }
    //以只读的形式打开源文件
    int fd_src = open(argv[1], O_RDONLY);
    if (fd_src == -1) {
        fprintf(stderr, "open(%s):%s\n", argv[1], strerror(errno));
        exit(EXIT_FAILURE);
    }

    //以写的方式打开目标文件，并且创建
    //O_TRUNC :如果文件存在，就将内容删除
    int fd_dst = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd_dst == -1) {
        close(fd_src);//释放资源
        fprintf(stderr, "open(%s):%s\n", argv[2], strerror(errno));
        exit(EXIT_FAILURE);
    }

    char buf[1024];
    while (1) {
        memset(buf, 0x00, sizeof(buf));
        int ret = read(fd_src, buf, 1024);
        if (ret == -1) {
            fprintf(stderr, "read(%s):%s\n", argv[1], strerror(errno));
            break;
        }
        else if (ret == 0) {//读完文件，返回为0
            break;
        }
        if (write(fd_dst, buf, ret) == -1) {
            fprintf(stderr, "write(%s):%s\n", argv[2], strerror(errno));
            break;
        }
    }
    close(fd_src);
    close(fd_dst);
    //关闭文件
}
[root@luckily day08]# ls
a.out            hehe.c  mycopy.c          review.c  tmp.txt
close_on_exec.c  mycopy  open_for_write.c  test.txt
[root@luckily day08]# cat hehe.c
AAAA
[root@luckily day08]# cat tmp.txt
AAAA
[root@luckily day08]# cat review.c
#include <stdio.h>

int main(void) {
    char buf[1024] = {};

    FILE* fp = fopen("aaa", "w");
    fprintf(fp, "{id:%d name=\'%s\' , sal=%.2f}", 3, "zhangsan", 10.2);
    //fprintf(stdout,"{id:%d name=\'%s\' , sal=%.2f}",3,"zhangsan",10.2);
    //snprintf(buf,1024,"{id:%d name=\'%s\' , sal=%.2f}",3,"zhangsan",10.2);
    //printf("%s\n",buf);
    fclose(fp);
}
[root@luckily day08]# cat test.txt
[root@luckily day08]# vim Studest.c
[root@luckily day08]# gcc Studest.c
Studest.c:1 : 8 : 错误：expected ‘ = ’, ‘, ’, ‘; ’, ‘asm’ or ‘__attribute__’ before ‘ < ’ token
    nclude <stdio.h>
    ^
    In file included from Studest.c:2 : 0 :
    / usr / include / stdlib.h : 139 : 1 : 错误：未知的类型名‘size_t’
    extern size_t __ctype_get_mb_cur_max(void) __THROW __wur;
^
In file included from Studest.c:2 : 0 :
    / usr / include / stdlib.h : 331 : 4 : 错误：未知的类型名‘size_t’
    size_t __statelen) __THROW __nonnull((2));
^
/ usr / include / stdlib.h:361 : 4 : 错误：未知的类型名‘size_t’
size_t __statelen,
^
/ usr / include / stdlib.h : 465 : 22 : 错误：未知的类型名‘size_t’
extern void* malloc(size_t __size) __THROW __attribute_malloc__ __wur;
^
/ usr / include / stdlib.h:467 : 22 : 错误：未知的类型名‘size_t’
extern void* calloc(size_t __nmemb, size_t __size)
^
/ usr / include / stdlib.h : 467 : 38 : 错误：未知的类型名‘size_t’
extern void* calloc(size_t __nmemb, size_t __size)
^
/ usr / include / stdlib.h : 479 : 36 : 错误：未知的类型名‘size_t’
extern void* realloc(void* __ptr, size_t __size)
^
In file included from / usr / include / stdlib.h : 491 : 0,
from Studest.c : 2 :
    / usr / include / alloca.h : 32 : 22 : 错误：未知的类型名‘size_t’
    extern void* alloca(size_t __size) __THROW;
^
In file included from Studest.c:2 : 0 :
    / usr / include / stdlib.h : 497 : 22 : 错误：未知的类型名‘size_t’
    extern void* valloc(size_t __size) __THROW __attribute_malloc__ __wur;
^
/ usr / include / stdlib.h:502 : 45 : 错误：未知的类型名‘size_t’
extern int posix_memalign(void** __memptr, size_t __alignment, size_t __size)
^
/ usr / include / stdlib.h : 502 : 65 : 错误：未知的类型名‘size_t’
extern int posix_memalign(void** __memptr, size_t __alignment, size_t __size)
^
/ usr / include / stdlib.h : 755 : 9 : 错误：未知的类型名‘size_t’
size_t __nmemb, size_t __size, __compar_fn_t __compar)
^
/ usr / include / stdlib.h:755 : 25 : 错误：未知的类型名‘size_t’
size_t __nmemb, size_t __size, __compar_fn_t __compar)
^
/ usr / include / stdlib.h:760 : 34 : 错误：未知的类型名‘size_t’
extern void qsort(void* __base, size_t __nmemb, size_t __size,
    ^
    / usr / include / stdlib.h:760 : 50 : 错误：未知的类型名‘size_t’
    extern void qsort(void* __base, size_t __nmemb, size_t __size,
        ^
        / usr / include / stdlib.h:839 : 6 : 错误：未知的类型名‘size_t’
        size_t __len) __THROW __nonnull((3, 4, 5));
^
/ usr / include / stdlib.h:842 : 6 : 错误：未知的类型名‘size_t’
size_t __len) __THROW __nonnull((3, 4, 5));
^
/ usr / include / stdlib.h:846 : 31 : 错误：未知的类型名‘size_t’
char* __restrict __buf, size_t __len)
^
/ usr / include / stdlib.h:850 : 31 : 错误：未知的类型名‘size_t’
char* __restrict __buf, size_t __len)
^
/ usr / include / stdlib.h:859 : 36 : 错误：未知的类型名‘size_t’
extern int mblen(const char* __s, size_t __n) __THROW __wur;
^
/ usr / include / stdlib.h:863 : 34 : 错误：未知的类型名‘size_t’
const char* __restrict __s, size_t __n) __THROW __wur;
^
/ usr / include / stdlib.h:870 : 1 : 错误：未知的类型名‘size_t’
extern size_t mbstowcs(wchar_t* __restrict  __pwcs,
    ^
    / usr / include / stdlib.h:871 : 32 : 错误：未知的类型名‘size_t’
    const char* __restrict __s, size_t __n) __THROW;
^
/ usr / include / stdlib.h:873 : 1 : 错误：未知的类型名‘size_t’
extern size_t wcstombs(char* __restrict __s,
    ^
    / usr / include / stdlib.h:874 : 38 : 错误：未知的类型名‘size_t’
    const wchar_t* __restrict __pwcs, size_t __n)
    ^
    In file included from Studest.c:3 : 0 :
    / usr / include / unistd.h : 360 : 45 : 错误：未知的类型名‘size_t’
    extern ssize_t read(int __fd, void* __buf, size_t __nbytes) __wur;
^
/ usr / include / unistd.h:366 : 52 : 错误：未知的类型名‘size_t’
extern ssize_t write(int __fd, const void* __buf, size_t __n) __wur;
^
/ usr / include / unistd.h:376 : 46 : 错误：未知的类型名‘size_t’
extern ssize_t pread(int __fd, void* __buf, size_t __nbytes,
    ^
    / usr / include / unistd.h:384 : 53 : 错误：未知的类型名‘size_t’
    extern ssize_t pwrite(int __fd, const void* __buf, size_t __n,
        ^
        / usr / include / unistd.h:511 : 35 : 错误：未知的类型名‘size_t’
        extern char* getcwd(char* __buf, size_t __size) __THROW __wur;
^
In file included from Studest.c:3 : 0 :
    / usr / include / unistd.h : 623 : 1 : 错误：未知的类型名‘size_t’
    extern size_t confstr(int __name, char* __buf, size_t __len) __THROW;
^
/ usr / include / unistd.h:623 : 49 : 错误：未知的类型名‘size_t’
extern size_t confstr(int __name, char* __buf, size_t __len) __THROW;
^
/ usr / include / unistd.h:796 : 46 : 错误：未知的类型名‘size_t’
extern int ttyname_r(int __fd, char* __buf, size_t __buflen)
^
/ usr / include / unistd.h : 832 : 29 : 错误：未知的类型名‘size_t’
char* __restrict __buf, size_t __len)
^
/ usr / include / unistd.h:843 : 31 : 错误：未知的类型名‘size_t’
char* __restrict __buf, size_t __len)
^
/ usr / include / unistd.h:879 : 38 : 错误：未知的类型名‘size_t’
extern int getlogin_r(char* __name, size_t __name_len) __nonnull((1));
^
In file included from Studest.c:3 : 0 :
    / usr / include / unistd.h : 901 : 39 : 错误：未知的类型名‘size_t’
    extern int gethostname(char* __name, size_t __len) __THROW __nonnull((1));
^
/ usr / include / unistd.h:908 : 45 : 错误：未知的类型名‘size_t’
extern int sethostname(const char* __name, size_t __len)
^
/ usr / include / unistd.h : 919 : 41 : 错误：未知的类型名‘size_t’
extern int getdomainname(char* __name, size_t __len)
^
/ usr / include / unistd.h : 921 : 47 : 错误：未知的类型名‘size_t’
extern int setdomainname(const char* __name, size_t __len)
^
/ usr / include / unistd.h : 939 : 57 : 错误：未知的类型名‘size_t’
extern int profil(unsigned short int* __sample_buffer, size_t __size,
    ^
    / usr / include / unistd.h:940 : 6 : 错误：未知的类型名‘size_t’
    size_t __offset, unsigned int __scale)
    ^
    Studest.c: 在函数‘input’中:
Studest.c : 19 : 3 : 警告：隐式声明与内建函数‘printf’不兼容[默认启用]
printf("name:");
^
Studest.c:20 : 3 : 警告：隐式声明与内建函数‘scanf’不兼容[默认启用]
scanf("%s", s.name);
^
Studest.c: 在函数‘output’中:
Studest.c : 27 : 27 : 错误：‘O_RDNOLY’未声明(在此函数内第一次使用)
int fd = open("stu.dat", O_RDNOLY);
^
Studest.c:27 : 27 : 附注：每个未声明的标识符在其出现的函数内只报告一次
Studest.c : 32 : 2 : 警告：隐式声明与内建函数‘printf’不兼容[默认启用]
printf("r=%d\n", r);
^
Studest.c:34 : 36 : 错误：expected identifier before ‘if’
printf("id =%d ,name =%s \n", buf.if, buf.name);
^
Studest.c: 在函数‘main’中:
Studest.c : 41 : 2 : 警告：隐式声明与内建函数‘printf’不兼容[默认启用]
printf("要输入的几个学生信息？");
^
Studest.c:42 : 2 : 警告：隐式声明与内建函数‘scanf’不兼容[默认启用]
scanf("%d", &n);
^
Studest.c: 在文件作用域：
Studest.c : 51 : 33 : 错误：expected identifier or ‘(’ before ‘}’ token
 }                               }                                        }
 ^
     Studest.c:51 : 74 : 错误：expected identifier or ‘(’ before ‘}’ token
 }                               }                                        }
 ^
     [root@luckily day08]# vim Studest.c
     [root@luckily day08]# gcc Studest.c
     Studest.c: 在函数‘output’中:
 Studest.c : 34 : 36 : 错误：expected identifier before ‘if’
     printf("id =%d ,name =%s \n", buf.if, buf.name);
 ^
     Studest.c: 在文件作用域：
     Studest.c : 51 : 33 : 错误：expected identifier or ‘(’ before ‘}’ token
 }                               }                                        }
 ^
     Studest.c:51 : 74 : 错误：expected identifier or ‘(’ before ‘}’ token
 }                               }                                        }
 ^
     [root@luckily day08]# vim Studest.c
     [root@luckily day08]# vim Studest.c
     [root@luckily day08]# vim Studest.c
     [root@luckily day08]# gcc Studest.c
     Studest.c:51 : 33 : 错误：expected identifier or ‘(’ before ‘}’ token
 }                               }                                        }
 ^
     Studest.c:51 : 74 : 错误：expected identifier or ‘(’ before ‘}’ token
 }                               }                                        }
 ^
     [root@luckily day08]# vim Studest.c
     [root@luckily day08]# gcc Studest.c
     Studest.c:51 : 33 : 错误：expected identifier or ‘(’ before ‘}’ token
 }                               }                                        }
 ^
     Studest.c:51 : 74 : 错误：expected identifier or ‘(’ before ‘}’ token
 }                               }                                        }
 ^
     [root@luckily day08]# vim Studest.c
     [root@luckily day08]# gcc Studest.c
     [root@luckily day08]# . / a.out
     要输入的几个学生信息？2
     name : 张三
     name : 李斯
     name : 赵刘
     要显示几号学生信息（ - 1 exit）1
     r = 0
     id = 1, name = 张三
     要显示几号学生信息（ - 1 exit）2
     r = 36
     id = 2, name = 李斯
     要显示几号学生信息（ - 1 exit）3
     r = 72
     id = 3, name = 赵刘
     要显示几号学生信息（ - 1 exit） - 1
     [root@luckily day08]# 
