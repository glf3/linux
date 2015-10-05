#include "apue.h"

int main()
{
	pid_t pid;
	if((pid = fork()) < 0)
		err_sys("fork error");
	else if(pid == 0)
	{
		sleep(4);
		printf("The child process PID is %d.\n", getpid());
		printf("The Group ID of child is %d.\n", getpgrp());
		printf("The Session ID of child is %d.\n", getsid(0));
		sleep(10);
		setsid();
		printf("\nChanged:\n");
		printf("The child process PID is %d.\n", getpid());
		printf("The Group ID of child id %d.\n", getpgrp());
		printf("The Session ID of child is %d.\n", getsid(0));
		exit(0);
	}
	printf("The parent PID is %d.\n", getpid());
	printf("The Group ID of parent is %d.\n", getpgrp());
	printf("The Session ID of parent is %d.\n", getsid(0));
	exit(0);
}
