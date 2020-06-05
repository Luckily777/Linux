root@luckily ~]# cd study
[root@luckily study]# cd day10
[root@luckily day10]# ls
01_lock.c  a.out  dir.c  test.txt
[root@luckily day10]# vim dir.c
[root@luckily day10]# gcc dir.c
dir.c:9 : 2 : 错误：未知的类型名‘node_t’
node_t * next;
^
dir.c: 在函数‘create_node’中:
dir.c : 16 : 21 : 警告：隐式声明与内建函数‘strlen’不兼容[默认启用]
pnode->name = malloc(strlen(dname) + 1);
^
dir.c:17 : 2 : 警告：隐式声明与内建函数‘memset’不兼容[默认启用]
memset(pnode->name, 0x00, strlen(dname) + 1);
^
dir.c:18 : 2 : 警告：隐式声明与内建函数‘strcpy’不兼容[默认启用]
strcpy(pnode->name, dname);
^
dir.c: 在函数‘insert_list’中:
dir.c : 32 : 18 : 警告：从不兼容的指针类型赋值[默认启用]
new_node->next = *head;
^
dir.c:38 : 16 : 警告：从不兼容的指针类型初始化[默认启用]
node_t * next = cur->next;
^
dir.c:44 : 8 : 警告：从不兼容的指针类型赋值[默认启用]
next = cur->next;
^
dir.c:47 : 17 : 警告：从不兼容的指针类型赋值[默认启用]
new_node->next = next;
^
dir.c:48 : 12 : 警告：从不兼容的指针类型赋值[默认启用]
cur->next = new_node;
^
dir.c: 在函数‘main’中:
dir.c : 59 : 3 : 警告：传递‘insert_list’的第 1 个参数时在不兼容的指针类型间转换[默认启用]
insert_list(&head, pdirent->d_name);
^
dir.c:24 : 6 : 附注：需要类型‘struct node_t * *’，但实参的类型为‘struct node_t * **’
void insert_list(node_t * *head, char* dname) {
	^
		dir.c:62 : 14 : 警告：从不兼容的指针类型初始化[默认启用]
		node_t * cur = head;
	^
		dir.c:65 : 6 : 警告：从不兼容的指针类型赋值[默认启用]
		cur = cur->next;
	^
		dir.c: 在函数‘insert_list’中:
	dir.c : 71 : 1 : 错误：expected declaration or statement at end of input
}
^
[root@luckily day10]# vim dir.c
[root@luckily day10]# gcc dir.c
dir.c: 在函数‘main’中:
dir.c : 60 : 3 : 警告：传递‘insert_list’的第 1 个参数时在不兼容的指针类型间转换[默认启用]
insert_list(&head, pdirent->d_name);
^
dir.c:25 : 6 : 附注：需要类型‘struct node_t * *’，但实参的类型为‘struct node_t * **’
void insert_list(node_t * *head, char* dname) {
	^
		dir.c:63 : 14 : 警告：从不兼容的指针类型初始化[默认启用]
		node_t * cur = head;
	^
		dir.c: 在函数‘insert_list’中:
	dir.c : 72 : 1 : 错误：expected declaration or statement at end of input
}
^
[root@luckily day10]# vim dir.c
[root@luckily day10]# gcc dir.c
[root@luckily day10]# . / a.out
01_lock.c  a.out  dir.c  test.txt
[root@luckily day10]# ls
01_lock.c  a.out  dir.c  test.txt
[root@luckily day10]# vim dir.c
[root@luckily day10]# gcc dir.c
[root@luckily day10]# . / a.out
01_lock.c  a.out  dir.c  test.txt
[root@luckily day10]# mkdir aaa
[root@luckily day10]# mkdir  ccc fff
[root@luckily day10]# ls
01_lock.c  aaa  a.out  ccc  dir.c  fff  test.txt
[root@luckily day10]# mkdir AAA FFF
[root@luckily day10]# ls
01_lock.c  aaa  AAA  a.out  ccc  dir.c  fff  FFF  test.txt
[root@luckily day10]# gcc dir.c
[root@luckily day10]# . / a.out
01_lock.c  a.out  AAA  aaa  ccc  dir.c  FFF  fff  test.txt
[root@luckily day10]# vim 03_stat.c
[root@luckily day10]# gcc 03_stat.c
[root@luckily day10]# . / a.out
usge : . / a.out file
[root@luckily day10]# . / a.out 01_lock.c
253
3
[root@luckily day10]# vim 03_stat.c
[root@luckily day10]# gcc 03_stat.c
03_stat.c: 在函数‘file_type’中:
03_stat.c : 10 : 8 : 错误：‘S_IFFLNK’未声明(在此函数内第一次使用)
   case S_IFFLNK:buf[0] = 'l'; break;
