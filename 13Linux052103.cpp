1 #include <stdio.h>
2 #include <stdlib.h>
3 #include <unistd.h>
4 #include <fcntl.h>
5 #include <string.h>
6
7 int main(void) {
    8         int fd1 = open("test.txt", O_RDONLY);
    9         int fd2 = open("test.txt", O_RDWR);
    10
        11         char buf1[10 + 1] = {};
    12         char buf2[10 + 1] = {};
    13
        14         //验证文件表是两份
        15         read(fd1, buf1, 10);
    16         read(fd2, buf2, 10);
    17         printf("buf2=[%s]\n", buf1);
    18         printf("buf2=[%s]\n", buf2);
    19
        20         //证明inode只有一份
        21         memset(buf1, 0x00, sizeof(buf1));
    22         write(fd3, "AAAAA", 5);
    23         read(fd1, buf1, 6);
    24         printf("buf1=[%s]\n", buf1);
    25         close(fd1);
    26         close(fd2);
    27
}
~