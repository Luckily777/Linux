//共享内存 --映射

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/mman.h>
#include <fcntl.h>

//共享内存
struct stu {
	int id;
	char name[32];
};

int main(void) {
	int fd = open("tmp.txt", O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (fd == -1) perror("open"), exit(1);

	struct stu* p = (struct stu*)mmap(NULL, sizeof(struct stu), PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
	ftruncate(fd, sizeof(struct stu));
	p->id = 1;
	strcpy(p->name, "zhangsan");
	munmap(p, sizeof(struct stu));

	close(fd);
}


struct stu {
	int id;
	char name[32];
};

int main(void) {
	int fd = open("tmp.txt", O_RDWR);
	if (fd == -1) perror("open"), exit(1);

	struct stu* p = (struct stu*)mmap(NULL, sizeof(struct stu), PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);

	printf("p->id=%d,p->name=%s\n", p->id, p->name);

	munmap(p, sizeof(struct stu));

	close(fd);
}
