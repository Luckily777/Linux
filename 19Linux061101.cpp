//´úÂë

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(void) {
	int fds[2];
	pipe(fds);
	if (fork() == 0) {
		close(fds[0]);
		sleep(3);
		write(fds[1], "aaa", 3);
		close(fds[1]);
	}
	else {
		close(fds[1]);
		char buf[10];
		read(fds[0], buf, 10);
		printf("buf=[%s]\n", buf);
		close(fds[0]);
	}
}


//2.
//ÊµÏÖls- l | wc -l
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(void) {
	int fds[2];

	pipe(fds);

	pid_t pid = fork();

	switch (pid) {
	case 0:
		close(fds[0]);
		dup2(fds[1], 1);
		execlp("ls", "ls", "-l", NULL);
		exit(0);
	case -1:
		break;
	default:
		close(fds[1]);
		dup2(fds[0], 0);
		execlp("wc", "wc", "-l", NULL);
		exit(0);
	}
}
