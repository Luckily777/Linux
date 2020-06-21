//信息队列的创建，删除，发送

//.creat
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/msg.h>

int main(void) {
	int id = msgget(1234, IPC_CREAT | 0644);
	if (id == -1) {
		perror("msgget"), exit(1);
	}
	printf("creat ok\n");
}

//.msgsnd
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/msg.h>

struct msgbuf {
	long channel;
	char buf[100];
};

int main(void) {
	int id = msgget(1234, 0);
	if (id == -1) {
		perror("msgget"), exit(1);
	}

	struct msgbuf mb;

	memset(&mb, 0x00, sizeof(mb));
	printf("channel:");
	scanf("%d%*c", &mb.channel);
	printf("msg:");
	fgets(mb.buf, 100, stdin);

	if (msgsnd(id, &mb, strlen(mb.buf), IPC_NOWAIT) == -1) {
		perror("msgsnd"), exit(1);
	}
}



//.msgrcv
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/msg.h>

struct msgbuf {
	long channel;
	char buf[100];
};

int main(void) {
	int id = msgget(1234, 0);
	if (id == -1) {
		perror("msgget"), exit(1);
	}

	struct msgbuf mb;

	memset(&mb, 0x00, sizeof(mb));
	long type;
	printf("channel:");
	scanf("%d%*c", &type);

	msgrcv(id, &mb, 100, type, IPC_NOEAIT);
	printf("[%s]\n", mb.buf);
	//if(msgsnd(id,&mb,strlen(mb.buf),0)== -1){
	//	perror("msgsnd"),exit(1);
	//}
}


//rmipc

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/msg.h>

int main(void) {
	int id = msgget(1234, 0);
	if (id == -1) {
		perror("msgget"), exit(1);
	}
	msgctl(id, IPC_RMID, 0);
}