^
03_stat.c:10 : 8 : 附注：每个未声明的标识符在其出现的函数内只报告一次
[root@luckily day10]# vim 03_stat.c
[root@luckily day10]# gcc 03_stat.c
[root@luckily day10]# . / a.out
usge : . / a.out file
[root@luckily day10]# . / a.out 03_stat.c
- rw - r--r--
[root@luckily day10]# ls - l 03_stat.c
- rw - r--r--. 1 root root 946 6月   5 13:44 03_stat.c
[root@luckily day10]# vim 03_stat.c
[root@luckily day10]# gcc 03
gcc: 错误：03：没有那个文件或目录
gcc : 致命错误：没有输入文件
编译中断。
[root@luckily day10]# gcc 03_stat.c
[root@luckily day10]# . / a.out / dev / sda0
stat : No such file or directory
[root@luckily day10]# ls ttt
ls : 无法访问ttt: 没有那个文件或目录
[root@luckily day10]# vim 03_stat.c
[root@luckily day10]# gcc 03_stat.c
[root@luckily day10]# . / a.out 01_lock.c
- rw - r--r--.
[root@luckily day10]# vim 03_stat.c
[root@luckily day10]# gcc 03_stat.c
03_stat.c: 在函数‘main’中:
03_stat.c : 58 : 2 : 错误：expected ‘; ’ before ‘printf’
printf("\n");
^
[root@luckily day10]# vim 03_stat.c
[root@luckily day10]# gcc 03_stat.c
[root@luckily day10]# . / a.out 03_stat.c
- rw - r--r--.  1 root root 1367 2020 - 06 - 05
[root@luckily day10]# ls - l 03_stat.c
- rw - r--r--. 1 root root 1367 6月   5 14:09 03_stat.c
[root@luckily day10]# vim 03_stat.c
[root@luckily day10]# gcc 03_stat.c
[root@luckily day10]# . / a.out 03_stat.c || ls - l 03_stat.c
- rw - r--r--.  1 root root 1402 2020年06月05日
- rw - r--r--. 1 root root 1402 6月   5 14:13 03_stat.c
[root@luckily day10]# vim 03_stat.c
[root@luckily day10]# gcc 03_stat.c
[root@luckily day10]# . / a.out
usge : . / a.out file
[root@luckily day10]# . / a.out 03_stat.c
- rw - r--r--.  1 root root 1423 2020年06月05日 03_stat.c
[root@luckily day10]# ls - l 03_stat.c
- rw - r--r--. 1 root root 1423 6月   5 14:15 03_stat.c
[root@luckily day10]# ln - s 03_stat.c  Hehe
[root@luckily day10]# ls - l Hehe
lrwxrwxrwx. 1 root root 9 6月   5 14:25 Hehe -> 03_stat.c
[root@luckily day10]# vim 03_stat.c
[root@luckily day10]# cat 03_stat.c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <string.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>

void file_type(mode_t mode) {
	char buf[11] = "?---------";
	switch (mode & S_IFMT) {
	case S_IFSOCK:buf[0] = 's'; break;
	case S_IFLNK:buf[0] = 'l'; break;
	case S_IFREG:buf[0] = '-'; break;
	case S_IFBLK:buf[0] = 'b'; break;
	case S_IFDIR:buf[0] = 'd'; break;
	case S_IFCHR:buf[0] = 'c'; break;
	case S_IFIFO:buf[0] = 'p'; break;
	}
	if (mode & S_IRUSR)buf[1] = 'r';
	if (mode & S_IWUSR)buf[2] = 'w';
	if (mode & S_IXUSR)buf[3] = 'x';

	if (mode & S_IRGRP)buf[4] = 'r';
	if (mode & S_IWGRP)buf[5] = 'w';
	if (mode & S_IXGRP)buf[6] = 'x';

	if (mode & S_IROTH)buf[7] = 'r';
	if (mode & S_IWOTH)buf[8] = 'w';
	if (mode & S_IXOTH)buf[9] = 'x';

	printf("%s.  ", buf);
}

int main(int argc, char* argv[]) {
	if (argc == 1)
		printf("usge :%s file \n", argv[0]), exit(0);

	struct stat buf;
	if (lstat(argv[1], &buf) == -1)
		perror("stat"), exit(1);
	//printf("%hhu\n",(buf.st_dev>>8)&0xFF);
	//printf("%hhu\n",buf.st_dev&0xFF);

	file_type(buf.st_mode);
	printf("%d ", buf.st_nlink);
	struct passwd* pw = getpwuid(buf.st_uid);
	printf("%s ", pw->pw_name);
	struct group* gp = getgrgid(buf.st_gid);
	printf("%s ", gp->gr_name);
	printf("%d ", buf.st_size);
	struct tm* ptm = localtime(&buf.st_mtime);
	printf("%04d年%02d月%02d日 ", ptm->tm_year + 1900, ptm->tm_mon + 1, ptm->tm_mday,
		ptm->tm_hour, ptm->tm_min);
	printf("%s ", argv[1]);

	if (S_ISLNK(buf.st_mode)) {
		readlink();
	}
	printf("\n");
}
[root@luckily day10]# readlink hehe
[root@luckily day10]# vim 03_stat.c
[root@luckily day10]# gcc 03_stat.c
[root@luckily day10]# . / a.out hehe
stat : No such file or directory
[root@luckily day10]# . / a.out Hehe
lrwxrwxrwx.  1 root root 9 2020年06月05日 Hehe-- > 03_stat.c
[root@luckily day10]# 
