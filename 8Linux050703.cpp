�����̺��ӽ���

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


�����

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {
         printf("before fork\n");

         pid_t pid = fork();

         if (pid == 0) {
                 printf("child\n");

    }
         else {
                 printf("parent\n");

    }
         getchar();

}
