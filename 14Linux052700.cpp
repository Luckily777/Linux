
//��������
[root@luckily ~]# cd study
[root@luckily study]# cd day09
[root@luckily day09]# ls
01.c  02.c  03.c  04.c  05.c  06.c  07.c  a.out  test.txt  ttt  ttt.c
[root@luckily day09]# cd ..
[root@luckily study]# cd day10
bash : cd: day10: û���Ǹ��ļ���Ŀ¼
[root@luckily study]# ls
day01  day02  day03  day04  day05  day06  day07  day08  day09
[root@luckily study]# mkdir day10
[root@luckily study]# ls
day01  day02  day03  day04  day05  day06  day07  day08  day09  day10
[root@luckily study]# cd day10
[root@luckily day10]# ls
[root@luckily day10]# vim 01_lock.c
[root@luckily day10]# gcc 01_lock.c
01_lock.c: �ں�����main����:
01_lock.c : 12 : 6 : ���󣺡�struct flock��û����Ϊ��l_yupe���ĳ�Ա
lock.l_yupe = F_WRLCK;
^
01_lock.c:17 : 11 : ���󣺡�fc��δ����(�ڴ˺����ڵ�һ��ʹ��)
if (fcntl(fc, F_SETLKW, &lock) == -1)
^
01_lock.c : 17 : 11 : ��ע��ÿ��δ�����ı�ʶ��������ֵĺ�����ֻ����һ��
01_lock.c : 20 : 24 : ����expected ��)�� before ��; �� token
printf(("lock ok\n");
^
01_lock.c:23 : 1 : ����expected ��; �� before ��}�� token
 }
 ^
     [root@luckily day10]# :wq
     bash : : wq : δ�ҵ�����...
     [root@luckily day10]# vim 01_lock.c
     [root@luckily day10]# gcc 01_lock.c
     01_lock.c: �ں�����main����:
 01_lock.c : 20 : 24 : ����expected ��)�� before ��; �� token
    printf(("lock ok\n");
 ^
     01_lock.c:23 : 1 : ����expected ��; �� before ��}�� token
 }
 ^
     [root@luckily day10]# vim 01_lock.c
     [root@luckily day10]# gcc 01_lock.c
     01_lock.c: �ں�����main����:
 01_lock.c : 21 : 24 : ����expected ��)�� before ��; �� token
     printf(("lock ok\n");
 ^
     01_lock.c:22 : 2 : ����expected ��; �� before ��}�� token
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
      01_lock.c: �ں�����main����:
  01_lock.c : 29 : 2 : ���󣺳�����������ġ�\357��
      if (fcntl(fd, F_SETLKW�� & lock) == -1) {
          ^
              01_lock.c:29 : 2 : ���󣺳�����������ġ�\274��
              01_lock.c:29 : 2 : ���󣺳�����������ġ�\214��
              01_lock.c:29 : 25 : ����˫Ŀ����� & ������(��int���͡�struct flock��)��Ч
              if (fcntl(fd, F_SETLKW�� & lock) == -1) {
                  ^
                      [root@luckily day10]# vim 01_lock.c
                      [root@luckily day10]# gcc 01_lock.c
                      01_lock.c: �ں�����main����:
                  01_lock.c : 31 : 2 : ���󣺳�����������ġ�\357��
                      if (fcntl(fd, F_SETLKW�� & lock) == -1) {
                          ^
                              01_lock.c:31 : 2 : ���󣺳�����������ġ�\274��
                              01_lock.c:31 : 2 : ���󣺳�����������ġ�\214��
                              01_lock.c:31 : 25 : ����˫Ŀ����� & ������(��int���͡�struct flock��)��Ч
                              if (fcntl(fd, F_SETLKW�� & lock) == -1) {
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
dir.c: �ں�����main����:
                                  dir.c : 10 : 21 : ��������ָ����ȫ���͵�ָ��
                                      printf("%s\n", pdir->d_name);
                                  ^
                                      [root@luckily day10]# vim dir.c
                                      [root@luckily day10]# gcc dir.c
                                      dir.c: �ں�����main����:
                                  dir.c : 10 : 21 : ��������ָ����ȫ���͵�ָ��
                                      printf("%s\n", pdir->d_name);
                                  ^
                                      [root@luckily day10]# vim dir.c
                                      [root@luckily day10]# gcc dir.c
                                      dir.c: �ں�����main����:
                                  dir.c : 10 : 21 : ��������ָ����ȫ���͵�ָ��
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
