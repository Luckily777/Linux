makefile ���ļ�����

[root@luckily ~]# cd study /
[root@luckily study]# ls
day01  day02
[root@luckily study]# cd day02
[root@luckily day02]# ls
042801.c  042802.c  042803.c  a.out  progress
[root@luckily day02]# cd progress
[root@luckily progress]# ls
add.c  a.out  main.c    mul.c  parse.c  sub.c
add.h  main   Makefile  mul.h  parse.h  sub.h
[root@luckily progress]# vim Makefile
[root@luckily progress]# vim Makefile
[root@luckily progress]# vim Makefile
[root@luckily progress]# make
gcc - c mul.c - o / root / study / day02 / progress / obj / mul.o
gcc - c main.c - o / root / study / day02 / progress / obj / main.o
gcc - c parse.c - o / root / study / day02 / progress / obj / parse.o
gcc - c add.c - o / root / study / day02 / progress / obj / add.o
gcc - c sub.c - o / root / study / day02 / progress / obj / sub.o
gcc - o main / root / study / day02 / progress / obj / mul.o / root / study / day02 / progress / obj / main.o / root / study / day02 / progress / obj / parse.o / root / study / day02 / progress / obj / add.o / root / study / day02 / progress / obj / sub.o
[root@luckily progress]# vim Makefile
[root@luckily progress]# ls
add.c  a.out  main.c    mul.c  obj      parse.h  sub.h
add.h  main   Makefile  mul.h  parse.c  sub.c
[root@luckily progress]# cd onj
bash : cd: onj: û���Ǹ��ļ���Ŀ¼
[root@luckily progress]# cd obj
[root@luckily obj]# ls
add.o  main.o  mul.o  parse.o  sub.o
[root@luckily obj]# cd /
[root@luckily / ]# cd .
[root@luckily / ]# cd ..
[root@luckily / ]# cd ..
[root@luckily / ]# cd
[root@luckily ~]# cd study
[root@luckily study]# cd day02
[root@luckily day02]# cd progress /
[root@luckily progress]# ls
add.c  a.out  main.c    mul.c  obj      parse.h  sub.h
add.h  main   Makefile  mul.h  parse.c  sub.c
[root@luckily progress]# vim Makefile
[root@luckily progress]# vim Makefile


rebuild Ŀ��
[root@luckily progress]# vim Makefile
[root@luckily progress]# make rebuild
rm - rf / root / study / day02 / progress / obj / mul.o / root / study / day02 / progress / obj / main.o / root / study / day02 / progress / obj / parse.o / root / study / day02 / progress / obj / add.o / root / study / day02 / progress / obj / sub.o
gcc - c mul.c - o / root / study / day02 / progress / obj / mul.o
gcc - c main.c - o / root / study / day02 / progress / obj / main.o
gcc - c parse.c - o / root / study / day02 / progress / obj / parse.o
gcc - c add.c - o / root / study / day02 / progress / obj / add.o
gcc - c sub.c - o / root / study / day02 / progress / obj / sub.o
gcc - o main / root / study / day02 / progress / obj / mul.o / root / study / day02 / progress / obj / main.o / root / study / day02 / progress / obj / parse.o / root / study / day02 / progress / obj / add.o / root / study / day02 / progress / obj / sub.o




*** gcc -MM �鿴���ɵ�.o����������Щ�ļ�

oot@luckily progress]# gcc - MM add.c
add.o: add.c add.h
