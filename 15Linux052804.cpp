//ÐÅºÅ
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

void handler(int s) {
	printf("ÄãÅª²»ËÀÎª%s\n", s);
}

typedef void (*handler_t)(int s);

int main(void) {
	handler_t old = NULL;
	old = signal(SIGINT, handler);

	while (1) {
		if (getchar() == '\n') {
			break;
		}
	}

	signal(SIGINT, old);

	for (;;) {
		printf(".");
		fflush(stdout);
		sleep(1);
	}
}
