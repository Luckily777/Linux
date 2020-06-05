stat结构体所设计的ls
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
		char tmp[256];
		readlink(argv[1], tmp, 256);
		printf(" -->%s", tmp);
	}
	printf("\n");
}
