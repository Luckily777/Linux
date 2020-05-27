12节Linux操作

[root@luckily ~]# bc
bc 1.06.95
Copyright 1991 - 1994, 1997, 1998, 2000, 2004, 2006 Free Software Foundation, Inc.
This is free software with ABSOLUTELY NO WARRANTY.
For details type `warranty'.
1500 - 1024
476
^ C
(interrupt) Exiting bc.
[root@luckily ~]# man 2 write
[root@luckily ~]# cd study
[root@luckily study]# ls
day01  day02  day03  day04  day05  day06  day07
[root@luckily study]# mkdir day08
[root@luckily study]# cd day08
[root@luckily day08]# ls
[root@luckily day08]# 
[root@luckily ~]# cd study
[root@luckily study]# cd day08
[root@luckily day08]# vim mycopy.c
[root@luckily day08]# gcc mycopy.c - omycopy
mycopy.c: 在函数‘main’中:
mycopy.c : 19 : 16 : 错误：‘fd_dst’未声明(在此函数内第一次使用)
close(fd_dst);
^
mycopy.c:19 : 16 : 附注：每个未声明的标识符在其出现的函数内只报告一次
mycopy.c : 48 : 1 : 错误：expected declaration or statement at end of input
 }
 ^
[root@luckily day08]# vim mycopy.c
[root@luckily day08]# gcc mycopy.c - omycopy
mycopy.c: 在函数‘main’中:
 mycopy.c : 47 : 1 : 错误：expected declaration or statement at end of input
 }
 ^
[root@luckily day08]# vim mycopy.c
[root@luckily day08]# gcc mycopy.c - omycopy
mycopy.c: 在函数‘main’中:
 mycopy.c : 47 : 1 : 错误：expected declaration or statement at end of input
 }
 ^
[root@luckily day08]# vim mycopy.c
[root@luckily day08]# gcc mycopy.c - omycopy
[root@luckily day08]# ls
mycopy  mycopy.c
[root@luckily day08]# . / mycopy mycopy.c  hehe.txt
[root@luckily day08]# vimdiff mycopy.c  hehe.txt
还有 2 个文件等待编辑
[root@luckily day08]# vimdiff mycopy.c hehe.txt
还有 2 个文件等待编辑
[root@luckily day08]# vim mycopy.c
[root@luckily day08]# man sprintf
[root@luckily day08]# vim review.c
[root@luckily day08]# gcc review.c
review.c: 在函数‘main’中:
 review.c : 6 : 20 : 警告：未知的转义序列：‘\040’[默认启用]
     snprintf(buf, 1024, "{id:%d name=\'%s'\ , sal=%.2f}", 3, "zhangsan", 10.2);
 ^
     [root@luckily day08]# vim review.c
     [root@luckily day08]# gcc review.c
     [root@luckily day08]# . / a.out
 { id:3 name = zhangsan , sal = 10.20 }
     [root@luckily day08]# vim review.c
     [root@luckily day08]# gcc review.c
     [root@luckily day08]# . / a.out
 { id:3 name = 'zhangsan' , sal = 10.20 }
     [root@luckily day08]# vim review.c
     [root@luckily day08]# gcc review.c
     [root@luckily day08]# . / a.out
     [root@luckily day08]# cat aaa
 { id:3 name = 'zhangsan' , sal = 10.20 }[root@luckily day08]# 
     [root@luckily day08]# rm - f hehe.txt
     [root@luckily day08]# ls
     aaa  a.out  mycopy  mycopy.c  review.c
     [root@luckily day08]# rm - f aaa
     [root@luckily day08]# rm - f a.out
     [root@luckily day08]# ls
     mycopy  mycopy.c  review.c
     [root@luckily day08]# vim mycopy.c
     [root@luckily day08]# . / mycopy review.c  hehe.c
     [root@luckily day08]# vim hehe.c
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
 [root@luckily day08]# echo "AAAA" > tmp.txt
     [root@luckily day08]# cat tmp.txt
     AAAA
