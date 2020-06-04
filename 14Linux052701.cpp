//文件上锁解锁

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main(void) {
	int fd = open("test.txt", O_RDWR | O_TRUNC);

	//上锁
	struct flock lock;
	memset(&lock, 0x00, sizeof(lock));
	lock.l_type = F_WRLCK;
	lock.l_whence = SEEK_SET;
	lock.l_start = 0;
	lock.l_len = 0;

	fcntl(fd, F_SETLKW, &lock);

	printf("input return to unlock\n");
	while (getchar() != '\n')
	{
		;
	}

	lock.l_type = F_UNLCK;//解锁
	fcntl(fd, F_SETLKW, &lock) ;
	printf("unlock");
	close(fd);
}



1 #include <dirent.h>
2 #include <unistd.h>
3 #include <stdio.h>
4
5 int main(void)
6 {
    7     struct dirent* pdirent = NULL;
    8     DIR * pdir = opendir(".");
    9     while ((pdirent = readdir(pdir)) != NULL) {
        10         if (pdirent->d_name[0] == '.') {
            11             continue;
            12
        }
        13         printf("%s\t", pdirent->d_name);
        14
    }
    15     printf("\n");
    16     closedir(pdir);
    17
        18
        19 }
