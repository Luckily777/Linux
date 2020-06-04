
//基础操作
[root@luckily ~]# cd study
[root@luckily study]# cd day09
[root@luckily day09]# ls
01.c  02.c  03.c  04.c  05.c  06.c  07.c  a.out  test.txt  ttt  ttt.c
[root@luckily day09]# cd ..
[root@luckily study]# cd day10
bash : cd: day10: 没有那个文件或目录
[root@luckily study]# ls
day01  day02  day03  day04  day05  day06  day07  day08  day09
[root@luckily study]# mkdir day10
[root@luckily study]# ls
day01  day02  day03  day04  day05  day06  day07  day08  day09  day10
[root@luckily study]# cd day10
[root@luckily day10]# ls
[root@luckily day10]# vim 01_lock.c
[root@luckily day10]# gcc 01_lock.c
01_lock.c: 在函数‘main’中:
01_lock.c : 12 : 6 : 错误：‘struct flock’没有名为‘l_yupe’的成员
lock.l_yupe = F_WRLCK;
^
01_lock.c:17 : 11 : 错误：‘fc’未声明(在此函数内第一次使用)
if (fcntl(fc, F_SETLKW, &lock) == -1)
^
01_lock.c : 17 : 11 : 附注：每个未声明的标识符在其出现的函数内只报告一次
01_lock.c : 20 : 24 : 错误：expected ‘)’ before ‘; ’ token
printf(("lock ok\n");
^
01_lock.c:23 : 1 : 错误：expected ‘; ’ before ‘}’ token
 }
 ^
     [root@luckily day10]# :wq
     bash : : wq : 未找到命令...
     [root@luckily day10]# vim 01_lock.c
     [root@luckily day10]# gcc 01_lock.c
     01_lock.c: 在函数‘main’中:
 01_lock.c : 20 : 24 : 错误：expected ‘)’ before ‘; ’ token
    printf(("lock ok\n");
 ^
     01_lock.c:23 : 1 : 错误：expected ‘; ’ before ‘}’ token
 }
 ^
     [root@luckily day10]# vim 01_lock.c
     [root@luckily day10]# gcc 01_lock.c
     01_lock.c: 在函数‘main’中:
 01_lock.c : 21 : 24 : 错误：expected ‘)’ before ‘; ’ token
     printf(("lock ok\n");
 ^
     01_lock.c:22 : 2 : 错误：expected ‘; ’ before ‘}’ token
  }
  ^
      [root@luckily day10]# vim 01_lock.c
      [root@luckily day10]# gcc 01_lock.c
      [root@luckily day10]# . / a.out
      fcntl : Bad file descriptor
      [root@luckily day10]# touch test.txt
      [root@luckily day10]# . / a.out
      lock ok
      [root@luckily day10]# 


      [root@luckily ~]# cd study
      [root@luckily study]# cd day10
      [root@luckily day10]# ls
      01_lock.c  a.out  test.txt
      [root@luckily day10]# vim 01_lock.c
      [root@luckily day10]# gcc 01_lock.c
      01_lock.c: 在函数‘main’中:
  01_lock.c : 29 : 2 : 错误：程序中有游离的‘\357’
      if (fcntl(fd, F_SETLKW， & lock) == -1) {
          ^
              01_lock.c:29 : 2 : 错误：程序中有游离的‘\274’
              01_lock.c:29 : 2 : 错误：程序中有游离的‘\214’
              01_lock.c:29 : 25 : 错误：双目运算符 & 操作数(‘int’和‘struct flock’)无效
              if (fcntl(fd, F_SETLKW， & lock) == -1) {
                  ^
                      [root@luckily day10]# vim 01_lock.c
                      [root@luckily day10]# gcc 01_lock.c
                      01_lock.c: 在函数‘main’中:
                  01_lock.c : 31 : 2 : 错误：程序中有游离的‘\357’
                      if (fcntl(fd, F_SETLKW， & lock) == -1) {
                          ^
                              01_lock.c:31 : 2 : 错误：程序中有游离的‘\274’
                              01_lock.c:31 : 2 : 错误：程序中有游离的‘\214’
                              01_lock.c:31 : 25 : 错误：双目运算符 & 操作数(‘int’和‘struct flock’)无效
                              if (fcntl(fd, F_SETLKW， & lock) == -1) {
                                  ^
                                      [root@luckily day10]# vim 01_lock.c
                                      [root@luckily day10]# gcc 01_lock.c
                                      [root@luckily day10]# . / a.out
                                      lock ok
                                      input return to unlock
                                      assdfgf
                                      unlock ok
                                      unlock[root@luckily day10]# 
                                      [root@luckily day10]# . / a.out
                                      lock ok
                                      input return to unlock
                                      asd
                                      unlock ok
                                      unlock[root@luckily day10]# 



[root@luckily day10]# cd ..
[root@luckily study]# vim day10

[root@luckily study]# cd day10
[root@luckily day10]# ls
01_lock.c  a.out  test.txt
[root@luckily day10]# vim dir.c
[root@luckily day10]# gcc dir.c
dir.c: 在函数‘main’中:
                                  dir.c : 10 : 21 : 错误：提领指向不完全类型的指针
                                      printf("%s\n", pdir->d_name);
                                  ^
                                      [root@luckily day10]# vim dir.c
                                      [root@luckily day10]# gcc dir.c
                                      dir.c: 在函数‘main’中:
                                  dir.c : 10 : 21 : 错误：提领指向不完全类型的指针
                                      printf("%s\n", pdir->d_name);
                                  ^
                                      [root@luckily day10]# vim dir.c
                                      [root@luckily day10]# gcc dir.c
                                      dir.c: 在函数‘main’中:
                                  dir.c : 10 : 21 : 错误：提领指向不完全类型的指针
                                      printf("%s\n", pdir->d_name);
                                  ^
                                      [root@luckily day10]# vim dir.c
                                      [root@luckily day10]# gcc dir.c
                                      [root@luckily day10]# . / a.out
                                      .
                                      ..
                                      test.txt
                                      01_lock.c
                                      dir.c
                                      a.out
                                      [root@luckily day10]# cp a.out ..
                                      [root@luckily day10]# cd ..
                                      [root@luckily study]# ls
                                      a.out  day01  day02  day03  day04  day05  day06  day07  day08  day09  day10
                                      [root@luckily study]# . / a.out
                                      .
                                      ..
                                      day01
                                      day02
                                      day03
                                      day04
                                      day05
                                      day06
                                      day07
                                      day08
                                      day09
                                      day10
                                      a.out
                                      [root@luckily study]# rm - f a.out
                                      [root@luckily study]# ls
                                      day01  day02  day03  day04  day05  day06  day07  day08  day09  day10
                                      [root@luckily study]# cd day10
                                      [root@luckily day10]# ls
                                      01_lock.c  a.out  dir.c  test.txt
                                      [root@luckily day10]# vim dir.c
                                      [root@luckily day10]# gcc dir.c
                                      [root@luckily day10]# . / a.out
                                      test.txt	01_lock.c	dir.c	a.out
                                      [root@luckily day10]# 
